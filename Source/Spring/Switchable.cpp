// Fill out your copyright notice in the Description page of Project Settings.


#include "Switchable.h"

// Sets default values
ASwitchable::ASwitchable()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASwitchable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASwitchable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASwitchable::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASwitchable::Enable()
{

}


void ASwitchable::Disable()
{

}


void ASwitchable::Toggle()
{
	TSet<ASwitchable*> handled;
	ToggleImp(handled);
}

void ASwitchable::ToggleImp(TSet< ASwitchable* > &handled)
{
	bool wasAlreadyAdded;
	handled.Add(this, &wasAlreadyAdded);
	if (wasAlreadyAdded == false)
	{
		state =! state;
		for(auto switchable : affectedSwitchables)
		{
			switchable->ToggleImp(handled);
		}
	}
}