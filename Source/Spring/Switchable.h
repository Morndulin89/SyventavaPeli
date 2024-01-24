// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Switchable.generated.h"

UCLASS()
class SPRING_API ASwitchable : public APawn
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

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Switchable")
	void Enable();

	UFUNCTION(BlueprintCallable, Category = "Switchable")
	void Disable();

	UFUNCTION(BlueprintCallable, Category = "Switchable")
	void Toggle();

protected: 
	void ToggleImp(TSet< ASwitchable* >& handled);

};
