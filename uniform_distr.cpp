#include <iostream>
#include <random>

void createHistogram(double rangeMin, double rangeMax){
    const int dataSize = 20000;
    std::uniform_real_distribution<double> distribution(rangeMin, rangeMax);
}

void printingHistogram(){

}


int main() {
    double rangeMin;
    double rangeMax;
    std:: cout << "Please enter a range. What is your minimum number? ";
    std:: cin >> rangeMin;
    std:: cout << "What is your maximum number? ";
    std:: cin >> rangeMax;

    return 0;
}




//void createHistogram( std:: vector<int> histogram, const std::vector<double>& data) {
//    double binWidth = (rangeMax - rangeMin) / numBins;
//    int dataSize = 20000;
//    std::uniform_real_distribution<double> distribution(rangeMin, rangeMax);
//}