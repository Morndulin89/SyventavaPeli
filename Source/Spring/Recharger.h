// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "EnergySource.h"
#include "Recharger.generated.h"

/**
 * UStaticMeshComponent doesn't aucomatically include tick-component, so 
 * there has to be a constructor URecharger() and TickComponent and BeginPlay must be overridden
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPRING_API URecharger : public UStaticMeshComponent
{
	GENERATED_BODY()

public: 
	URecharger();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnergyConsumer")
	UEnergySource* TargetSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnergyConsumer")
	float RechargeRate;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;
	
};
