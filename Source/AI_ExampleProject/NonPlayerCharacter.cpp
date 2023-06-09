// Fill out your copyright notice in the Description page of Project Settings.


#include "NonPlayerCharacter.h"

#include "AI/ExampleAIController.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetComponent.h"

// Sets default values
ANonPlayerCharacter::ANonPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractWithWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractWithWidget"));
	InteractWithWidget->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ANonPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	ExampleAIController = Cast<AExampleAIController>(GetController());

	ExampleAIController->RunBehaviorTree(ExampleAIController->GetCurrentBehaviorTree());
	
}

void ANonPlayerCharacter::InteractWith()
{
	// When interacted with, AI controller runs Dialogue tree.
	ExampleAIController->StartDialogueTree();
}

bool ANonPlayerCharacter::GetIsInteractable()
{
	return IInteractable::GetIsInteractable();
}

void ANonPlayerCharacter::SetIsInteractable(bool bSetIsInteractableTo)
{
	// If this NPC is currently being looked at, display the visibility of the InteractWith Widget, otherwise hide it
	IInteractable::SetIsInteractable(bSetIsInteractableTo);
	if(bIsInteractable)
	{
		InteractWithWidget->SetVisibility(true);
	}
	else
	{
		InteractWithWidget->SetVisibility(false);
	}
}

FString ANonPlayerCharacter::GetInteractableDisplayName()
{
	return NPC_Name;
}

// Called every frame
void ANonPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANonPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANonPlayerCharacter::SetInterestState(const EInterestState StateToSet)
{
	InterestState = StateToSet;

	switch (InterestState) { case EInterestState::EIS_NotInterested:

		ExampleAIController->SetCurrentBehaviorTree(ExampleAIController->GetNotInterestedBehaviorTree());
		break;
	case EInterestState::EIS_SearchingForPlayer:

		ExampleAIController->SetCurrentBehaviorTree(ExampleAIController->GetSearchingForPlayerBehaviorTree());
		break;
	case EInterestState::EIS_TalkingWithPlayer:

		ExampleAIController->SetCurrentBehaviorTree(ExampleAIController->GetDialogueBehaviorTree());
		
		break;
	case EInterestState::EIS_EngagingPlayer:

		ExampleAIController->SetCurrentBehaviorTree(ExampleAIController->GetEngagingPlayerBehaviorTree());
		break;
		
	case EInterestState::EIS_FleeingPlayer:

		ExampleAIController->SetCurrentBehaviorTree(ExampleAIController->GetFleeingPlayerBehaviorTree());
		break;

	case EInterestState::EIS_Transitioning:

		ExampleAIController->SetCurrentBehaviorTree(ExampleAIController->GetTransitioningBehaviorTree());
		break;
	case EInterestState::EIS_Patrolling:

		ExampleAIController->SetCurrentBehaviorTree(ExampleAIController->GetPatrollingBehaviorTree());
		break;
	
	case EInterestState::EIS_MAX:


		
		break;

		
	default: ;
	}
}

