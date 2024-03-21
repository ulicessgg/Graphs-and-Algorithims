#include <iostream>
#include "project.h"
#include <functional>

namespace NS_TEAM_PROJECT
{
    template <typename T>
    int partition(std::vector<T> &arr, int tail, int head, std::function<bool(T, T)> comp)
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
    template <typename T>
    void quickSort(std::vector<T> &arr, int tail, int head, std::function<bool(T, T)> comp)
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
}