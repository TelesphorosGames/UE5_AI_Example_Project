// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionComponent.h"

#include "Components/SphereComponent.h"
#include "Kismet/KismetSystemLibrary.h"


UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	// Create the Interactable Range Sphere
	InteractableRangeSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Interactable Range Sphere"));
	
	InteractableRangeSphere->SetSphereRadius(800.f);
}

void UInteractionComponent::Interact()
{
	// 1. Do Sphere trace outwards from location of player character + control rotation (camera rotation)
	FHitResult OutHitResult;
	TArray<AActor*> ActorsToIgnore;
	UKismetSystemLibrary::SphereTraceSingle(GetWorld(), GetOwner()->GetActorLocation(), GetOwner()->GetActorLocation() + (GetOwner()->GetInstigatorController()->GetControlRotation().Vector() * 5'000), 25.f, ETraceTypeQuery::TraceTypeQuery1, false, ActorsToIgnore, EDrawDebugTrace::ForOneFrame, OutHitResult, false);

	// 2. If blocking hit, check it for Interactable interface. If it Implements the interface and is currently interactable, interact
	if(OutHitResult.bBlockingHit)
	{
		IInteractable* InteractableObject = Cast<IInteractable>(OutHitResult.GetActor());
		if(InteractableObject && InteractableObject->GetIsInteractable())
		{
			UE_LOG(LogTemp,Warning,TEXT("Success, interacting with : %s"), *InteractableObject->GetInteractableDisplayName());
			InteractableObject->InteractWith(GetOwner());
		}
		else
		{
			UE_LOG(LogTemp,Warning,TEXT("Failure. %s is not interactable!"), *OutHitResult.GetActor()->GetName());
		}
	}
}

void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	
	InteractableRangeSphere->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	
	// Bind Overlap Functions to Interactable Sphere
	InteractableRangeSphere->OnComponentBeginOverlap.AddDynamic(this, &UInteractionComponent::InteractSphereOverlap);
	InteractableRangeSphere->OnComponentEndOverlap.AddDynamic(this, &UInteractionComponent::InteractSphereEndOverlap);
}


void UInteractionComponent::ConstantInteractionCheck()
{
	if(bShouldDoInteractionCheck)
	{
		FHitResult InteractionCheckHitResult;
        	
		UKismetSystemLibrary::LineTraceSingle(this, GetOwner()->GetActorLocation(), GetOwner()->GetActorLocation() + GetOwner()->GetInstigatorController()->GetControlRotation().Vector() * 1'000, ETraceTypeQuery::TraceTypeQuery1, false, TArray<AActor*>(), EDrawDebugTrace::ForOneFrame, InteractionCheckHitResult, true);
		
		if(InteractionCheckHitResult.GetActor() && InteractionCheckHitResult.GetActor()->Implements<UInteractable>())
        {
			if(PreviouslyHighlightedInteractable)
			{
				PreviouslyHighlightedInteractable->SetIsInteractable(false);
			}
			
			CurrentlyHighlightedInteractable = Cast<IInteractable>(InteractionCheckHitResult.GetActor());
			CurrentlyHighlightedInteractable->SetIsInteractable(true);
			HighlightedInteractableName = CurrentlyHighlightedInteractable->GetInteractableDisplayName();
			PreviouslyHighlightedInteractable = CurrentlyHighlightedInteractable;
        }
		else if(CurrentlyHighlightedInteractable != nullptr)
		{
			CurrentlyHighlightedInteractable->SetIsInteractable(false);
			HighlightedInteractableName = "";
		}		
	}
	else if(CurrentlyHighlightedInteractable)
	{
		CurrentlyHighlightedInteractable->SetIsInteractable(false);
		HighlightedInteractableName = "";
	}
	else
	{
		HighlightedInteractableName = "";
	}
}

void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Does Line Trace to 
	ConstantInteractionCheck();
	
	

}

void UInteractionComponent::InteractSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor)
	{
		IInteractable* PossibleInteractable = Cast<IInteractable>(OtherActor);
		if(PossibleInteractable)
		{
			bShouldDoInteractionCheck=true;
			NumberOfOverlappedInteractables += 1;
		}
	}
}

void UInteractionComponent::InteractSphereEndOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(OtherActor)
	{
		IInteractable* PossibleInteractable = Cast<IInteractable>(OtherActor);
		if(PossibleInteractable)
		{
			NumberOfOverlappedInteractables -=1;
			if(NumberOfOverlappedInteractables <=0)
			{
				bShouldDoInteractionCheck = false;
			}
		}
	}
}


