// Fill out your copyright notice in the Description page of Project Settings.


#include "Switchable.h"

// Sets default values
ASwitchable::ASwitchable()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	state = true; 

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

void ASwitchable::Enable()
{
	TSet<ASwitchable*> handled;
	EnableImp(handled);
}


void ASwitchable::Disable()
{
	TSet<ASwitchable*> handled;
	DisableImp(handled);
}


void ASwitchable::Toggle()
{
	TSet<ASwitchable*> handled;
	ToggleImp(handled);
}


void ASwitchable::EnableImp(TSet< ASwitchable* >& handled)
{
	bool wasAlreadyAdded;
	handled.Add(this, &wasAlreadyAdded);
	if (wasAlreadyAdded == false)

		if (state == false)
		{
			state = true;
			OnStateChanged(state);
			StateChanged.Broadcast(state);
		}
	{
		
		for (auto switchable : affectedSwitchables)
		{
			if (switchable)
			{
				switchable->EnableImp(handled);
			}
			else
			{
				//errorhandling with a log-text
				UE_LOG(LogTemp, Warning, TEXT("Affected switchable was NULL in '%s', please update or remove switchable"), *GetName());
			}

		}

	}
}

void ASwitchable::DisableImp(TSet< ASwitchable* >& handled)
{
	bool wasAlreadyAdded;
	handled.Add(this, &wasAlreadyAdded);
	if (wasAlreadyAdded == false)
	{
		if (state == true)
		{
			state = false;
			OnStateChanged(state);
			StateChanged.Broadcast(state);
		}
		
		for (auto switchable : affectedSwitchables)
		{
			if (switchable)
			{
				switchable->DisableImp(handled);
			}
			else
			{
				//errorhandling with a log-text
				UE_LOG(LogTemp, Warning, TEXT("Affected switchable was NULL in '%s', please update or remove switchable"), *GetName());
			}

		}

	}
}

void ASwitchable::ToggleImp(TSet< ASwitchable* > &handled)
{
	bool wasAlreadyAdded;
	handled.Add(this, &wasAlreadyAdded);
	if (wasAlreadyAdded == false)
	{
		state =! state;
		OnStateChanged(state);
		StateChanged.Broadcast(state);
		for(auto switchable : affectedSwitchables)
		{
			if (switchable)
			{

				switchable->ToggleImp(handled);
				UE_LOG(LogTemp, Display, TEXT("Switchable %s was activated"), *GetName());
				
			}
			else
			{
				//errorhandling with a log-text
				UE_LOG(LogTemp, Warning, TEXT("Affected switchable was NULL in '%s', please update or remove switchable"), *GetName());
			}
			
		}

	}
	
}


/*
Implementation-sana mahdollistaa blueprinteissä ylikirjoittamisen!
*/
void ASwitchable::OnStateChanged_Implementation(bool newState)
{
	//oletustoteutus tarvittaessa

}