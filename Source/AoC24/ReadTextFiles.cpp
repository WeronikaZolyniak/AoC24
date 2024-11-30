// Fill out your copyright notice in the Description page of Project Settings.


#include "ReadTextFiles.h"
#include "HAL/PlatformFileManager.h"
#include "Misc/FileHelper.h"

FString UReadTextFiles::ReadStringFromFile(FString FilePath)
{
	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath))
	{
		FString RetString = "";

		if (FFileHelper::LoadFileToString(RetString, *FilePath))
		{
			return RetString;
		}
	}

	return "";
}

TArray<FString> UReadTextFiles::ParseStringIntoArray(FString String)
{
	TArray<FString> Array;
	String.ParseIntoArrayWS(Array, (const TCHAR*)nullptr, false);

	return Array;
}
