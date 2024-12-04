// Fill out your copyright notice in the Description page of Project Settings.


#include "Day4.h"
#include "ReadTextFiles.h"

int UDay4::ReturnAnswer(FString String)
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

	//part 1
	/*int sum = 0;
	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < width; x++)
		{
			
			if (Array[y][x] == 'X')
			{
				//up
				if (y - 3 >= 0)
				{
					if (Array[y - 1][x] == 'M' && Array[y - 2][x] == 'A' && Array[y - 3][x] == 'S') sum++;
				}
				//down
				if (y + 3 < length)
				{
					if (Array[y + 1][x] == 'M' && Array[y + 2][x] == 'A' && Array[y + 3][x] == 'S') sum++;
				}
				//right
				if (x + 3 < width)
				{
					if (Array[y][x+1] == 'M' && Array[y][x + 2] == 'A' && Array[y][x + 3] == 'S') sum++;
				}
				//left
				if (x - 3 >= 0)
				{
					if (Array[y][x - 1] == 'M' && Array[y][x - 2] == 'A' && Array[y][x - 3] == 'S') sum++;
				}
				//diagonally up-right
				if (y - 3 >= 0 && x + 3 < width)
				{
					if (Array[y - 1][ x + 1] == 'M' && Array[y - 2][x + 2] == 'A' && Array[y - 3][x + 3] == 'S') sum++;
				}
				//diagonally up-left
				if (y - 3 >= 0 && x - 3 >= 0)
				{
					if (Array[y - 1][x - 1] == 'M' && Array[y - 2][x - 2] == 'A' && Array[y - 3][x - 3] == 'S') sum++;
				}
				//diagonally down-right
				if (y + 3 < length && x + 3 < width)
				{
					if (Array[y + 1][x + 1] == 'M' && Array[y + 2][x + 2] == 'A' && Array[y + 3][x + 3] == 'S') sum++;
				}
				//diagonally down-left
				if (y + 3 < length && x - 3 >= 0)
				{
					if (Array[y + 1][x - 1] == 'M' && Array[y + 2][x - 2] == 'A' && Array[y + 3][x - 3] == 'S') sum++;
				}
			}
		}
	}
	return sum;*/

	//part2
	int sum = 0;

	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < width; x++)
		{

			if (Array[y][x] == 'A' && y - 1 >= 0 && y + 1 < length && x - 1 >= 0 && x + 1 < width)
			{
				if ((Array[y - 1][x + 1] == 'M' && Array[y + 1][x - 1] == 'S') || (Array[y - 1][x + 1] == 'S' && Array[y + 1][x - 1] == 'M'))
				{
					if ((Array[y - 1][x - 1] == 'M' && Array[y + 1][x + 1] == 'S') || (Array[y - 1][x - 1] == 'S' && Array[y + 1][x + 1] == 'M'))
					{
						sum++;
					}
				}
			}
		}
	}
	return sum;
}


