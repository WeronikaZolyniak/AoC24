// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Day7.generated.h"

/**
 * 
 */
UCLASS()
class AOC24_API UDay7 : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static int ReturnAnswer(FString String);

	static bool IsCorrect(int TestValue, TArray<int> EquationValues);

	static int CalculateEquation(TArray<int> EquationValues, TArray<bool> Signs);

	static TArray<bool> DecToBinary(int number, int numberOfSigns);
	
};
