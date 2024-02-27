// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Shield.generated.h"

/**
 * 
 */
UCLASS()
class SPRING_API UShield : public UStaticMeshComponent
{
	GENERATED_BODY()

public: 
	UFUNCTION(BlueprintCallable, Category = "Shield")
	void Protect();
	
};
