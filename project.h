
#ifndef NS_TEAM_PROJECT_h
#define NS_TEAM_PROJECT_h

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <functional>

namespace NS_TEAM_PROJECT
{

    // using namespace std;

    // Used to store a specific token and its frequency.
    struct TokenFreq
    {
        std::string token;
        unsigned int freq;
    };

    

    // Generates a histogram of 20,000 randomly generated floating-point numbers according to a uniform distribution with a user-specified range
    void genRandUniformDist(std::vector<int> &myNums, double lowerBound, double upperBound);
    // TODO Accepts an empty vector which is populated through Normal Distribution using the mean and standard deviation from user input
    void genRandNormalDist(std::vector<int> &myNums, double mean, double stdDev);
    // Calculates five number summary of the distribution.
    void calcHistStats(const std::vector<int> &, double, double);
    // Prints out histogram with `sym` as representation of data points.
    void printHist(const std::vector<int> &myNums, char &sym);
    // The partition subroutine that's shared by the quickSort and k-th ranked  object algorithms
    template <typename T>
    int partition(const std::vector<TokenFreq> &arr, int tail, int head, std::function<bool(T, T)> comp);
    // An almost generic randomized-QuickSort algorithm to sort an array of TokenFreq objects by a given sorting criterion.
    template <typename T>
    void quickSort(std::vector<TokenFreq> &arr, int tail, int head, std::function<bool(T, T)> comp);
    // TODO Implement an almost generic algorithm (the randomized version) to find the k-th ranked object in an array without first sorting this array.
    void genKthRanked(std::vector<TokenFreq> &arr, int k);
    // Overloaded `calcHistStats()` calcualtes and prints five number summary of the distribution used for unit testing
    void calcHistStats(const std::vector<int> &, double &, double &, double &, double &, double &, size_t &, size_t &);

    // printHist prints the populated vector
    void printHist(const std::vector<int> &, char &);

}

#endif