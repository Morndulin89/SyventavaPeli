// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//add timeline component to the file
#include "Components/TimelineComponent.h"
#include "GameFramework/Actor.h"
#include "actorTurnerComponent.h"
#include "securityCamera2.generated.h"

class UCurveFloat;

UCLASS()
class SPRING_API AsecurityCamera2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AsecurityCamera2();

	/*
		UFUNCTION()
	void TimelineProgress(float value);
	


	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Surveillance")
	bool isActive;


	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Surveillance")
	FRotator startPosition;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Surveillance")
	FRotator endPosition; //kierrot (alku- ja p‰‰tepiste)


	UPROPERTY(EditAnywhere, Category = "Surveillance")
	UCurveFloat* CurveFloat;

	FTimeline CurveTimeline;
	*/


	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Surveillance")
	UactorTurnerComponent* actorComponent;





protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
