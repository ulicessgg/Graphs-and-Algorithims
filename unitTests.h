#ifndef UNITTESTS_H
#define UNITTESTS_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include "normDist.h"

namespace UNIT_TESTS
{
	bool unitTest1_genNums()
	{
		std::vector<int> userNums;
		NORM_DIST::genNums(userNums, 0, 1); // with a mean of zero there can't be a normal distribution generated
		return userNums.empty(); // returns true if userNums is empty
	}

	bool unitTest2_genNums()
	{
		std::vector<int> userNums;
		NORM_DIST::genNums(userNums, 1, 0); // with a stdDev of zero there can't be a normal distribution generated
		return userNums.empty(); // returns true if userNums is empty
	}

	bool unitTest3_genNums()
	{
		std::vector<int> userNums;
		NORM_DIST::genNums(userNums, 9, 3);
		return userNums.size() == 15; // returns true if userNums has mean + 6 as its size
	}

	bool unitTest1_calcStats()
	{
		std::vector<int> userNums = {1,2,3,4,5,6,7,8,9,10,11,10,9,8,7,6,5,4,3,2,1};
		double mean = 10;
		double stdDev = 15;
		double median;
		double mode;
		double variance;
		size_t min;
		size_t max;
		NORM_DIST::calcStats(userNums, mean, stdDev, median, mode, variance, min, max);
		if (median == mean && mode == mean && variance == pow(stdDev, 2) && min == 0 && max == 10)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool unitTest2_calcStats()
	{
		std::vector<int> userNums = {1,2,4,8,4,2,1};
		double mean = 3;
		double stdDev = 1;
		double median;
		double mode;
		double variance;
		size_t min;
		size_t max;
		NORM_DIST::calcStats(userNums, mean, stdDev, median, mode, variance, min, max);
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

		NORM_DIST::printHist(userNums, sym);

		return (sym == '*');
	}

	bool unitTest2_printHist()
	{
		std::vector<int> userNums = {1,2,4,8,4,2,1};
		char sym = '*';

		NORM_DIST::printHist(userNums, sym);
		
		return !(sym == '*');
	}
}

#endif UNITTESTS_
