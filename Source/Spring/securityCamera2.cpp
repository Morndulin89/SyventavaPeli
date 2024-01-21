// Fill out your copyright notice in the Description page of Project Settings.


#include "securityCamera2.h"


// Sets default values
AsecurityCamera2::AsecurityCamera2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");


	rotateSpeed = 1.f;

//Kato tarviiko näitä!
	PitchValue = 0.0f;
	YawValue = 0.0f;
	RollValue = 0.0f;

	turnPitch = 0.f;
	turnYaw = 0.f;
	turnRoll = 0.f;


}

// Called when the game starts or when spawned
void AsecurityCamera2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AsecurityCamera2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
/*
	FQuat QuatRotation = FQuat(FRotator(PitchValue, YawValue, RollValue));

	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);

*/
}

void AsecurityCamera2::rotateActor(float DeltaTime)
{
	FRotator Rotator = GetOwner()->GetActorRotation();

}

