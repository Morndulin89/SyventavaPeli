// Fill out your copyright notice in the Description page of Project Settings.


#include "SecurityCamera2.h"
#include "ActorTurnerComponent.h"
#include "Components/TimelineComponent.h"

// Sets default values
ASecurityCamera2::ASecurityCamera2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//isActive = true; 

	actorComponent = CreateDefaultSubobject<UActorTurnerComponent>(TEXT("turnerActorComponent"));

}

// Called when the game starts or when spawned
void ASecurityCamera2::BeginPlay()
{
	Super::BeginPlay();

	/*
	* t��ll� t�m� toimii ihan oikein
	* 
		if (CurveFloat)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindUFunction(this, FName("TimelineProgress"));
		CurveTimeline.AddInterpFloat(CurveFloat, TimelineProgress);
		CurveTimeline.SetLooping(true);

		CurveTimeline.PlayFromStart();
	}
	*/
}

// Called every frame
void ASecurityCamera2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	/*
	* t�m�kin toimii oikein
	* 
		if(isActive)
	{
		CurveTimeline.TickTimeline(DeltaTime);
	}
}
	
	*/

	/*
	* t�m� toimii
	* 
	void AsecurityCamera2::TimelineProgress(float Value)
{
	FRotator newRotation = FMath::Lerp(startPosition, endPosition, Value);
	SetActorRotation(newRotation);
	*/
}
	
	
	


