// Copyright Epic Games, Inc. All Rights Reserved.

#include "Ch3_Team2GameMode.h"
#include "Ch3_Team2Character.h"
#include "UObject/ConstructorHelpers.h"

ACh3_Team2GameMode::ACh3_Team2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
