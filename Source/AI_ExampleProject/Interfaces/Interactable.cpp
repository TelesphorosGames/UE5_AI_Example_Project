// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"

/* Add default functionality here for any IInteractable functions that are not pure virtual. */

// Any actor that inherits from IInteractable should overwrite this to define interaction
// When called from the character class, you should pass in 'this' as actor to interact with
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
