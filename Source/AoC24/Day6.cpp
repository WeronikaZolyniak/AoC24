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


	//part 1
	/*bool GuardOutOfBounds = false;
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

	return sum;*/

	//part 2

	//guard's start coordinates
	char Start_direction = '^';
	int Start_x = Guard_x;
	int Start_y = Guard_y;

	int sum = 0;

	for (int y = 0; y < length; y++)
	{

		for (int x = 0; x < width; x++)
		{
			//array of visited obstacles
			//TArray<TPair<int, int>> VisitedObstaclesCords;

			//reset guard
			Array[Guard_y][Guard_x] = '.';
			Array[Start_y][Start_x] = Start_direction;
			Guard_y = Start_y;
			Guard_x = Start_x;

			//set new obstacle
			if (Array[y][x] != '.') continue;
			Array[y][x] = '#';

			//check loop
			bool GuardOutOfBounds = false;
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

				//check if already visited
				if (Array[Guard_y + movement_y][Guard_x + movement_x] == 'X')
				{
					sum++;
					break;
				}

				//check if there's an obstacle
				if (Array[Guard_y + movement_y][Guard_x + movement_x] == '#')
				{
					//Turn Right and move
					char NewGuardDirection = TurnRight(GuardDirection);
					GuardDirection = NewGuardDirection;

					//check new direction
					movement_x = 0;
					movement_y = 0;
					if (Array[Guard_y][Guard_x] == '^') movement_y = -1;
					else if (Array[Guard_y][Guard_x] == 'v') movement_y = 1;
					else if (Array[Guard_y][Guard_x] == '>') movement_x = 1;
					else if (Array[Guard_y][Guard_x] == '<') movement_x = -1;

					//mark direction as visited
					Array[Guard_y][Guard_x] = 'X';
					Guard_y += movement_y;
					Guard_x += movement_x;
					continue;
				}

				Array[Guard_y + movement_y][Guard_x + movement_x] = GuardDirection;
				Guard_y += movement_y;
				Guard_x += movement_x;

			}

			//clean markings
			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (Array[i][j] == 'X')
					{
						Array[i][j] = '.';
					}
				}
			}

			//reset obstacle
			Array[y][x] = '.';
		}
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
