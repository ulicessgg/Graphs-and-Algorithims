#include <iostream>
#include <functional>
#include <cstdlib>
#include "project.h"

NS_TEAM_PROJECT::TokenFreq genKthRanked(std::vector<NS_TEAM_PROJECT::TokenFreq> &arr, int k, std::function<bool(NS_TEAM_PROJECT::TokenFreq, NS_TEAM_PROJECT::TokenFreq)> comp) {
    int left = 0;
    int right = arr.size() -1;

    while(true) {
        int pivot = std::rand() % (right - left + 1) + left;
        int new_pivot = NS_TEAM_PROJECT::partition(arr, left, right, comp);
        if(new_pivot == arr.size() - k) {
            return arr[new_pivot];
        } else if (new_pivot > arr.size() - k) {
            right = new_pivot - 1;
        } else {
            left = new_pivot + 1;
        }
    }
};
