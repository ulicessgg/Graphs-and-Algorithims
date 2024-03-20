#include <iostream>
#include <random>
#include <string>
#include <iomanip>

void printingHistogram(std::vector<int> dataNums, double rangeMin, double rangeMax)
{
    if (dataNums.empty()) {
        std::cout << "Empty";
        return;
    }
    for (int i = 0; i < dataNums.size(); ++i) {
        std::cout << (float(i) / 10)+rangeMin << "-" << (float(i + 1) / 10)+ rangeMin << ": ";
        std::cout << std::string(dataNums[i] * 400.0 / 20000.0, '*') << std::endl;
    }
}

void createHistogram(double rangeMin, double rangeMax) {
    const int dataSize = 20000;
    const int intervals = static_cast<int>(rangeMax - rangeMin) * 10;

    std::default_random_engine randomNums;
    std::uniform_real_distribution<double> distribution(rangeMin, rangeMax);

    std::vector<int> dataNums(intervals, 0);
    double tempNums = 0;

    for (int i = 0; i < dataSize; ++i) {
        tempNums = distribution(randomNums);
        int index = static_cast<int>((tempNums - rangeMin) / (rangeMax - rangeMin) * intervals);
        if (index >= 0 && index < intervals) {
            dataNums[index]++;
        }
    }
    printingHistogram(dataNums, rangeMin, rangeMax);
}

int main() {
    double rangeMin;
    double rangeMax;
    std:: cout << "Please enter a range. What is your minimum number? ";
    std:: cin >> rangeMin;
    std:: cout << "What is your maximum number? ";
    std:: cin >> rangeMax;
    createHistogram( rangeMin, rangeMax);
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
