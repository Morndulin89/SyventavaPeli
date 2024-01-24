// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "Components/ActorComponent.h"
#include "actorTurnerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPRING_API UactorTurnerComponent : public UActorComponent
{
	GENERATED_BODY()

public: 
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Surveillance")
	FRotator startPosition;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Surveillance")
	FRotator endPosition; //kierrot (alku- ja p‰‰tepiste)

	float lerpAlpha;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Surveillance")
	float rotationSpeed; //kiertonopeus
	
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Surveillance")
	bool isActivated;
	
	float holdTime;
	float holdRemaining;
	bool  reverseDirection;
	

	UFUNCTION()
	void TimelineProgress(float Value);

	UPROPERTY(EditAnywhere, Category = "Surveillance")
	UCurveFloat* CurveFloat;

	FTimeline CurveTimeline;



public:	
	// Sets default values for this component's properties
	UactorTurnerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
public: 
	UFUNCTION(BlueprintCallable, Category = "Surveillance")
	FRotator TurnActor(float DeltaTime);
		
};
