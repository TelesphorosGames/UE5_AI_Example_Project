// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/Interactable.h"
#include "NonPlayerCharacter.generated.h"

// Determines state AI will be in
UENUM(BlueprintType)
enum class EInterestState : uint8
{
	EIS_NotInterested UMETA(DisplayName="Not Interested"),
	EIS_Transitioning UMETA(DisplayName="In Transition"),
	EIS_Patrolling UMETA(DisplayName="Patrolling"),
	EIS_SearchingForPlayer UMETA(DisplayName="Searching For Player"),
	EIS_TalkingWithPlayer UMETA(DisplayName="Talking With Player"),
	EIS_EngagingPlayer UMETA(DisplayName="Engaging To Attack Player"),
	EIS_FleeingPlayer UMETA(DisplayName="Fleeing From Player"),
	
	EIS_MAX UMETA(DisplayName="DefaultMAX")
	
};

UCLASS()
class AI_EXAMPLEPROJECT_API ANonPlayerCharacter : public ACharacter, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANonPlayerCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// Can be called to set Interest State to dictate the NPC's next behavior tree.
	UFUNCTION(BlueprintCallable)
	void SetInterestState(const EInterestState StateToSet);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	EInterestState GetInterestState() const {return  InterestState;}

	// Point where AI will patrol to - to be set via widget in editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MakeEditWidget = "true"))
	FVector PatrolPoint1;
	// Point where AI will patrol to - to be set via widget in editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MakeEditWidget = "true"))
	FVector PatrolPoint2;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void InteractWith() override;

	virtual bool GetIsInteractable() override;
	virtual void SetIsInteractable(bool bSetIsInteractableTo) override;
	
	virtual FString GetInteractableDisplayName() override;

private:

	// Interact Widget - Set in Default Blueprint to the Interact Button to ensure it is created correctly
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> InteractWidgetClass;
	// Pointer to the actual InteractWith Widget component 
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UWidgetComponent> InteractWithWidget;
	// Can be set to dictate the NPC's next behavior tree.
	UPROPERTY(VisibleAnywhere)
	EInterestState InterestState;
	// Name of NPC, can be set in editor and will display as HUD's interactable && Dialogue widget's speaker name
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess="true"))
	FString NPC_Name = "None";

	TObjectPtr<class AExampleAIController> ExampleAIController;

	// TODO : Implement simple bShouldPatrol toggle
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess="true"))
	bool bShouldPatrol = true;

};
