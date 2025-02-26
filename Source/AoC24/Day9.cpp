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
    DiskMap.Add(-1);

    //part 1
    /*for (int i = 0; i < DiskMap.Num(); i++)
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
    }*/

    //part 2
    int blankspacesize = 0;
    bool blankspacebeingcounted = false;

    int filespacesize = 0;
    bool filebeingcounted = false;

    for (int i = 0; i < DiskMap.Num(); i++)
    {
        if (DiskMap[i] == -1)
        {
            if (blankspacebeingcounted)
            {
                blankspacesize++;
                continue;
            }
            else
            {
                blankspacesize = 1;
                blankspacebeingcounted = true;
                continue;
            }
        }
        else
        {
            if (blankspacebeingcounted)
            {
                blankspacebeingcounted = false;
                int blankspaceleft = blankspacesize;

                for (int j = DiskMap.Num() - 2; j > i; j--)
                {
                    if (blankspaceleft == 0) break;

                    if (DiskMap[j] != -1)
                    {
                        if (filebeingcounted && DiskMap[j - 1] == DiskMap[j])
                        {

                        }
                        else if (filebeingcounted && DiskMap[j - 1] == DiskMap[j] )
                        {
                            //end counting of one file, start another
                            filebeingcounted = false;
                            if
                        }
                    }
                    else
                    {

                    }
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

bool UDay9::CheckIfSpaceIsBigEnough(int blankspacesize, int filesize)
{
    return blankspacesize >= filesize;
}
