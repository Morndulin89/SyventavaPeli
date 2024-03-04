// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "EnergyConsumer.h"
#include "AsteroidField.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPRING_API UWeapon : public UEnergyConsumer
{
	GENERATED_BODY()

public: 

	AAsteroidField* field; 

	UFUNCTION(BlueprintCallable, Category="Weapon")
	void Shoot(); 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	float Range = 1000.f; 
	
};
