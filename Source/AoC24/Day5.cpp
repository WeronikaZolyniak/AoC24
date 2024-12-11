// Fill out your copyright notice in the Description page of Project Settings.


#include "Day5.h"
#include "ReadTextFiles.h"

int UDay5::ReturnAnswer(FString String)
{
	TArray<FString> Lines = UReadTextFiles::ParseStringIntoArrayofLines(String);
	TMap<int, TArray<int>> OrderMap;
	TArray<TArray<FString>> PrintQueues;
	int sum = 0;
	for (FString line : Lines)
	{
		int index;
		if (line.FindChar('|',index))
		{
			int key = FCString::Atoi(*line.Left(2));
			int value = FCString::Atoi(*line.Right(2));
			if (OrderMap.Find(key) != nullptr)
			{
				OrderMap[key].Add(value);
			}
			else
			{
				TArray<int> TempArray;
				TempArray.Add(value);
				OrderMap.Add(key, TempArray);
			}
			
		}
		else if(line.FindChar(',', index))
		{
			TArray<FString> TempArray;
			FString TempString = "";
			for (char c : line)
			{
				if (c == ',')
				{
					TempArray.Add(TempString);
					TempString = "";
					continue;
				}
				if (c >= '0' && c <= '9')
				{
					TempString += c;
				}
				
			}
			TempArray.Add(TempString);
			PrintQueues.Add(TempArray);

		}
	}

	//part 1
	/*for (TArray<FString> Queue : PrintQueues)
	{
		if (QueueIsCorrect(OrderMap, Queue))
		{
			int middleindex = ceil(Queue.Num() /2);
			int middlelement = FCString::Atoi(*Queue[middleindex]);
			sum += middlelement;
		}
	}
	return sum;*/

	TArray<TArray<FString>> IncorrectQueues;
	for (TArray<FString> Queue : PrintQueues)
	{
		if (!QueueIsCorrect(OrderMap, Queue))
		{
			IncorrectQueues.Add(Queue);
		}
	}

	for (TArray<FString> IncorrectQueue : IncorrectQueues)
	{
		int middle = ReturnCorrectMiddle(IncorrectQueue, OrderMap);
		sum += middle;
	}
	return sum;
}

bool UDay5::QueueIsCorrect(TMap<int, TArray<int>> OrderMap, TArray<FString> PrintQueue)
{
	for (int i = 1; i < PrintQueue.Num(); i++)
	{
		int currentNum = FCString::Atoi(*PrintQueue[i]);
		TArray<int> NumbersAfter = *OrderMap.Find(currentNum);
		for (int j = 0; j < i; j++)
		{
			int numtocheck = FCString::Atoi(*PrintQueue[j]);
			for (int numberafter : NumbersAfter)
			{
				if (numberafter == numtocheck) return false;
			}
		}
	}
	return true;
}

int UDay5::ReturnCorrectMiddle(TArray<FString> IncorrectQueue, TMap<int, TArray<int>> OrderMap)
{
	



	return 0;
}
