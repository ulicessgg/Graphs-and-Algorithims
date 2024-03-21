#include <iostream>
#include <functional>
#include <cstdlib>
#include "project.h"

// function to generate the kth ranked object
NS_TEAM_PROJECT::TokenFreq genKthRanked(std::vector<NS_TEAM_PROJECT::TokenFreq> &arr, int k, std::function<bool(NS_TEAM_PROJECT::TokenFreq, NS_TEAM_PROJECT::TokenFreq)> comp) {
    int left = 0;
    int right = arr.size() -1;
    
    // Loop until the kth ranked object is found
    while(true) {
	// select a random pivot
        int pivot = std::rand() % (right - left + 1) + left;
        // partition array around the pivot
	int new_pivot = NS_TEAM_PROJECT::partition(arr, left, right, comp);
        
	// if the pivot is the kth ranked object, return it
	if(new_pivot == arr.size() - k) {
            return arr[new_pivot];
	// search the left side
        } else if (new_pivot > arr.size() - k) {
            right = new_pivot - 1;
        // search the right side
	} else {
            left = new_pivot + 1;
        }
    }
}
