// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Asteroid.h"
#include "BigAsteroid.h"
#include "Components/BoxComponent.h"
#include "AsteroidField.generated.h"

UCLASS()
class SPRING_API AAsteroidField : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AsteroidField")
	UBoxComponent* triggerBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AsteroidField")
	int maxAsteroidsInField;

	UPROPERTY()
	TArray<AAsteroid*> asteroids;				


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AsteroidField")
	TArray<TSubclassOf<AAsteroid>> types; 

	
	/*
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AsteroidField")
	TSubclassOf<AAsteroid> type;
	*/



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AsteroidField")
	FVector minVelocity; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AsteroidField")
	FVector maxVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AsteroidField")
	float noSpawnZoneRadius;

	// Sets default values for this actor's properties
	AAsteroidField();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void DestroyOverlappedAsteroid(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
	void CreateAsteroids();

	UFUNCTION()
	void DestroyAsteroid(AActor* OtherActor);

	void CreateAsteroid(UClass *Class, const FVector& location, const FRotator& rotation, const FVector& velocity, const FVector& angularVelocity);
	
	void DestroyAllAsteroids();


};
