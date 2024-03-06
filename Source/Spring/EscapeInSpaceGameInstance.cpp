// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeInSpaceGameInstance.h"
#include "AsteroidField.h"
#include "Kismet/GameplayStatics.h"


void UEscapeInSpaceGameInstance::Save()
{
	
		SaveGameInstance = Cast<UAsteroidFieldSaveGame>(UGameplayStatics::CreateSaveGameObject(UAsteroidFieldSaveGame::StaticClass()));

	if (SaveGameInstance)
	{
		TArray<AActor*> asteroidFields;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAsteroidField::StaticClass(), asteroidFields);
		AAsteroidField* field = Cast<AAsteroidField>(asteroidFields[0]);
		for (auto asteroid : field->asteroids)
		{
			asteroid->Save(*this);
		}
		if (UGameplayStatics::SaveGameToSlot(SaveGameInstance, DEFAULT_SAVE_SLOT_NAME, DEFAULT_SAVE_USER_INDEX))
		{
			UE_LOG(LogTemp, Warning, TEXT("Saving finished"));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Saving failed"));
		}
		
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Could not create save object"));
	}
}

void UEscapeInSpaceGameInstance::Load()
{
}

void UEscapeInSpaceGameInstance::Save(AAsteroid& asteroid)
{
	FAsteroidStruct as;
	as.transform = asteroid.GetActorTransform();
	as.type = EAsteroidType::RegularAsteroid;
}
