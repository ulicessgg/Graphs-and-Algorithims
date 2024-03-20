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
void createHistogram(double rangeMin, double rangeMax){
    const int dataSize = 20000;
    const int intervals = 10;
    const int numStars = 95;
    std::uniform_real_distribution<double> distribution(rangeMin, rangeMax);
    std:: vector<double> dataNums (rangeMax + 1, 0);
    if ( rangeMax - rangeMin == 0) {
        std:: cout << "Range is equal to 0. Distribution not possible" << std:: endl;
        return;
    }
    std::default_random_engine randomNums;
    double tempNums;
    for ( int i = 0; i < dataSize; i++) {
        tempNums = distribution(randomNums);
        dataNums[int(tempNums * intervals)]++;
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

//mynums holding frequency of the values. temp holding actual values



//
//
//const int size=20000;  // number of experiments
//const int nstars=95;     // maximum number of stars to distribute
//const int nintervals=10; // number of intervals so for example 0 to 1, 1 to 2, 2 to 3 etc
//
//std::default_random_engine seed;
//std::uniform_real_distribution<double> distribution(lowerBound,upperBound);
//
//int p[nintervals]={};
//
//for (int i=0; i<size; ++i) {
//double number = distribution(generator);
//++p[int(nintervalsnumber)];
//}
//
//std::cout << std::fixed; std::cout.precision(1);
//
//for (int i=0; i<nintervals; ++i) {
//std::cout << float(i)/nintervals << "-" << float(i+1)/nintervals << ": ";
//std::cout << std::string(p[i]nstars/nrolls,'*') << std::endl;
//}
//
//



//void createHistogram( std:: vector<int> histogram, const std::vector<double>& data) {
//    double binWidth = (rangeMax - rangeMin) / numBins;
//    int dataSize = 20000;
//    std::uniform_real_distribution<double> distribution(rangeMin, rangeMax);
//}