// Fill out your copyright notice in the Description page of Project Settings.


#include "Day6.h"
#include "ReadTextFiles.h"

int UDay6::ReturnAnswer(FString String)
{
	TArray<FString> ArrayofLines = UReadTextFiles::ParseStringIntoArrayofLines(String);
	int width = ArrayofLines[0].Len();
	int length = ArrayofLines.Num();
	TArray<TArray<char>> Array;

	int Guard_x = 0;
	int Guard_y = 0;

	for (int i = 0; i < length; i++)
	{
		TArray<char> line_array;
		FString line = ArrayofLines[i];
		for (int j = 0; j < width; j++)
		{
			if (line[j] == '^')
			{
				Guard_y = i;
				Guard_x = j;
			}
			line_array.Add(line[j]);
		}
		Array.Add(line_array);
	}

	bool GuardOutOfBounds = false;
	int sum = 1;
	while (!GuardOutOfBounds)
	{
		int movement_x = 0;
		int movement_y = 0;
		char GuardDirection = Array[Guard_y][Guard_x];

		//check direction
		if (Array[Guard_y][Guard_x] == '^') movement_y = -1;
		else if (Array[Guard_y][Guard_x] == 'v') movement_y = 1;
		else if (Array[Guard_y][Guard_x] == '>') movement_x = 1;
		else if (Array[Guard_y][Guard_x] == '<') movement_x = -1;

		//check if new position is out of bounds
		if (Guard_y + movement_y < 0 || Guard_y + movement_y >= length || Guard_x + movement_x < 0 || Guard_x + movement_x >= width)
		{
			GuardOutOfBounds = true;
			break;
		}

		//check if there's an obstacle
		if (Array[Guard_y + movement_y][Guard_x + movement_x] == '#')
		{
			char NewGuardDirection = TurnRight(GuardDirection);
			Array[Guard_y][Guard_x] = NewGuardDirection;
			GuardDirection = NewGuardDirection;
			continue;
		}

		//check if already visited
		if (Array[Guard_y + movement_y][Guard_x + movement_x] == 'X')
		{
			Array[Guard_y + movement_y][Guard_x + movement_x] = GuardDirection;
			Array[Guard_y][Guard_x] = 'X';
			Guard_y += movement_y;
			Guard_x += movement_x;
			continue;
		}

		Array[Guard_y + movement_y][Guard_x + movement_x] = GuardDirection;
		sum++;
		Array[Guard_y][Guard_x] = 'X';
		Guard_y += movement_y;
		Guard_x += movement_x;

	}

	return sum;
}

char UDay6::TurnRight(char Guard)
{
	if (Guard == '^') return '>';
	if (Guard == '>') return 'v';
	if (Guard == 'v') return '<';
	if (Guard == '<') return '^';
	return 0;
}
