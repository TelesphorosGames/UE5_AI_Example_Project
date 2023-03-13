// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI_ExampleProjectGameMode.h"
#include "AI_ExampleProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAI_ExampleProjectGameMode::AAI_ExampleProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
