// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SplineComponent.h"
#include "CustomMovementComponent.generated.h"


UENUM(BlueprintType)
enum ECustomMovement
{
	MOVE_SplineMovement UMETA(DisplayName = "Move along spline")
};
/**
 * 
 */
UCLASS()
class SPRING_API UCustomMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public: 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USplineComponent* MovementSpline = nullptr;
	
	float PassedTimeInSeconds = 0.0f; 

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
