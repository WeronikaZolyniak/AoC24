// Fill out your copyright notice in the Description page of Project Settings.


#include "Day7.h"
#include "ReadTextFiles.h"

int UDay7::ReturnAnswer(FString String)
{
	//input
	TArray<FString> ArrayOfLines = UReadTextFiles::ParseStringIntoArrayofLines(String);
	TArray<int> testValues;
	TArray<TArray<int>> EquationNumbers;

	for (FString line : ArrayOfLines)
	{
		//test value
		FString testvalue_str = "";
		int lenoftestvalue_withsemicolon = 0;
		for (int i = 0; i < line.Len(); i++)
		{
			if (line[i] == ':')
			{
				lenoftestvalue_withsemicolon = i + 1;
				break;
			}
			testvalue_str += line[i];
		}
		testValues.Add(FCString::Atoi(*testvalue_str));

		FString RestOfString = line.RightChop(lenoftestvalue_withsemicolon);

		//equation numbers
		TArray<FString> Equationnumber_str;
		RestOfString.ParseIntoArrayWS(Equationnumber_str, (const TCHAR*)nullptr, true);
		TArray<int> ArrayToPush;
		for (FString number_str : Equationnumber_str)
		{
			int number = FCString::Atoi(*number_str);
			ArrayToPush.Add(number);
		}

		EquationNumbers.Add(ArrayToPush);
	}


	//part 1
	uint64 sum = 0;
	for (int i = 0; i < testValues.Num(); i++)
	{
		if (IsCorrect(testValues[i], EquationNumbers[i]))
		{
			//sum += testValues[i];
			//UE_LOG(LogTemp, Warning, TEXT("%i"), sum);
		}
	}

	//UE_LOG(LogTemp, Warning, TEXT("%i"), sum);
	return 0;
}

bool UDay7::IsCorrect(int TestValue, TArray<int> EquationValues)
{
	int numberOfSigns = EquationValues.Num() - 1;
	//0 - sum, 1 - multiplication
	TArray<bool> Signs;
	/*for (int i = 0; i < numberOfSigns; i++)
	{
		Signs.Add(0);
	}*/

	for (int i = 0; i < pow(2, numberOfSigns); i++)
	{
		Signs = DecToBinary(i, numberOfSigns);

		if (CalculateEquation(EquationValues, Signs) == TestValue)
		{
			UE_LOG(LogTemp, Error, TEXT("%i"), TestValue);
			return true;
		}
	}

	return false;
}

int UDay7::CalculateEquation(TArray<int> EquationValues, TArray<bool> Signs)
{
	int result = EquationValues[0];

	//0 - sum, 1 - multiplication
	for (int i = 1; i < EquationValues.Num(); i++)
	{
		if (Signs[i - 1] == 0)
		{
			result += EquationValues[i];
		}
		else
		{
			result *= EquationValues[i];
		}
	}
	return result;
}

TArray<bool> UDay7::DecToBinary(int number, int numberOfSigns)
{
	FString ReversedBin = "";
	if (number == 0) ReversedBin = "0";
	while (number > 0) {

		if (number % 2 == 0)
		{
			ReversedBin += '0';
		}
		else
		{
			ReversedBin += '1';
		}
		number = number / 2;
	}
	TArray<bool> return_array;

	for (int i = ReversedBin.Len(); i < numberOfSigns; i++)
	{
		ReversedBin += '0';
	}
			


	for (int i = ReversedBin.Len() - 1; i >= 0; i--)
	{
		if (ReversedBin[i] == '0')
		{
			return_array.Add(0);
		}
		else
		{
			return_array.Add(1);
		}
		
	}
	return return_array;
}
