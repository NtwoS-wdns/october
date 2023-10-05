// Copyright Epic Games, Inc. All Rights Reserved.

#include "lasttestGameMode.h"
#include "lasttestCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "CharacterHUD.h"

AlasttestGameMode::AlasttestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;

	}
	HUDClass = ACharacterHUD::StaticClass(); 
}
