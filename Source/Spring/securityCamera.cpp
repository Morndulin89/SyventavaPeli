// Fill out your copyright notice in the Description page of Project Settings.


#include "securityCamera.h"

// Sets default values
AsecurityCamera::AsecurityCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

