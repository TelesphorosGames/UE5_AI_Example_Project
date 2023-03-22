// Fill out your copyright notice in the Description page of Project Settings.


#include "ExampleAIController.h"

#include "BrainComponent.h"
#include "Perception/AIPerceptionComponent.h"

void AExampleAIController::BeginPlay()
{
	Super::BeginPlay();
	PerceptionComponent = MyPerceptionComponent;
	
	
}

AExampleAIController::AExampleAIController()
{
	MyPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));
}

void AExampleAIController::StartDialogueTree()
{
	RunBehaviorTree(DialogueTree);
}

void AExampleAIController::EndDialogue()
{
	RunBehaviorTree(CurrentBehaviorTree);
}
