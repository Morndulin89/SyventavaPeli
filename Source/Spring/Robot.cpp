// Fill out your copyright notice in the Description page of Project Settings.


#include "Robot.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ARobot::ARobot()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> robotMesh(TEXT("SkeletalMesh'/Game/Characters/Robots/K9/SKM_K9.SKM_K9'"));

	if (robotMesh.Object)
	{
		TArray<USkeletalMeshComponent*> skeletalMeshes;
		GetComponents(skeletalMeshes, false);
		if (skeletalMeshes.Num() > 0)
		{
			skeletalMeshes[0]->SetSkeletalMesh(robotMesh.Object);
		}
	}

}

// Called when the game starts or when spawned
void ARobot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARobot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARobot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

