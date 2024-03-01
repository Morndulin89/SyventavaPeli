// Fill out your copyright notice in the Description page of Project Settings.


#include "Recharger.h"


URecharger::URecharger()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void URecharger::BeginPlay()
{
	Super::BeginPlay();
}

void URecharger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Red, FString::Printf(TEXT("Recharger is ticking")));
	if (TargetSource)
	{
		TargetSource->AddCharge(DeltaTime * RechargeRate);
	}

}
