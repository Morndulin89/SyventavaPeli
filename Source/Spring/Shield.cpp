// Fill out your copyright notice in the Description page of Project Settings.


#include "Shield.h"



void UShield::Protect()
{
	//Check if static mesh has been set
	if (GetStaticMesh())
	{
		if (ConsumeBurst())
		{

			this->SetVisibility(true);
			this->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Red, FString::Printf(TEXT("Shield used")));


		}
	}
}

void UShield::DestroyShield()
{
	this->SetVisibility(false);
	this->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
