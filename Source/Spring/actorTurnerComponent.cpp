// Fill out your copyright notice in the Description page of Project Settings.


#include "actorTurnerComponent.h"


// Sets default values for this component's properties
UactorTurnerComponent::UactorTurnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	lerpAlpha = 0.0f;
	holdTime = 0.0f;
	holdRemaining = 0.0f;
	reverseDirection = false;
	rotationSpeed = 1.0f;
	isActive = true;
	

	// ...
}


// Called when the game starts
void UactorTurnerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UE_LOG(LogTemp, Warning, TEXT("ActorComponent on olemassa"));

}


// Called every frame
void UactorTurnerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* owner = GetOwner();

	UE_LOG(LogTemp, Display, TEXT(""));

	// ...
}


FRotator UactorTurnerComponent::TurnActor(float DeltaTime)
{
	FRotator newRot = (startPosition);
	
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
		
		newRot = FMath::Lerp(startPosition, endPosition, lerpAlpha);

		
		//owner.SetActorRotation(newRot);
	}
	return newRot;
}




