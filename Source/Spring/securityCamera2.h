// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "actorTurnerComponent.h"
#include "securityCamera2.generated.h"

UCLASS()
class SPRING_API AsecurityCamera2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AsecurityCamera2();


	UactorTurnerComponent* turnerComponent; 


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DefaultMesh; 

};
