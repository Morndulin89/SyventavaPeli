// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedBurst.h"

void USpeedBurst::SpeedBurst(float speedMultiplier)
{
	if (ConsumeBurst)
	{
		if (GetOwner())
		{
			APawn* OwningPawn = Cast<APawn>(GetOwner());
			UPawnMovementComponent* movementComponent = OwningPawn->GetMovementComponent();
			
			
		}


	}

}
