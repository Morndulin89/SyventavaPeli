// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorTurnerComponent.h"
#include "SecurityCamera.generated.h"

UCLASS()
class SPRING_API ASecurityCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASecurityCamera();

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Surveillance")
	UActorTurnerComponent* actorComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
public: 

	void turnOperation(float DeltaTime);

};
