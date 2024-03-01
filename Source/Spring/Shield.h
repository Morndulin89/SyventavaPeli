// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "EnergyConsumer.h"
#include "Shield.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPRING_API UShield : public UEnergyConsumer
{
	GENERATED_BODY()


public: 
	UFUNCTION(BlueprintCallable, Category = "Shield")
	void Protect();
	
	UFUNCTION(BlueprintCallable, Category = "Shield")
	void DestroyShield();

};
