// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Day8.generated.h"

/**
 * 
 */
UCLASS()
class AOC24_API UDay8 : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	static int ReturnAnswer(FString String);

	static bool ValuesAreOnArray(int x, int y, int length, int width);
};
