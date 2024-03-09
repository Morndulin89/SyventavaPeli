// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "AsteroidFieldSaveGame.generated.h"

enum EAsteroidType
{
	RegularAsteroid,
	BigAsteroid,
};

USTRUCT(BlueprintType)
struct FAsteroidStruct
{
	GENERATED_BODY()
	
	UPROPERTY()
	FTransform transform;

	UPROPERTY()
	int32 type; 
	UPROPERTY()
	FVector angularVelocity; 
	UPROPERTY()
	FVector velocity; 
};

USTRUCT(BlueprintType)
struct FPlayerStruct
{
	GENERATED_BODY()

	UPROPERTY()
	FTransform playerTransform; 
};


/**
 * 
 */
UCLASS()
class SPRING_API UAsteroidFieldSaveGame : public USaveGame
{
	GENERATED_BODY()

public: 
	UPROPERTY()
	TArray<FAsteroidStruct> asteroids; 
	
};
