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

	
	void SetCurrentBehaviorTree(UBehaviorTree* TreeToSetTo){CurrentBehaviorTree = TreeToSetTo; } 
	void SetDialogueTree(UBehaviorTree* TreeToSetTo) { DialogueTree = TreeToSetTo ;}

	UBehaviorTree* GetCurrentBehaviorTree() const {return CurrentBehaviorTree;}
	UBehaviorTree* GetNotInterestedBehaviorTree() const {return NotInterestedBehaviorTree;}
	UBehaviorTree* GetPatrollingBehaviorTree() const {return PatrollingBehaviorTree;}
	UBehaviorTree* GetSearchingForPlayerBehaviorTree() const {return CurrentBehaviorTree;}
	UBehaviorTree* GetDialogueBehaviorTree() const {return DialogueTree;}
	UBehaviorTree* GetFleeingPlayerBehaviorTree() const {return FleeingBehaviorTree;}
	UBehaviorTree* GetEngagingPlayerBehaviorTree() const {return EngagingBehaviorTree;}
	UBehaviorTree* GetTransitioningBehaviorTree() const {return TransitioningBehaviorTree;}

	
protected:

	virtual void BeginPlay() override;
	
private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UAIPerceptionComponent> MyPerceptionComponent;
	
	// This is the Current (also default) behavior tree that the AI controller is running. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UBehaviorTree> CurrentBehaviorTree;

	// Can be used as a transition between other behavior trees 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UBehaviorTree> TransitioningBehaviorTree;


	// To be used when NPC is patrolling
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UBehaviorTree> PatrollingBehaviorTree;
	
	// The Dialogue tree to be used when the player talks with this NPC ("Talking To Player" State)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UBehaviorTree> DialogueTree;

	// The behavior tree to be used when the NPC is in "Not Interested" state
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UBehaviorTree> NotInterestedBehaviorTree;

	// Behavior tree to be used when NPC is for searching for the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UBehaviorTree> SearchingForPlayerBehaviorTree;

	// Behavior tree to be used when NPC is engaging/attacking the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UBehaviorTree> EngagingBehaviorTree;

	// Behavior tree to be used when NPC is fleeing from the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	TObjectPtr<class UBehaviorTree> FleeingBehaviorTree;

};
