// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"

/* Add default functionality here for any IInteractable functions that are not pure virtual. */

// Any actor that inherits from IInteractable should overwrite this to define interaction
// Called from the character class, should pass in 'this' as actor to interct with
void IInteractable::InteractWith(AActor* ActorToInteractWith)
{
	
}

bool IInteractable::GetIsInteractable()
{
	return bIsInteractable;
}

void IInteractable::SetIsInteractable(bool bSetIsInteractableTo)
{
	bIsInteractable = bSetIsInteractableTo;
}

FString IInteractable::GetInteractableDisplayName()
{
	return "No Name Set";
}
