// Fill out your copyright notice in the Description page of Project Settings.


#include "Day2.h"
#include "ReadTextFiles.h"

//0 - decreasing, 1 - increasing, 2 - invalid
int UDay2::IsIncreasing(int no1, int no2)
{
	if (no1 == no2 || abs(no1 - no2) > 3) return 2;
	if (no1 - no2 < 0) return 0;
	else return 1;
}

int UDay2::ReturnAnswer(TArray<FString> Strings)
{
	//part 1
	/*int sum = 0;
	for (FString line : Strings)
	{
		TArray<FString> Array = UReadTextFiles::ParseStringIntoArray(line);
		if (IsValid(Array)) sum++;
	}

	return sum;*/

	//part 2
	int sum = 0;
	for (FString line : Strings)
	{
		TArray<FString> Array = UReadTextFiles::ParseStringIntoArray(line);
		if (IsValid(Array)) sum++;
		else
		{
			for (int i = 0; i < Array.Num(); i++)
			{
				TArray<FString> ArrayCopy = Array;
				ArrayCopy.RemoveAt(i);
				if (IsValid(ArrayCopy))
				{
					sum++;
					break;
				}
			}
		}
	}
	return sum;

	TMap<int, int> map;
	map.Add(1);
}

bool UDay2::IsValid(TArray<FString> Array)
{
	int Increasing = 1;
	bool IsValid = true;
	if (IsIncreasing(FCString::Atoi(*Array[0]), FCString::Atoi(*Array[1])) == 2)
	{
		return false;
	}
	else if (IsIncreasing(FCString::Atoi(*Array[0]), FCString::Atoi(*Array[1])) == 0)
	{
		Increasing = 0;
	}

	for (int i = 2; i < Array.Num(); i++)
	{
		if (IsIncreasing(FCString::Atoi(*Array[i - 1]), FCString::Atoi(*Array[i])) != Increasing)
		{
			IsValid = false;
			break;
		}
	}

	return IsValid;
}
