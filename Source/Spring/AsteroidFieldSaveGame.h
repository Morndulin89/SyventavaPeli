// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "AsteroidFieldSaveGame.generated.h"

enum EAsteroidType
{
	RegularAsteroid,
	BigAsteroid
};

USTRUCT(BlueprintType)
struct FAsteroidStruct
{
	GENERATED_BODY()
	
	FTransform transform;

	UPROPERTY()
	int32 type; 
};


/**
 * 
 */
UCLASS()
class SPRING_API UAsteroidFieldSaveGame : public USaveGame
{
	GENERATED_BODY()

	TArray<FAsteroidStruct> astroids; 
	
};
