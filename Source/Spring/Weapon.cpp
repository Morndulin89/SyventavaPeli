// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "DrawDebugHelpers.h"

#define ENERGY_WEAPON_TRACE_CHANNEL	ECollisionChannel::ECC_GameTraceChannel2

void UWeapon::Shoot()
{
	FVector direction = GetOwner()->GetActorForwardVector();
	FHitResult outHit;

	FVector start = GetComponentLocation();
	FVector end = GetComponentLocation() + direction * Range;

	DrawDebugLine(GetWorld(), start, end, FColor::Green, false, 2.0f, 0U, 10.0f);
	GetWorld()->LineTraceSingleByChannel(outHit, start,end,
										ENERGY_WEAPON_TRACE_CHANNEL);
	AActor* hitActor = outHit.GetActor();
	if (hitActor)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Red, FString::Printf(TEXT("Weapon hits %s"), *hitActor->GetActorLabel()));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0, FColor::Blue, FString("Weapon missed"));
	}

}
