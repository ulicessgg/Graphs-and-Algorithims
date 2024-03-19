#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include "project.h"

namespace UNIT_TESTS
{
	bool unitTest1_genRandUniformDist()
	{
		std::vector<int> userNums;
		NS_TEAM_PROJECT::genRandUniformDist(userNums, 0, 1); // with a mean of zero there can't be a normal distribution generated
		return userNums.empty();							 // returns true if userNums is empty
	}

	bool unitTest2_genRandUniformDist()
	{
		std::vector<int> userNums;
		NS_TEAM_PROJECT::genRandUniformDist(userNums, 1, 0); // with a stdDev of zero there can't be a normal distribution generated
		return userNums.empty();							 // returns true if userNums is empty
	}

	bool unitTest3_genRandUniformDist()
	{
		std::vector<int> userNums;
		NS_TEAM_PROJECT::genRandUniformDist(userNums, 9, 3);
		return userNums.size() == 15; // returns true if userNums has mean + 6 as its size
	}

	bool unitTest1_calcHistStats()
	{
		std::vector<int> userNums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
		double mean = 10;
		double stdDev = 15;
		double median;
		double mode;
		double variance;
		size_t min;
		size_t max;
		NS_TEAM_PROJECT::calcHistStats(userNums, mean, stdDev, median, mode, variance, min, max);
		if (median == mean && mode == mean && variance == pow(stdDev, 2) && min == 0 && max == 10)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool unitTest2_calcHistStats()
	{
		std::vector<int> userNums = {1, 2, 4, 8, 4, 2, 1};
		double mean = 3;
		double stdDev = 1;
		double median;
		double mode;
		double variance;
		size_t min;
		size_t max;
		NS_TEAM_PROJECT::calcHistStats(userNums, mean, stdDev, median, mode, variance, min, max);
		if (median == mean && mode == mean && variance == pow(stdDev, 2) && min == 0 && max == 3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool unitTest1_printHist()
	{
		std::vector<int> userNums;
		char sym = '*';

		NS_TEAM_PROJECT::printHist(userNums, sym);

		return (sym == '*');
	}

	bool unitTest2_printHist()
	{
		std::vector<int> userNums = {1, 2, 4, 8, 4, 2, 1};
		char sym = '*';

		NS_TEAM_PROJECT::printHist(userNums, sym);

		return !(sym == '*');
	}

	bool _isSortedDesc(const std::vector<NS_TEAM_PROJECT::TokenFreq> &vector)
	{
		bool isSorted = true;
		std::cout << "{";

		if (vector.size() > 1)
		{
			std::cout << vector[0].freq;
		}
		for (size_t i = 1; i < vector.size(); ++i)
		{
			std::cout << ", " << vector[i].freq;
			if (vector[i].freq > vector[i - 1].freq)
			{
				isSorted = false;
			}
		}
		std::cout << "} ";
		return isSorted;
	}
	bool _isSortedAsc(const std::vector<NS_TEAM_PROJECT::TokenFreq> &vector)
	{
		bool isSorted = true;
		std::cout << "{";

		if (vector.size() > 1)
		{
			std::cout << vector[0].freq;
		}
		for (size_t i = 1; i < vector.size(); ++i)
		{
			std::cout << ", " << vector[i].freq;
			if (vector[i].freq < vector[i - 1].freq)
			{
				isSorted = false;
			}
		}
		std::cout << "} ";
		return isSorted;
	}

	bool unitTest1_quickSort()
	{
		std::vector<NS_TEAM_PROJECT::TokenFreq> insertionSortVector;
		insertionSortVector.push_back(NS_TEAM_PROJECT::TokenFreq{"token4", 200});
		insertionSortVector.push_back(NS_TEAM_PROJECT::TokenFreq{"token4", 3});
		insertionSortVector.push_back(NS_TEAM_PROJECT::TokenFreq{"token4", 1});
		insertionSortVector.push_back(NS_TEAM_PROJECT::TokenFreq{"token4", 3});

		auto comp = [](const NS_TEAM_PROJECT::TokenFreq &o1, const NS_TEAM_PROJECT::TokenFreq &o2)
		{
			return (o1.freq > o2.freq);
		};

		int head = insertionSortVector.size() - 1;

		NS_TEAM_PROJECT::quickSort(insertionSortVector, 0, head, comp);

		// Check if the vector is sorted
		if (_isSortedAsc(insertionSortVector))
		{
			std::cout << "test1_quickSort Passed" << std::endl;
			return true;
		}

		std::cout << "test1_quickSort Failed" << std::endl;
		return false;
	}

	bool unitTest2_quickSort()
	{
		std::vector<NS_TEAM_PROJECT::TokenFreq> insertionSortVector;
		insertionSortVector.push_back(NS_TEAM_PROJECT::TokenFreq{"token4", 4});
		insertionSortVector.push_back(NS_TEAM_PROJECT::TokenFreq{"token4", 1});
		insertionSortVector.push_back(NS_TEAM_PROJECT::TokenFreq{"token4", 3});
		insertionSortVector.push_back(NS_TEAM_PROJECT::TokenFreq{"token4", 2});

		auto comp = [](const NS_TEAM_PROJECT::TokenFreq &o1, const NS_TEAM_PROJECT::TokenFreq &o2)
		{
			return (o1.freq < o2.freq);
		};

		int head = insertionSortVector.size() - 1;

		NS_TEAM_PROJECT::quickSort(insertionSortVector, 0, head, comp);

		// Check if the vector is sorted
		if (_isSortedDesc(insertionSortVector))
		{
			std::cout << "test2_quickSort Passed" << std::endl;
			return true;
		}

		std::cout << "test2_quickSort Failed" << std::endl;
		return false;
	}

	bool unitTest3_quickSort()
	{
		std::vector<NS_TEAM_PROJECT::TokenFreq> insertionSortVector;
		insertionSortVector.push_back(NS_TEAM_PROJECT::TokenFreq{"token4", 0});
		insertionSortVector.push_back(NS_TEAM_PROJECT::TokenFreq{"token4", 0});
		insertionSortVector.push_back(NS_TEAM_PROJECT::TokenFreq{"token4", 0});

		auto comp = [](const NS_TEAM_PROJECT::TokenFreq &o1, const NS_TEAM_PROJECT::TokenFreq &o2)
		{
			return (o1.freq > o2.freq);
		};

		int head = insertionSortVector.size() - 1;

		NS_TEAM_PROJECT::quickSort(insertionSortVector, 0, head, comp);

		// Check if the vector is sorted
		if (_isSortedAsc(insertionSortVector))
		{
			std::cout << "test3_quickSort Passed" << std::endl;
			return true;
		}

		std::cout << "test3_quickSort Failed" << std::endl;
		return false;
	}
}

#endif
