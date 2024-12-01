// Fill out your copyright notice in the Description page of Project Settings.


#include "Day1.h"
#include "Containers/Map.h"

bool UDay1::SortCondition(int value1, int value2)
{
	return value1 < value2;
}

int UDay1::ReturnAnswer(TArray<FString> Strings)
{
	// first part
	int sum = 0;
	TArray<int> Array1;
	TArray<int> Array2;

	for (int i = 0; i < Strings.Num(); i++)
	{
		if (i % 2 == 0)
		{
			Array1.Add(FCString::Atoi(*Strings[i]));
		}
		else
		{
			Array2.Add(FCString::Atoi(*Strings[i]));
		}
	}

	Array1.Sort([](int32 A, int32 B) {
		return A < B;
		});

	Array2.Sort([](int32 A, int32 B) {
		return A < B;
		});

	TArray<int> Values;

	for (int elem : Array1)
	{
		Values.Add(elem);
	}

	int i = 0;
	for (auto elem : Array2)
	{
		Values[i] = abs(Values[i] - elem);
		i++;
	}

	for (int el : Values)
	{
		sum += el;
	}

	//return sum;

	//second part
	int similarityscore = 0;

	for (int el1 : Array1)
	{
		int numberofappearances = 0;
		for (int el2 : Array2)
		{
			if (el1 == el2)
			{
				numberofappearances++;
			}
		}
		similarityscore += el1 * numberofappearances;
	}

	return similarityscore;
}


