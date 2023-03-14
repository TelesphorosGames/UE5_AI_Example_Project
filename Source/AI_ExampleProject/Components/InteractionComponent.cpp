// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionComponent.h"

#include "Components/SphereComponent.h"


UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	// Create the Interactable Range Sphere
	InteractableRangeSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Interactable Range Sphere"));
	InteractableRangeSphere->SetupAttachment(GetOwner()->GetRootComponent());
	InteractableRangeSphere->SetSphereRadius(800.f);
}

void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	
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


