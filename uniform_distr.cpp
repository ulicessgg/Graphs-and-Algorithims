#include <iostream>
#include <random>
#include <string>
#include <iomanip>

void printingHistogram(std::vector<int> dataNums, double rangeMin, double rangeMax, char& sym)
{
    if (dataNums.empty()) {  // checking if data is empty and printing "empty" if it is
        std::cout << "Empty";
        return;
    }
    std::cout << "Enter symbol for histogram printing: "; // prompting user for input on symbol
    std::cin >> sym;
    std::cout << std::endl;

    for (int i = 0; i < dataNums.size(); ++i) { // for loop used to print out the histogram
        std::cout << (float(i) / 10)+rangeMin << "-" << (float(i + 1) / 10)+ rangeMin << ": ";
        std::cout << std::string(dataNums[i] * 400.0 / 20000.0, '*') << std::endl;
    }
}

void createHistogram(double rangeMin, double rangeMax) {
    const int dataSize = 20000; // declare size of distribution as 20000
    const int intervals = static_cast<int>(rangeMax - rangeMin) * 10; // declaring intervals sizes

    std::default_random_engine randomNums; //  used to generate random numbers
    std::uniform_real_distribution<double> distribution(rangeMin, rangeMax); // declare uniform distribution function using the range with upper bound and lower bound variables


    std::vector<int> dataNums(intervals, 0); // declaring dataNums with the intervals
    double tempNums = 0;

    for (int i = 0; i < dataSize; ++i) {  // for loop used to generate 20000 random integers
        tempNums = distribution(randomNums);
        int index = static_cast<int>((tempNums - rangeMin) / (rangeMax - rangeMin) * intervals);
        if (index >= 0 && index < intervals) {
            dataNums[index]++;
        }
    }
    char sym; // declaring symbol we will use to populate histogram
    printingHistogram(dataNums, rangeMin, rangeMax, sym); // calling printing method
}

int main() {
    double rangeMin; // declaring variables for the range
    double rangeMax;
    std:: cout << "Please enter a range. What is your minimum number? ";  // prompting user for input
    std:: cin >> rangeMin;
    std:: cout << "What is your maximum number? ";
    std:: cin >> rangeMax;
    createHistogram( rangeMin, rangeMax); // calling function to create the histogram
    return 0;
}






/*

 void printingHistogram( std::vector<double> dataNums ){
    char symbol = '*';
    if (dataNums.empty()){
        std:: cout << "Empty";
    }
    for ( int i = 0; i < dataNums.size(); i++ ){
        std::cout << i << " - " << i+1.0 << "|" ;
        std::cout << std::string(dataNums[i]*200.0/20000.0,'*') << std::endl;
    }
}



void createHistogram(double rangeMin, double rangeMax) {
    const int dataSize = 20000;
    const int intervals = 10;
    //const int numStars = 95;
    std::uniform_real_distribution<double> distribution(rangeMin, rangeMax);
    std::vector<double> dataNums(intervals + 1, 0);
    std::default_random_engine randomNums;
    double tempNums;
    for (int i = 0; i < dataSize; i++) {
        tempNums = distribution(randomNums);
        int position = static_cast<int>(tempNums * intervals); // Calculate index
        if (position <= intervals) {
            dataNums[position]++; // Increment the count at the calculated index
        }
    }
    printingHistogram(dataNums);
}
 */







    /* for ( int i = 0; i < dataSize; i++) {
      tempNums = distribution(randomNums);
      dataNums[int(tempNums * intervals)]++;
  }
  */
