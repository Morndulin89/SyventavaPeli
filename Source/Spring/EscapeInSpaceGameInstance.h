// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AsteroidFieldSaveGame.h"
#include "Asteroid.h"
#include "EscapeInSpaceGameInstance.generated.h"

/**
 * 
 */
#define DEFAULT_SAVE_SLOT_NAME "ASTEROIDFIELD"
#define DEFAULT_SAVE_USER_INDEX 0


UCLASS()
class SPRING_API UEscapeInSpaceGameInstance : public UGameInstance
{
	GENERATED_BODY()

public: 

	UAsteroidFieldSaveGame* SaveGameInstance; 
	
	UFUNCTION(BlueprintCallable, Category = "EscapeInSpace")
	void Save();
	UFUNCTION(BlueprintCallable, Category="EscapeInSpace")
	void Load();

	void Save(AAsteroid& asteroid);
};
