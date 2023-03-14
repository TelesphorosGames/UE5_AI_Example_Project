// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"

#include "Blueprint/UserWidget.h"


void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	CreateCharacterOverlay();

}

void APlayerHUD::CreateCharacterOverlay()
{
	//Create the Character Overlay when the game starts and make it visible.
	if(CharacterOverlayClass && !CharacterOverlay)
	{
		CharacterOverlay = CreateWidget(GetOwningPlayerController(), CharacterOverlayClass);
		CharacterOverlay->AddToViewport();
		CharacterOverlay->SetVisibility(ESlateVisibility::Visible);
	}
}
