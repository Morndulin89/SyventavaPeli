// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovementComponent.h"


void UCustomMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	/*Use custom tick IF spline is set (NOT nullptr) and MovementMode is set to custom AND custom movement is set to SplineMovement*/
	if (MovementSpline != nullptr &&								//spline is set
		MovementMode == EMovementMode::MOVE_Custom &&				//movement is set to custom movement
		CustomMovementMode == ECustomMovement::MOVE_SplineMovement)	//custom movement is set to SplineMovement
	{
		UE_LOG(LogTemp, Warning, TEXT("Spline movement active"));
		FVector movement = ConsumeInputVector();
		float inputScale = movement.Size();
		if(inputScale > 0.5) //if there is input (character does not move on it's own)
		{
			PassedTimeInSeconds += DeltaTime; //time spent on the movement
		}

		FVector location = MovementSpline->GetLocationAtTime(PassedTimeInSeconds, ESplineCoordinateSpace::World, true); //get current location
		GetOwner()->SetActorLocation(location);
	}

	else
	{
		PassedTimeInSeconds = 0.0f; //reset passed time when the custom tick is not called
		/*Otherwise use the normal tick function*/
		Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	}
	

}

