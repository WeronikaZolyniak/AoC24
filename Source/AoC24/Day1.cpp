// Fill out your copyright notice in the Description page of Project Settings.


#include "Day1.h"

int UDay1::ReturnAnswer(TArray<FString> Strings)
{
	int sum = 0;

	for (FString string : Strings)
	{
		FString str_number = "";
		for (int i = 0; i < string.Len(); i++)
		{
			if (string[i] > '0' && string[i] <= '9')
			{
				str_number += string[i];
				break;
			}
		}

		for (int i = string.Len() - 1; i >= 0; i--)
		{
			if (string[i] >= '0' && string[i] <= '9')
			{
				str_number += string[i];
				break;
			}
		}

		sum += FCString::Atoi(*str_number);
	}
	

	return sum;
}
