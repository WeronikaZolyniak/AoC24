// Fill out your copyright notice in the Description page of Project Settings.


#include "Day6.h"
#include "ReadTextFiles.h"

int UDay6::ReturnAnswer(FString String)
{
	TArray<FString> ArrayofLines = UReadTextFiles::ParseStringIntoArrayofLines(String);
	int width = ArrayofLines[0].Len();
	int length = ArrayofLines.Num();
	TArray<TArray<char>> Array;
	for (int i = 0; i < length; i++)
	{
		TArray<char> line_array;
		FString line = ArrayofLines[i];
		for (int j = 0; j < width; j++)
		{
			line_array.Add(line[j]);
		}
		Array.Add(line_array);
	}

	return 0;
}

char UDay6::TurnRight(char Guard)
{
	if (Guard == '^') return '>';
	if (Guard == '>') return 'v';
	if (Guard == 'v') return '<';
	if (Guard == '<') return '^';
	return 0;
}
