// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "AI_ExampleProjectCharacter.generated.h"


class UInteractionComponent;
class USphereComponent;
class AAI_ExampleProjectGameMode;

// BASE PLAYER CLASS - CANNOT BE INTERACTED WITH BY DEFAULT - CAN ONLY INTERACT
UCLASS(config=Game)
class AAI_ExampleProjectCharacter : public ACharacter
{
	GENERATED_BODY()

/* UNREAL ENGINE BASE CHARACTER SETUP */
/*************************************
 *
 */
	
	public:
	AAI_ExampleProjectCharacter();


	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	
	protected:

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

	
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

private:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;
	
/*******************************************//*///////*/
/* END UNREAL ENGINE BASE CHARACTER SETUP */
	
public:
	// Holds the name of the interactable being hit by our line trace
	UPROPERTY(VisibleAnywhere)
	FString CurrentlyLookedAtInteractableName;
	
protected:
	
	// Calls the interaction component's Interact()
	void InteractButtonPressed();
	
private:

	
	/** Interact Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InteractAction;

	// Game Mode
	TObjectPtr<class AAI_ExampleProjectGameMode> ExampleProjectGameMode;

	// Player HUD
	TObjectPtr<class APlayerHUD> PlayerHUD;

	/* Set This in BP to the Interaction Component class so we can find our BP version
	 * Can avoid this with a direct Interaction Component Created in C++ */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UActorComponent> InteractionComponentClass;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInteractionComponent* InteractionComponent;

	


};

