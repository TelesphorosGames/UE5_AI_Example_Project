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

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

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

	
};

