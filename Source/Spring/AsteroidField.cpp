// Fill out your copyright notice in the Description page of Project Settings.


#include "AsteroidField.h"

// Sets default values
AAsteroidField::AAsteroidField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	triggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));	//luodaan UBoxcomponent 
	RootComponent = triggerBox;	//Set it as rootcomponent
}

// Called when the game starts or when spawned
void AAsteroidField::BeginPlay()
{
	Super::BeginPlay();

	triggerBox->OnComponentEndOverlap.AddDynamic(this, &AAsteroidField::DestroyAsteroid);
	CreateAsteroids();

	
	
}

// Called every frame
void AAsteroidField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (currentAmountOfAsteroids < maxAsteroidsInField)
	{

	}

}

void AAsteroidField::DestroyAsteroid(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//check we destroy only asteroids on the endOverlap
	if (OtherActor->Tags.Contains(FName("asteroid"))) 
	{
		asteroids.Remove(Cast<AAsteroid>(OtherActor));
		OtherActor->Destroy();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("not asteroid overlapped"));
	}
	
}

void AAsteroidField::CreateAsteroids()
{
	for (int i = 0; i < maxAsteroidsInField; i++)
	{
		FVector boxExtents = triggerBox->GetScaledBoxExtent() * 0.5;
		FVector spawnLocation = this->GetActorLocation() +
			FVector(FMath::RandRange(-boxExtents.X, boxExtents.X),
				FMath::RandRange(-boxExtents.Y, boxExtents.Y),
				FMath::RandRange(-boxExtents.Z, boxExtents.Z));

		if (GetParentActor())
		{
			if ((spawnLocation - GetActorLocation()).Length() < noSpawnZoneRadius)
			{
				spawnLocation.Normalize();
				spawnLocation *= noSpawnZoneRadius;
				spawnLocation += GetActorLocation();
			}
		}


		FRotator spawnRotation = FRotator::ZeroRotator;


		//int randomAsteroidIndex = FMath::RandRange(0, types.Num() - 1);
		//AAsteroid* newAsteroid = GetWorld()->SpawnActor<AAsteroid>(types[randomAsteroidIndex], spawnLocation, spawnRotation);

		AAsteroid* newAsteroid = GetWorld()->SpawnActor<AAsteroid>(type, spawnLocation, spawnRotation);

		UPrimitiveComponent* pc = newAsteroid->FindComponentByClass<UPrimitiveComponent>();
		newAsteroid->Tags.Add(FName("asteroid"));

		//random velocity to asteroid 
		FVector velocity = FVector(FMath::RandRange(-minVelocity.X, maxVelocity.X),
			FMath::RandRange(-minVelocity.Y, maxVelocity.Y),
			FMath::RandRange(-minVelocity.Z, maxVelocity.Z));


		pc->SetPhysicsLinearVelocity(velocity, true, NAME_None);					//laitetaan asteroidit liikkeelle

		asteroids.Add(newAsteroid);
		currentAmountOfAsteroids++;
	}
}
