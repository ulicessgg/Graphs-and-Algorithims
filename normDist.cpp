#include "project.h"


namespace NS_TEAM_PROJECT
{
	void genRandUniformDist(std::vector<int>& myNums, double mean, double stdDev)
	{
		if (mean == 0 || stdDev == 0)
		{
			std::cout << "Mean or Standard Deviation equal 0. Distribution not possible." << std::endl << std::endl;
			return;
		}

		const int size = 20000; // 20000 random intergers specifed in project description and is used for size of vector
		std::default_random_engine seed; // used to generate random numbers 
		std::normal_distribution<double> myDist(mean, stdDev); // using the meand and standard deviation a normal distribution is created
		int temp; // used to hold value of numbers from random generation

		myNums.resize(21, 0); // resizes the vector in order to organize its bins for future printing uses 21 as its size as this includes 0 as a number and the range is from 0 - 20

		// for loop used to generate 20000 random integers
		for (int i = 0; i < size; i++)
		{
			temp = static_cast<int>(std::round(myDist(seed))); // generates random value within the distribution and rounds it to an integer
			if (temp >= 0 && temp < myNums.size()) // checks random number is within our range
			{
				myNums[temp]++; // for each corressponding value their frequency is increased
			}
		}
		calcHistStats(myNums, mean, stdDev);// passes the values of the normal distribution to calculate and print statistical information
	}

	void calcHistStats(const std::vector<int>& myNums, double mean, double stdDev)
	{
		// mean median and mode are the same in normal distribution
		double median = mean;
		double mode = median;
		// standard deviation is the square root of the variance
		double variance = pow(stdDev, 2);

		auto minPos = std::min_element(myNums.begin(), myNums.end()); // mipos stores the minimum value
		size_t min = std::distance(myNums.begin(), minPos); // using minpos distance returns and stores the minimum value index
		auto maxPos = std::max_element(myNums.begin(), myNums.end()); // maxpos stores the maximum value
		size_t max = std::distance(myNums.begin(), maxPos); // using maxpos distance returns and stores the maximum value index

		// outputs histogram data to users
		std::cout << "Mean: " << mean << std::endl
				  << "Median: " << median << std::endl
				  << "Mode: " << mode << std::endl
				  << "Variance: " << variance << std::endl
				  << "Standard Deviation: " << stdDev << std::endl
				  << "Min: " << min << std::endl
				  << "Max: " << max << std::endl << std::endl;

		char sym; // char for user input and unit testing

		printHist(myNums, sym); // passes the values of the normal distribution to print
	}

	void calcHistStats(const std::vector<int>& myNums, double& mean, double& stdDev, double& median, double& mode, double& variance, size_t& min, size_t& max)
	{
		// mean median and mode are the same in normal distribution
		median = mean;
	    mode = median;
		// standard deviation is the square root of the variance
		variance = pow(stdDev, 2);

		auto minPos = std::min_element(myNums.begin(), myNums.end()); // mipos stores the minimum value
		min = std::distance(myNums.begin(), minPos); // using minpos distance returns and stores the minimum value index
		auto maxPos = std::max_element(myNums.begin(), myNums.end()); // maxpos stores the maximum value
		max = std::distance(myNums.begin(), maxPos); // using maxpos distance returns and stores the maximum value index

		// outputs histogram data to users
		std::cout << "Mean: " << mean << std::endl
				  << "Median: " << median << std::endl
				  << "Mode: " << mode << std::endl
				  << "Variance: " << variance << std::endl
				  << "Standard Deviation: " << stdDev << std::endl
				  << "Min: " << min << std::endl
				  << "Max: " << max << std::endl << std::endl;

		char sym; // char for user input and unit testing

		printHist(myNums, sym); // passes the values of the normal distribution to print
	}

	void printHist(const std::vector<int>& myNums, char& sym)
	{
		// if empty ends function
		if (myNums.empty())
		{
			return;
		}

		// allows for user specified symbol
		std::cout << "Enter symbol for histogram printing: ";
		std::cin >> sym;
		std::cout << std::endl;

		// iterates through the bins of the distribution
		for (int i = 0; i < myNums.size(); i++)
		{
			// prints out the value of the bin while aligning it to the rest
			std::cout << std::setw(2) << i << "|";
			// if the corresponding value is present
			if (myNums[i] > 0)
			{
				// prints * to show the frequency of it using 200 for scaleing and 20000 for the size of our distribution
				std::cout << std::string(myNums[i] * (200.0 / 20000.0), sym) << std::endl;
			}
			else
			{
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}

}
