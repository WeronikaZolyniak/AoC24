// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <regex>
#include "Day3.generated.h"

/**
 * 
 */
UCLASS()
class AOC24_API UDay3 : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static int ReturnAnswer(FString String);
	
};
