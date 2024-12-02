// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReadTextFiles.generated.h"

/**
 * 
 */
UCLASS()
class AOC24_API UReadTextFiles : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static FString ReadStringFromFile(FString FilePath);

	UFUNCTION(BlueprintCallable)
	static TArray<FString> ParseStringIntoArray(FString String);

	UFUNCTION(BlueprintCallable)
	static TArray<FString> ParseStringIntoArrayofLines(FString String);
};
