// Fill out your copyright notice in the Description page of Project Settings.


#include "Shield.h"



void UShield::Protect()
{
	//Check if static mesh has been set
	if (GetStaticMesh())
	{
	//And if there is available energy in the Energysource
		if (ConsumeBurst())
		{
			//set Static mesh visible and enable collision in it
			this->SetVisibility(true);
			this->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Red, FString::Printf(TEXT("Shield used")));
		
			/*
			here could have been a delay set for example:
			FTimerHandle Unusedhandle;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &MyActor::TimerElapsed, TimerDelay, false)
			But it is much easier to set the timer (especially the amount of delay) 
			in the blueprint, so I did it there and hid the shield by
			calling another function
			*/

		}
	}
}




void UShield::DestroyShield()
{
	//hide the static mesh and disable collision
	this->SetVisibility(false);
	this->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
