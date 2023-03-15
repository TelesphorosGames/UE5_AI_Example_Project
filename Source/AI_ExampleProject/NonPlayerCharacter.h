// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/Interactable.h"
#include "NonPlayerCharacter.generated.h"

UCLASS()
class AI_EXAMPLEPROJECT_API ANonPlayerCharacter : public ACharacter, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANonPlayerCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void InteractWith(AActor* ActorToInteractWith) override;

	virtual bool GetIsInteractable() override;
	virtual void SetIsInteractable(bool bSetIsInteractableTo) override;

private:

	// Interact Widget - Set in Blueprint Default to the Interact Button
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> InteractWidgetClass;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UWidgetComponent> InteractWithWidget;


};
