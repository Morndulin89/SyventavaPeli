// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"



/**
 * 
 */
class SPRING_API DialogLoader
{
public:
	DialogLoader();
	~DialogLoader();

	UFUNCTION(BlueprintCallable, Category = "custom")
	static bool FileSaveString(FString SaveTextB, FString FileNameB);

	UFUNCTION(BlueprintCallable, Category = "custom")
	static bool FileLoadString(FString FileNameA, FString& SaveTextA);

};
