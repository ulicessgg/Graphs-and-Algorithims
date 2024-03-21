#include "project.h"

namespace NS_TEAM_PROJECT
{
	void genRandNormalDist(std::vector<int>& myNums, double mean, double stdDev)
	{
		//catches mean or standard deviation if equal to 0 as it won't create a distribution if so
		if (mean == 0 || stdDev == 0)
		{
			std::cout << "Mean or Standard Deviation equal 0. Distribution not possible." << std::endl << std::endl;
			return;
		}

		const int size = 20000; // 20000 random integers specified in the project description and is used for the size of vector
		std::default_random_engine seed; // used to generate random numbers 
		std::normal_distribution<double> myDist(mean, stdDev); // using the mean and standard deviation a normal distribution is created

		int temp; // used to hold the value of numbers from random generation

		if (mean < 10) // if the mean is lesser than 10 the size is set to the mean plus 6 to make it a range of 10
		{
			myNums.resize((int)mean + 6, 0); // resizes the vector to organize its bins for future printing using the mean as it is the median 
											 // and adds 6 to make the range large enough to output 10 bins for example mean:9 size of 15 will output bins 
											 // 4 - 14 as the range is 5 on each side of the mean/median
		}
		else // if the mean is greater than 10 the size is set to the mean plus 11 to make it a range of 20
		{
			myNums.resize((int)mean + 11, 0); // resizes the vector to organize its bins for future printing using the mean as it is the median 
										 	  // and adds 6 to make the range large enough to output 10 bins for example mean:12 size of 23 will output bins 
											  // 2 - 22 as the range is 10 on each side of the mean/median
		}

		// for loop used to generate 20000 random integers
		for (int i = 0; i < size; i++)
		{
			temp = static_cast<int>(std::round(myDist(seed))); // generates a random value within the distribution and rounds it to an integer in order to create a histogram
			if (temp >= 0 && temp < myNums.size()) // checks random number is within our range
			{
				myNums[temp]++; // for each corresponding value their frequency is increased
			}
		}
		calcNormalHistStats(myNums, mean, stdDev);// passes the values of the normal distribution to calculate and print statistical information
	}

	void calcNormalHistStats(const std::vector<int>& myNums, double mean, double stdDev)
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

		printNormalHist(myNums, sym, mean); // passes the values of the normal distribution to print
	}

	void calcNormalHistStats(const std::vector<int>& myNums, double& mean, double& stdDev, double& median, double& mode, double& variance, size_t& min, size_t& max)
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

		printNormalHist(myNums, sym, mean); // passes the values of the normal distribution to print
	}

	void printNormalHist(const std::vector<int>& myNums, char& sym, const double& mean)
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

		
		if (mean <= 5) // if the mean is closer to 0 then the range starts from 0 until the end of the vector can range from 0 - 6 up to 0 - 10
		{
			for (size_t i = 0; i < myNums.size(); i++)
			{
				if (i < 0)
				{
					// prints out the value of the bin while aligning it to the rest
					std::cout << std::setw(2) << i << "|";
				}
				// prints out the value of the bin while aligning it to the rest
				std::cout << std::setw(2) << i << "|";
				// if the corresponding value is present

				if (myNums[i] > 0)
				{
					// prints user symbol to show the frequency of it using 200 for scaling and 20000 for the size of our distribution
					std::cout << std::string(myNums[i] * (200.0 / 20000.0), sym) << std::endl;
				}
				else
				{
					std::cout << std::endl;
				}
			}
		}
		else if (mean < 10) // if the mean is larger than 5 lesser than 10 then the range can be from 1 - 11 up to 4 - 14
		{
			for (size_t i = mean - 5; i < myNums.size(); i++)
			{
				// prints out the value of the bin while aligning it to the rest
				std::cout << std::setw(2) << i << "|";
				// if the corresponding value is present
				if (myNums[i] > 0)
				{
					// prints user symbol to show the frequency of it using 200 for scaling and 20000 for the size of our distribution
					std::cout << std::string(myNums[i] * (200.0 / 20000.0), sym) << std::endl;
				}
				else
				{
					std::cout << std::endl;
				}
			}
		}
		else // if the mean is larger than or equal to 10 then the range can be from 0 - 20 qnd ranges above this
		{
			for (size_t i = mean - 10; i < myNums.size(); i++) 
			{
				// prints out the value of the bin while aligning it to the rest
				std::cout << std::setw(2) << i << "|";
				// if the corresponding value is present
				if (myNums[i] > 0)
				{
					// prints user symbol to show the frequency of it using 200 for scaling and 20000 for the size of our distribution
					std::cout << std::string(myNums[i] * (200.0 / 20000.0), sym) << std::endl;
				}
				else
				{
					std::cout << std::endl;
				}
			}
		}
		std::cout << std::endl;
	}
}
