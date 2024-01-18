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

	//lis�t��n muuttujia ja laitetaan ne n�kyv�ksi Unrealissa
	UPROPERTY(EditAnywhere/*muokkaa miss� tahansa, n�kyy editorissa*/, 
		BluePrintReadWrite/*Blueprinteist� l�ytyy arvo*/, 
		Category = "Testing"/*mist� kategoriasta muuttuja l�ytyy*/)
	float testFloatNum;
	UPROPERTY(EditAnywhere,	BluePrintReadWrite,	Category = "Testing")
	FVector testVector;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//tehd��n funktio n�kyv�ksi UnrealEnginen blueprintiss�
	UFUNCTION(BlueprintCallable, Category = "Testing")
	float testActorFunction(bool value, float arvo); //laitetaan funktiolle parametrit ja palautusarvo


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Testing")
	void testActorFunction2();

};
