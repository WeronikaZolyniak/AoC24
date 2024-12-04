// Fill out your copyright notice in the Description page of Project Settings.


#include "Day3.h"



int UDay3::ReturnAnswer(FString String)
{
	//part 1
	/*int sum = 0;

	std::string str = std::string(TCHAR_TO_UTF8(*String));
	std::smatch matches;
	std::regex regex("mul\\([0-9]{1,3},[0-9]{1,3}\\)");

	while (std::regex_search(str, matches, regex))
	{
		std::string match = matches[0];
		std::string no1 = "";
		std::string no2 = "";
		int numbertoaddto = 1;
		for (int i = 4; i < match.length() - 1; i++)
		{
			if (match[i] == ',')
			{
				numbertoaddto = 2;
				continue;
			}
			if (numbertoaddto == 1)
			{
				no1 += match[i];
			}
			else
			{
				no2 += match[i];
			}
		}
		sum += std::stoi(no1) * std::stoi(no2);
		str = matches.suffix().str();
	}
	
	return sum;*/


	//part 2
	int sum = 0;
	bool enabled = true;

	std::string str = std::string(TCHAR_TO_UTF8(*String));
	std::smatch matches;
	std::regex regex("mul\\([0-9]{1,3},[0-9]{1,3}\\)");
	std::regex do_dont_regex("don?'?t?\\(\\)");

	while (std::regex_search(str, matches, regex))
	{
		std::string prefix = matches.prefix().str();
		std::smatch prefixmatch;
		while (std::regex_search(prefix, prefixmatch, do_dont_regex))
		{
			if (prefixmatch[0] == "don't()")
			{
				enabled = false;
			}
			else if (prefixmatch[0] == "do()")
			{
				enabled = true;
			}
			prefix = prefixmatch.suffix().str();
		}

		std::string match = matches[0];
		if (enabled)
		{
			std::string no1 = "";
			std::string no2 = "";
			int numbertoaddto = 1;
			for (int i = 4; i < match.length() - 1; i++)
			{
				if (match[i] == ',')
				{
					numbertoaddto = 2;
					continue;
				}
				if (numbertoaddto == 1)
				{
					no1 += match[i];
				}
				else
				{
					no2 += match[i];
				}
			}
			sum += std::stoi(no1) * std::stoi(no2);
		}
		str = matches.suffix().str();
	}

	return sum;

}
