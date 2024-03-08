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
			if (IsValid(asteroid))
			{
				asteroid->Save(*this);
			}
			
//tähän pelaajan lokaation tallennus
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
	//move game loading to main game thread
	//AsyncTask(ENamedThreads::GameThread, [this]() {

		//get the save file from the specified slot
		UAsteroidFieldSaveGame* LoadedGame = Cast<UAsteroidFieldSaveGame>(UGameplayStatics::LoadGameFromSlot(DEFAULT_SAVE_SLOT_NAME, DEFAULT_SAVE_USER_INDEX));
		if (LoadedGame)
		{
			TArray<AActor*> asteroidFields;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAsteroidField::StaticClass(), asteroidFields);
			AAsteroidField* field = Cast<AAsteroidField>(asteroidFields[0]);
			field->DestroyAllAsteroids();

			//get all the asteroids-structs from the savefile-array
			for (FAsteroidStruct & as : LoadedGame-> asteroids)
			{
			UClass* Class = nullptr;
			switch (as.type)
				{
				case EAsteroidType::RegularAsteroid:
				Class = AAsteroid::StaticClass();
				break;
				}
					if (Class == nullptr)
					{
				UE_LOG(LogTemp, Error, TEXT("Could not create asteroid - invalid type"));
					}
					else 
					{
						field->CreateAsteroid(Class, as.transform.GetLocation(), as.transform.Rotator(), FVector::ZeroVector, FVector::ZeroVector);
					}
			}
		}
		else 
		{
			UE_LOG(LogTemp, Error, TEXT("Could not load game - no game save slot found!"));
		}
	//});
}

void UEscapeInSpaceGameInstance::Save(AAsteroid& asteroid)
{
	FAsteroidStruct as;
	as.transform = asteroid.GetActorTransform();
	as.type = EAsteroidType::RegularAsteroid;
	SaveGameInstance->asteroids.Add(as);
}
