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


	//set static mesh component to actor, for easier testing
	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		UStaticMeshComponent* Mesh;



/*
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Surveillance")
		FRotator startPosition;		//kierrot (alkupiste)
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Surveillance")
		FRotator endPosition;		//kierrot (p‰‰tepiste)
*/
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Surveillance")
		float rotateSpeed;			//kierron nopeus

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Surveillance")
		float turnDegrees;		//kierron m‰‰r‰


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//create variables for setting the movement

	UPROPERTY(EditAnywhere, category = "ActorMovement")
	float PitchValue;
	UPROPERTY(EditAnywhere, category = "ActorMovement")
	float YawValue;
	UPROPERTY(EditAnywhere, category = "ActorMovement")
	float RollValue;

	float turnPitch;
	float turnYaw;
	float turnRoll;


	void rotateActor(float DeltaTime);
};
