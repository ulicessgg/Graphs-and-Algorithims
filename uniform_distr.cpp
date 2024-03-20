#include <iostream>
#include <random>
#include <string>
#include <iomanip>

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
    /* if ( rangeMax - rangeMin == 0) {
         std:: cout << "Range is equal to 0. Distribution not possible" << std:: endl;
         return;
     } */
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


    /* for ( int i = 0; i < dataSize; i++) {
      tempNums = distribution(randomNums);
      dataNums[int(tempNums * intervals)]++;
  }
  */
