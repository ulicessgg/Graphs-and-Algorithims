#include "project.h"
#include "generic_quick_sort.cpp"
#include "norm_distr.cpp"
#include "unitTests.h"

int main()
{
    UNIT_TESTS::unitTest1_quickSort();
    UNIT_TESTS::unitTest2_quickSort();
    UNIT_TESTS::unitTest3_quickSort();
    UNIT_TESTS::unitTest1_genRandNormalDist();
    UNIT_TESTS::unitTest2_genRandNormalDist();
    UNIT_TESTS::unitTest3_genRandNormalDist();
    UNIT_TESTS::unitTest1_partition();
    UNIT_TESTS::unitTest2_partition();

    return 0;
}
