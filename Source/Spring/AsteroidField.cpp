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

	//when Triggerbox is activated by an astroid, call destroyAsteroid-function
	triggerBox->OnComponentEndOverlap.AddDynamic(this, &AAsteroidField::DestroyOverlappedAsteroid);

	//create the base asteroids in the field
	CreateAsteroids();
	
}

// Called every frame
void AAsteroidField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//call CreateAsteroids-function in every tick
	CreateAsteroids();
	


}

//function that creates asteroids
void AAsteroidField::CreateAsteroids()
{
	this->Tags.Add(FName("AsteroidField"));
	//get the current amount of astroids and set it in a variable
	int NumAsteroids = asteroids.Num();
	
	//if there are less asteroids than wented, create more
	for (int i = NumAsteroids; i < maxAsteroidsInField; i++)
	{
		//get the center of the triggerbox
		FVector boxExtents = triggerBox->GetScaledBoxExtent() * 0.5;

		//set the spawn location for the asteroids
		FVector spawnLocation = this->GetActorLocation() +
			//get a random point within the triggerbox
			FVector(FMath::RandRange(-boxExtents.X, boxExtents.X),
				FMath::RandRange(-boxExtents.Y, boxExtents.Y),
				FMath::RandRange(-boxExtents.Z, boxExtents.Z));

		//if spawn location is too close to the ship, set it further away
		if (GetParentActor()) //check if has parent actor (like the ship in this case)
		{
			if ((spawnLocation - GetActorLocation()).Length() < noSpawnZoneRadius)
			{
				spawnLocation.Normalize();
				spawnLocation *= noSpawnZoneRadius;
				spawnLocation += GetActorLocation();
			}
		}


		FRotator spawnRotation = FRotator::ZeroRotator;

		//get random number from the Array, where all the types of asteroids are
		int randomAsteroidIndex = FMath::RandRange(0, types.Num() - 1);
		//create one of the asteroid types
		AAsteroid* newAsteroid = GetWorld()->SpawnActor<AAsteroid>(types[randomAsteroidIndex], spawnLocation, spawnRotation);

		//AAsteroid* newAsteroid = GetWorld()->SpawnActor<AAsteroid>(type, spawnLocation, spawnRotation);

		//add a tag to the asteroid (to enable the tracing)
		UPrimitiveComponent* pc = newAsteroid->FindComponentByClass<UPrimitiveComponent>();
		newAsteroid->Tags.Add(FName("Asteroid"));

		//random velocity to asteroid 
		FVector velocity = FVector(FMath::RandRange(-minVelocity.X, maxVelocity.X),
			FMath::RandRange(-minVelocity.Y, maxVelocity.Y),
			FMath::RandRange(-minVelocity.Z, maxVelocity.Z));


		pc->SetPhysicsLinearVelocity(velocity, true, NAME_None);					//laitetaan asteroidit liikkeelle

		//add the newly created asteroid to an array
		asteroids.Add(newAsteroid);

	}
}

void AAsteroidField::DestroyAsteroid(AActor* OtherActor)
{
	asteroids.Remove(Cast<AAsteroid>(OtherActor));
	OtherActor->Destroy();
}

void AAsteroidField::DestroyOverlappedAsteroid(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//check we destroy only asteroids on the endOverlap
	if (OtherActor->Tags.Contains(FName("asteroid")))
	{

		//remove the asteroid from the array and destroy it
		asteroids.Remove(Cast<AAsteroid>(OtherActor));
		OtherActor->Destroy();

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("not asteroid overlapped"));
	}

}

