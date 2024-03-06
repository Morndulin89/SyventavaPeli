// Fill out your copyright notice in the Description page of Project Settings.


#include "Asteroid.h"
#include "EscapeInSpaceGameInstance.h"

// Sets default values
AAsteroid::AAsteroid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AsteroidMesh"));
	RootComponent = Mesh;
	Mesh->SetSimulatePhysics(true);
	Mesh->SetEnableGravity(false);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetGenerateOverlapEvents(true);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel2, ECollisionResponse::ECR_Block);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> asteroidMesh(TEXT("StaticMesh'/Game/Levels/Space/Graphics/Asteroids/asteroidi.asteroidi'"));
	
	if (asteroidMesh.Object)
	{
		TArray<UStaticMeshComponent*> staticMeshes;
		GetComponents(staticMeshes, false);
		if (staticMeshes.Num() > 0)
		{
			staticMeshes[0]->SetStaticMesh(asteroidMesh.Object);
		}
	}

}

// Called when the game starts or when spawned
void AAsteroid::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAsteroid::Save(UEscapeInSpaceGameInstance& saveHandler)
{

	saveHandler.Save(*this);
}



