// Copyright Epic Games, Inc. All Rights Reserved.

#include "IMS445GameMode.h"
#include "IMS445Character.h"
#include "UObject/ConstructorHelpers.h"

AIMS445GameMode::AIMS445GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
