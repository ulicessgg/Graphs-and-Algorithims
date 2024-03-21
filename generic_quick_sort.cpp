#include <iostream>
#include "project.h"
#include <functional>

int NS_TEAM_PROJECT::partition(std::vector<NS_TEAM_PROJECT::TokenFreq> &arr, int tail, int head, std::function<bool(NS_TEAM_PROJECT::TokenFreq, NS_TEAM_PROJECT::TokenFreq)> comp)
{
    // Pick middle value as pivot.
    int midpoint = tail + (head - tail) / 2;
    auto pivot = arr[midpoint];


    // Get the leftest and right most indexes.
    int left = tail;
    int right = head;
    bool done = false;

    // While the left and right index do not cross.
    while (!done)
    {
        // Increase the left most index until the comparison fails against the pivot.
        while (comp(arr[left], pivot))
        {
            ++left;
        }

        // Decrease the right most index until the comparison fails against the pivot.
        while (comp(pivot, arr[right]))
        {
            --right;
        }
        // If the left and right indexes cross or are at the same index.
        if (left >= right)
        {
            // The partition is complete.
            done = true;
        }
        // ELSE
        else
        {
            // Swap the values of the right index and left index.
            auto temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
            ++left;
            --right;
        }
    }
    // Return the current pivot.
    return right;
}

void NS_TEAM_PROJECT::quickSort(std::vector<NS_TEAM_PROJECT::TokenFreq> &arr, int tail, int head, std::function<bool(NS_TEAM_PROJECT::TokenFreq, NS_TEAM_PROJECT::TokenFreq)> comp)
{
    //  If the left and right indexes cross or are at the same index.
    if (tail >= head)
    {
        //  The arr is sorted. Return nothing.
        return;
    }
    // Sort the full array and return the pivot position.
    int j = partition(arr, tail, head, comp);
    // Sort the lower parition, ending at the pivot.
    quickSort(arr, tail, j, comp);
    //  Sort the upper partition, starting at the value +1 the pivot.
    quickSort(arr, j + 1, head, comp);
}
