// Fill out your copyright notice in the Description page of Project Settings.


#include "ExampleAIController.h"

#include "BrainComponent.h"

void AExampleAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

void AExampleAIController::StartDialogueTree()
{
	RunBehaviorTree(DialogueTree);
}

void AExampleAIController::EndDialogue()
{
	// BrainComponent->StopLogic("");
	RunBehaviorTree(CurrentBehaviorTree);
	
}
