// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Day2.generated.h"

/**
 * 
 */
UCLASS()
class AOC24_API UDay2 : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	static int ReturnAnswer(TArray<FString> Strings);

	static bool IsValid(TArray<FString> Array);

	static int IsIncreasing(int no1, int no2);
};
