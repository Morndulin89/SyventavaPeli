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

float UEnergySource::RequestCharge(float value)
{
	if (Energy > value)
	{
		Energy -= value;
		return value; 
	}
	else
	{
		return value; 
	}
}
