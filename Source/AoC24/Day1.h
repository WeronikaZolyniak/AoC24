// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Day1.generated.h"

/**
 * 
 */
UCLASS()
class AOC24_API UDay1 : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static int ReturnAnswer(TArray<FString> Strings);

	bool SortCondition(int value1, int value2);
	
};
