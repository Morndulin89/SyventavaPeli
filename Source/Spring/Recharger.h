// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "EnergySource.h"
#include "Recharger.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPRING_API URecharger : public UStaticMeshComponent
{
	GENERATED_BODY()

public: 
	UFUNCTION(BlueprintCallable, Category = "Recharger")
	float RechargeRate();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
