// Fill out your copyright notice in the Description page of Project Settings.


#include "securityCamera.h"

// Sets default values
AsecurityCamera::AsecurityCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	PrimaryActorTick.bCanEverTick = true;
	/*
	lerpAlpha = 0.0f;
	holdTime = 0.0f;
	holdRemaining = 0.0f;
	reverseDirection = false;
	rotationSpeed = 1.0f;
	*/
	
	//isActive = true;
	
	actorComponent = CreateDefaultSubobject<UactorTurnerComponent>(TEXT("turnerActorComponent"));
	
}

// Called when the game starts or when spawned
void AsecurityCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AsecurityCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


		
		SetActorRotation(actorComponent->TurnActor(DeltaTime));
		//turnOperation(DeltaTime);
	

}

void AsecurityCamera::turnOperation(float DeltaTime)
{
/*
	//if lerpAlpha (turning degree is under 1 and holdRemaining (delta time Passed) is below or 0.0)
	if (lerpAlpha > 1.0f && holdRemaining <= 0.0f)
	{
		reverseDirection = true;
		holdRemaining = holdTime;
	}
	else if (lerpAlpha < 0.0f && holdRemaining <= 0.0f)
	{
		reverseDirection = false;
		holdRemaining = holdTime;
	}
	if (holdRemaining > 0.0f)
	{
		holdRemaining -= DeltaTime;
		lerpAlpha = FMath::Clamp(lerpAlpha, 0.0f, 1.0f);
	}
	else
	{
		lerpAlpha = FMath::Clamp(lerpAlpha, 0.0f, 1.0f);
		if (reverseDirection) lerpAlpha -= rotationSpeed * DeltaTime;
		else                    lerpAlpha += rotationSpeed * DeltaTime;
		FRotator newRot = FMath::Lerp(startPosition, endPosition, lerpAlpha);

		SetActorRotation(newRot);
	}

*/
}

