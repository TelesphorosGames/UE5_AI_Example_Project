// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ExampleAIController.generated.h"

/**
 * Example AI Controller class with Behavior and Dialogue trees
 */
UCLASS()
class AI_EXAMPLEPROJECT_API AExampleAIController : public AAIController
{
	GENERATED_BODY()
public:
	
	void StartDialogueTree();

	void SetDialogueTree(UBehaviorTree* TreeToSetTo) { DialogueTree = TreeToSetTo ;}

	
protected:

	virtual void BeginPlay() override;

	
	
private:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UBehaviorTree> DialogueTree;
	
};
