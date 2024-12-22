// Fill out your copyright notice in the Description page of Project Settings.


#include "Day9.h"

int UDay9::ReturnAnswer(FString String)
{
    //converting input
    TArray<int> DiskMap;
    int id = 0;
    for (int i = 0; i < String.Len(); i++)
    {
        int number = String[i] - '0';
        if (i % 2 == 0)
        {
            for (int j = 0; j < number; j++)
            {
                DiskMap.Add(id);
            }
            id++;
        }
        else
        {
            for (int j = 0; j < number; j++)
            {
                DiskMap.Add(-1);
            }
        }
    }

    //part 1
    for (int i = 0; i < DiskMap.Num(); i++)
    {
        if (DiskMap[i] == -1)
        {
            for (int j = DiskMap.Num() - 1; j > i; j--)
            {
                if (DiskMap[j] != -1)
                {
                    DiskMap[i] = DiskMap[j];
                    DiskMap[j] = -1;
                    break;
                }
            }
        }
    }

    uint64 sum = 0;
    for (int i = 0; i < DiskMap.Num(); i++)
    {
        if (DiskMap[i] == -1) continue;
        sum += i * DiskMap[i];
    }

    return 0;
}
