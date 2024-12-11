// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Day5.generated.h"

/**
 * 
 */
UCLASS()
class AOC24_API UDay5 : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	static int ReturnAnswer(FString String);

	static bool QueueIsCorrect(TMap<int, TArray<int>> OrderMap, TArray<FString> PrintQueue);

	static int ReturnCorrectMiddle(TArray<FString> IncorrectQueue, TMap<int, TArray<int>> OrderMap);
};
