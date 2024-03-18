#ifndef NORMDIST_H
#define NORMDIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>

namespace NORM_DIST
{
	// genNums accepts an empty vector which is populated through Normal Distribution using the mean and standard deviation from user input
	void genNums(std::vector<int>&, double, double);
	// calcStats calcualtes five number summary of the distribution and prints
	void calcStats(const std::vector<int>&, double, double);
	// printHist prints the populated vector
	void printHist(const std::vector<int>&);
}

#endif