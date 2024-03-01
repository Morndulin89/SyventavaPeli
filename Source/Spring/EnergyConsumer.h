// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "EnergySource.h"
#include "EnergyConsumer.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPRING_API UEnergyConsumer : public UStaticMeshComponent
{
	GENERATED_BODY()

public: 
	UEnergyConsumer();

	//the energy source
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnergyConsumer")
	UEnergySource* TargetSource;

	//how much energy is spent in a burst
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnergyConsumer")
	float BurstCunsumptionRate;

	//how much energy is consumed constantly (for example engine etc)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnergyConsumer")
	float ConstantConsumptionRatePerSecond;
	
	//use burst
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool ConsumeBurst();

	//get tick-function
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
