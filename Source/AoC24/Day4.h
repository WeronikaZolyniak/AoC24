// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Day4.generated.h"

/**
 * 
 */
UCLASS()
class AOC24_API UDay4 : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static int ReturnAnswer(FString String);
	
};
