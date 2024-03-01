// Fill out your copyright notice in the Description page of Project Settings.


#include "Recharger.h"


URecharger::URecharger()
{
//Add can tick	
	PrimaryComponentTick.bCanEverTick = true;
}

void URecharger::BeginPlay()
{
	//bring Super::BeginPlay to be able to enable tickcomponent
	Super::BeginPlay();
}

void URecharger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//get tick from Super
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//if TargetSource is set, recharge it in the rechargerate on every tick
	if (TargetSource)
	{
		TargetSource->AddCharge(DeltaTime * RechargeRate);
	}

}
