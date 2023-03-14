// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

/**
 * Example HUD class  * 
 */
UCLASS()
class AI_EXAMPLEPROJECT_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:

	
	

protected:
	//Create the Character Overlay when the game starts and make it visible.
	void CreateCharacterOverlay();

	virtual void BeginPlay() override;
	
private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="My Stuff | Widgets", meta=(AllowPrivateAccess=true))
	TObjectPtr<UUserWidget> CharacterOverlay;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="My Stuff | Widgets", meta=(AllowPrivateAccess=true))
	TSubclassOf<UUserWidget> CharacterOverlayClass;
	
};
