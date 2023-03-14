// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 *  Anything that can be interacted with in the game. Actors inheriting from this interface
 *  will create an "Interact" widget when viewed in game.
 */
class AI_EXAMPLEPROJECT_API IInteractable
{
	GENERATED_BODY()

public:
	
	virtual void InteractWith(AActor* ActorToInteractWith);
	
};
