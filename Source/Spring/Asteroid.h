// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Asteroid.generated.h"

class UEscapeInSpaceGameInstance;

UCLASS()
class SPRING_API AAsteroid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAsteroid();

	UPROPERTY(EditAnywhere, Category="Asteroid")
	UStaticMeshComponent* Mesh; 


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Save(UEscapeInSpaceGameInstance& saveHandler); 

};
