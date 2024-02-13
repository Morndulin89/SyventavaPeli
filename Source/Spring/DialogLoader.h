// copyright seppo.nevalainen@karelia.fi 2022

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DialogLoader.generated.h"

/**
 * Tämän saa lisättyä suoraan Unrealin puolelta, piti vaan valita C++ luokaksi suoraan tuo "BlueprintFunctionLibrary", ei empty
 */
UCLASS()
class SPRING_API UDialogLoader : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public: 
	UFUNCTION(BlueprintCallable, Category = "Dialog")
	static bool FileSaveString(FString SaveTextB, FString FileNameB);

	UFUNCTION(BlueprintCallable, Category = "Dialog")
	static bool FileLoadString(FString FileNameA, FString& SaveTextA);
};
