// Fill out your copyright notice in the Description page of Project Settings.


#include "EnergyConsumer.h"

UEnergyConsumer::UEnergyConsumer()
{
    PrimaryComponentTick.bCanEverTick = true;
}

bool UEnergyConsumer::ConsumeBurst()
{
    if (TargetSource)
   {
       float usedEnergy =  TargetSource->RequestCharge(BurstCunsumptionRate);
       return (usedEnergy >= BurstCunsumptionRate); //if the energy required is smaller than the energy used in burst, can use energy
     
   }
    return false;

}

void UEnergyConsumer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    //if target source is set, use energy on every tick
    if (TargetSource)
    {
        TargetSource->RequestCharge(ConstantConsumptionRatePerSecond * DeltaTime);
    }
}
