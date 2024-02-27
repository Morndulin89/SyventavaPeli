// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "EnergySource.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPRING_API UEnergySource : public UStaticMeshComponent
{
	GENERATED_BODY()

	float MaxEnergy; 
	float Energy; 
	void AddCharge(float charge);
	float GetCharge() const;
	float RequestCharge(float value);
	
};
