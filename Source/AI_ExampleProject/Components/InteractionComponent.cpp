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
	FHitResult OutHitResult;
	TArray<AActor*> ActorsToIgnore;
	UKismetSystemLibrary::SphereTraceSingle(GetWorld(), GetOwner()->GetActorLocation(), GetOwner()->GetActorLocation() + (GetOwner()->GetInstigatorController()->GetControlRotation().Vector() * 5'000), 25.f, ETraceTypeQuery::TraceTypeQuery1, false, ActorsToIgnore, EDrawDebugTrace::ForOneFrame, OutHitResult, false);
	
	if(OutHitResult.bBlockingHit)
	{
		IInteractable* InteractableObject = Cast<IInteractable>(OutHitResult.GetActor());
		if(InteractableObject && InteractableObject->GetIsInteractable())
		{
			UE_LOG(LogTemp,Warning,TEXT("Success, interacting with : %s"), *OutHitResult.GetActor()->GetName());
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


void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


}

void UInteractionComponent::InteractSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp,Warning,TEXT("I AM TIRED"));
	if(OtherActor)
	{
		IInteractable* PossibleInteractable = Cast<IInteractable>(OtherActor);
		if(PossibleInteractable)
		{
			PossibleInteractable->SetIsInteractable(true);
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
			PossibleInteractable->SetIsInteractable(false);
		}
	}
}


