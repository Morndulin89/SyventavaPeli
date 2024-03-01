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

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnergySource")
	float MaxEnergy; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnergySource")
	float Energy; 

	UFUNCTION(BlueprintCallable)
	void AddCharge(float charge);

	UFUNCTION(BlueprintCallable)
	float GetCharge() const;

	UFUNCTION(BlueprintCallable)
	float RequestCharge(float value);
	
};
