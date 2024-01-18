// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "testActor.generated.h"

UCLASS()
class SPRING_API AtestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AtestActor();

	//lisätään muuttujia ja laitetaan ne näkyväksi Unrealissa
	UPROPERTY(EditAnywhere/*muokkaa missä tahansa, näkyy editorissa*/, 
		BluePrintReadWrite/*Blueprinteistä löytyy arvo*/, 
		Category = "Testing"/*mistä kategoriasta muuttuja löytyy*/)
	float testFloatNum;
	UPROPERTY(EditAnywhere,	BluePrintReadWrite,	Category = "Testing")
	FVector testVector;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//tehdään funktio näkyväksi UnrealEnginen blueprintissä
	UFUNCTION(BlueprintCallable, Category = "Testing")
	float testActorFunction(bool value, float arvo); //laitetaan funktiolle parametrit ja palautusarvo


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Testing")
	void testActorFunction2();

};
