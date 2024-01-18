// Fill out your copyright notice in the Description page of Project Settings.


#include "testActor.h"

// Sets default values
AtestActor::AtestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	testFloatNum = 3.0f;
	testVector.Set(2.0f, 2.0f, 2.0f);

}

// Called when the game starts or when spawned
void AtestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AtestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AtestActor::testActorFunction(bool value, float arvo)
{
	return 40.0f;
}

//luo eventin, johon toteutus tehd‰‰n blueprintiss‰
void AtestActor::testActorFunction2_Implementation()
{
}

