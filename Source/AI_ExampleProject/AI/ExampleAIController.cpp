// Fill out your copyright notice in the Description page of Project Settings.


#include "ExampleAIController.h"

void AExampleAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

void AExampleAIController::StartDialogueTree()
{
	RunBehaviorTree(DialogueTree);
}
