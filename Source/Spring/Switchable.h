// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Switchable.generated.h"

//luodaan uusi delegaatti, t‰m‰nkaltainen voi ottaa max kahdeksan muuttujaa
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStateChangedEvent, bool, NewState);

UCLASS()
class SPRING_API ASwitchable : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASwitchable();


	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Switchable")
	TArray<ASwitchable*> affectedSwitchables;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(/*EditAnywhere, */BluePrintReadOnly, Category = "Switchable")
	bool state;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Switchable")
	void Enable();

	UFUNCTION(BlueprintCallable, Category = "Switchable")
	void Disable();

	UFUNCTION(BlueprintCallable, Category = "Switchable")
	void Toggle();


	UFUNCTION(BlueprintNativeEvent, category = "Switchable")
	void OnStateChanged(bool newState);

	UPROPERTY(BlueprintAssignable, category = "Switchable") //assignable eli blueprintiss‰ voidaan liitt‰‰ asioita
	FOnStateChangedEvent StateChanged;

protected: 
	void ToggleImp(TSet< ASwitchable* >& handled);
	void EnableImp(TSet< ASwitchable* >& handled);
	void DisableImp(TSet< ASwitchable* >& handled);



};
