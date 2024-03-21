#include "project.h"
#include "generic_quick_sort.cpp"
#include "norm_distr.cpp"
#include "unitTests.h"

int main()
{
    UNIT_TESTS::unitTest1_quickSort();
    UNIT_TESTS::unitTest2_quickSort();
    UNIT_TESTS::unitTest3_quickSort();
    UNIT_TESTS::unitTest1_partition();
    UNIT_TESTS::unitTest2_partition();

     if (!UNIT_TESTS::unitTest1_genRandNormalDist())
     std::cout << "unitTest1_genRandNormalDist failed!\n";
     if (!UNIT_TESTS::unitTest2_genRandUniformDist())
         std::cout << "unitTest2_genRandUniformDist failed!\n";
     if (!UNIT_TESTS::unitTest3_genRandUniformDist())
         std::cout << "unitTest3_genRandUniformDist failed!\n";
     if (!UNIT_TESTS::unitTest1_calcNormalHistStats())
         std::cout << "unitTest1_calcNormalHistStats failed!\n";
     if (!UNIT_TESTS::unitTest2_calcNormalHistStats())
         std::cout << "unitTest2_calcNormalHistStats failed!\n";
     if (!UNIT_TESTS::unitTest1_printNormalHist())
         std::cout << "unitTest1_printNormalHist failed!\n";
     if (!UNIT_TESTS::unitTest2_printNormalHist())
         std::cout << "unitTest2_printNormalHist failed!\n";
     
     std::vector<int> userNums;
     int userMean;
     int userSD;
     char userSym;
    
     std::cout << "Enter mean: ";
     std::cin >> userMean;
     std::cout << "Enter standard deviation: ";
     std::cin >> userSD;
     std::cout << std::endl;
    
     NS_TEAM_PROJECT::genRandNormalDist(userNums, userMean, userSD);
     NS_TEAM_PROJECT::calcNormalHistStats(userNums, userMean, userSD);
     NS_TEAM_PROJECT::printNormalHist(userNums, userSym, userMean);


    return 0;
}



