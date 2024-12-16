// Fill out your copyright notice in the Description page of Project Settings.


#include "Day8.h"
#include "ReadTextFiles.h"

int UDay8::ReturnAnswer(FString String)
{
	TArray<FString> ArrayofLines = UReadTextFiles::ParseStringIntoArrayofLines(String);
	int width = ArrayofLines[0].Len();
	int length = ArrayofLines.Num();
	TArray<TArray<char>> Array;
	TArray<TArray<char>> Antinodes;
	//input
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

	//blank antennas array
	for (int i = 0; i < length; i++)
	{
		TArray<char> line_array;
		for (int j = 0; j < width; j++)
		{
			line_array.Add('.');
		}
		Antinodes.Add(line_array);
	}

	int sum = 0;

	//part 1
	/*for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//check for antenna
			if (Array[y][x] != '.')
			{
				char antenna_frequency = Array[y][x];
				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < width; j++)
					{
						if (i == y && j == x) continue;
						//check for the same frequency
						if (Array[y][x] == Array[i][j])
						{
							int antinode_x = abs(x - j);
							int antinode_y = abs(y - i);

							//all options of placement
							if (y < i)
							{
								if (x < j)
								{
									antinode_y = -antinode_y;
									antinode_x = -antinode_x;
								}
								else
								{
									antinode_y = -antinode_y;
								}
							}
							else
							{
								if (x < j)
								{
									antinode_x = -antinode_x;
								}
							}

							//antinode from main antenna
							if (ValuesAreOnArray(x + antinode_x,y + antinode_y, length, width))
							{
								Antinodes[y + antinode_y][x + antinode_x] = '#';
							}

							//antinode from checked antenna
							int sec_antinode_y = -antinode_y;
							int sec_aninode_x = -antinode_x;
							if (ValuesAreOnArray(j + sec_aninode_x, i + sec_antinode_y, length, width))
							{
								Antinodes[i + sec_antinode_y][j + sec_aninode_x] = '#';
							}
						}
					}
				}
			}
		}
	}

	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (Antinodes[y][x] == '#')
			{
				sum++;
			}
		}
	}

	return sum;*/

	//part 2
	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//check for antenna
			if (Array[y][x] != '.')
			{
				char antenna_frequency = Array[y][x];
				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < width; j++)
					{
						if (i == y && j == x) continue;
						//check for the same frequency
						if (Array[y][x] == Array[i][j])
						{
							Antinodes[y][x] = '#';
							int antinode_x = abs(x - j);
							int antinode_y = abs(y - i);

							//all options of placement
							if (y < i)
							{
								if (x < j)
								{
									antinode_y = -antinode_y;
									antinode_x = -antinode_x;
								}
								else
								{
									antinode_y = -antinode_y;
								}
							}
							else
							{
								if (x < j)
								{
									antinode_x = -antinode_x;
								}
							}

							//antinode from main antenna
							int initial_antinode_x = antinode_x;
							int initial_antinode_y = antinode_y;
							while (ValuesAreOnArray(x + antinode_x, y + antinode_y, length, width))
							{
								Antinodes[y + antinode_y][x + antinode_x] = '#';
								antinode_x += initial_antinode_x;
								antinode_y += initial_antinode_y;
							}

							//antinode from checked antenna
							int sec_antinode_y = -antinode_y;
							int sec_aninode_x = -antinode_x;
							initial_antinode_x = sec_aninode_x;
							initial_antinode_y = sec_antinode_y;
							while (ValuesAreOnArray(j + sec_aninode_x, i + sec_antinode_y, length, width))
							{
								Antinodes[i + sec_antinode_y][j + sec_aninode_x] = '#';
								sec_aninode_x += initial_antinode_x;
								sec_antinode_y += initial_antinode_y;
							}
						}
					}
				}
			}
		}
	}


	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (Antinodes[y][x] == '#')
			{
				sum++;
			}
		}
	}

	return sum;
}

bool UDay8::ValuesAreOnArray(int x, int y, int length, int width)
{
	if (x < 0 || x >= width) return false;
	if (y < 0 || y >= length) return false;
	return true;
}
