// Fill out your copyright notice in the Description page of Project Settings.


#include "securityCameraTurner.h"

// Sets default values for this component's properties
UsecurityCameraTurner::UsecurityCameraTurner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UsecurityCameraTurner::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Component is in use"))
	// ...
	
}


// Called every frame
void UsecurityCameraTurner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UE_LOG(LogTemp, Warning, TEXT("Component is ticking"))
	// ...
}

