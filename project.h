
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

    

    // TODO Generates a histogram of 20,000 randomly generated floating-point numbers according to a uniform distribution with a user-specified range
    void createHistogram(double rangeMin, double rangeMax);
    void printingHistogram(std::vector<int> dataNums, double rangeMin, double rangeMax, char& sym);
    //  Accepts an empty vector which is populated through Normal Distribution using the mean and standard deviation from user input
    void genRandNormalDist(std::vector<int>&, double, double);
    // Calculates a number summary of the distribution.
    void calcNormalHistStats(const std::vector<int>&, double, double);
    // Overloaded `calcHistStats()` calculates and prints a five-number summary of the distribution used for unit testing
    void calcNormalHistStats(const std::vector<int>&, double&, double&, double&, double&, double&, size_t&, size_t&);
    // Prints out histogram with `sym` as a representation of data points.
    void printNormalHist(const std::vector<int>&, char&, const double&);
    // The partition subroutine that's shared by the quickSort and k-th ranked  object algorithms
    template<typename T>
    int partition(std::vector<T> &arr, int tail, int head, std::function<bool(T, T)> comp);
    // An almost generic randomized-QuickSort algorithm to sort an array of TokenFreq objects by a given sorting criterion.
    template<typename T>
    void quickSort(std::vector<T> &arr, int tail, int head, std::function<bool(T, T)> comp);
    // An almost generic algorithm (the randomized version) to find the k-th ranked object in an array without first sorting this array.
    void genKthRanked(std::vector<TokenFreq> &arr, int k, std::function<bool(TokenFreq, TokenFreq)> comp);

    // printHist prints the populated vector
    void printHist(const std::vector<int> &, char &);

}

#endif
