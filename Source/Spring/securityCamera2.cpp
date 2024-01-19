// Fill out your copyright notice in the Description page of Project Settings.


#include "securityCamera2.h"

// Sets default values
AsecurityCamera2::AsecurityCamera2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Default mesh"));

	turnerComponent = CreateDefaultSubobject <UactorTurnerComponent>(TEXT("actorTurner"));

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

}

