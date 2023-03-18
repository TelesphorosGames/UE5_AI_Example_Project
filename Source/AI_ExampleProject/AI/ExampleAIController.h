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

	AExampleAIController();
	
	void StartDialogueTree();

	UFUNCTION(BlueprintCallable)
	void EndDialogue();
	

	void SetDialogueTree(UBehaviorTree* TreeToSetTo) { DialogueTree = TreeToSetTo ;}

	UBehaviorTree* GetCurrentBehaviorTree() const {return CurrentBehaviorTree;}
	UBehaviorTree* GetNotInterestedBehaviorTree() const {return NotInterestedBehaviorTree;}
	UBehaviorTree* GetSearchingForPlayerBehaviorTree() const {return CurrentBehaviorTree;}
	UBehaviorTree* GetDialogueBehaviorTree() const {return DialogueTree;}
	UBehaviorTree* GetFleeingPlayerBehaviorTree() const {return FleeingBehaviorTree;}
	UBehaviorTree* GetEngagingPlayerBehaviorTree() const {return EngagingBehaviorTree;}

	
protected:

	virtual void BeginPlay() override;
	
private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UAIPerceptionComponent> MyPerceptionComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UBehaviorTree> DialogueTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UBehaviorTree> CurrentBehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UBehaviorTree> NotInterestedBehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UBehaviorTree> SearchingForPlayerBehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UBehaviorTree> BehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UBehaviorTree> EngagingBehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UBehaviorTree> FleeingBehaviorTree;

};
