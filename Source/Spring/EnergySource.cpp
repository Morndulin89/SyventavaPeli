// Fill out your copyright notice in the Description page of Project Settings.


#include "EnergySource.h"

void UEnergySource::AddCharge(float charge)
{
	Energy += charge;
	Energy = FMath::Min(MaxEnergy, Energy);
}

float UEnergySource::GetCharge() const
{
	return Energy;
}

//if there is energy in the source, move some amount of energy
float UEnergySource::RequestCharge(float value)
{
	if (Energy > value)
	{
		Energy -= value;
		return value; 
	}
	else
	{
		float empty = Energy; 
		Energy = 0.0f; 
		GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Red, FString::Printf(TEXT("EnergySource empty")));
		return empty;


	}
}
