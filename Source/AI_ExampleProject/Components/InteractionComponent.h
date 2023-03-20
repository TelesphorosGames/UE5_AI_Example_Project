// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI_ExampleProject/Interfaces/Interactable.h"
#include "InteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AI_EXAMPLEPROJECT_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractionComponent();

	void Interact();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString HighlightedInteractableName = "None";

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//TODO : Put on timer
	// Currently is run in the Tick function
	void ConstantInteractionCheck();

private:
	
	// Player HUD
	TObjectPtr<class APlayerHUD> PlayerHUD;

	// Range with which interaction is possible. Overlaps with interactable actors will enable interaction. Can adjust Radius in Blueprints.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess="true"))
	TObjectPtr<class USphereComponent> InteractableRangeSphere;

	// Called when Interactable Range Sphere is Overlapped with by anything that generates overlap events
	UFUNCTION()
	void InteractSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	// Called When Interactable Range Sphere is no longer overlapping said Other Actor
	UFUNCTION()
	void InteractSphereEndOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	TObjectPtr<IInteractable> CurrentlyHighlightedInteractable;
	TObjectPtr<IInteractable> PreviouslyHighlightedInteractable;

	// Keeps track of how many interactables we're overlapping with to ensure bShouldDoInteracionCheck is not toggled off early
	int32 NumberOfOverlappedInteractables = 0;

	// Only true when our character's interaction component is overlapping with an interactable object
	bool bShouldDoInteractionCheck = false;
	
	
};

