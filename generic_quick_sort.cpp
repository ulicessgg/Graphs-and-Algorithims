#include <iostream>
#include "project.h"
#include <functional>

int NS_TEAM_PROJECT::partition(std::vector<NS_TEAM_PROJECT::TokenFreq> &arr, int tail, int head, std::function<bool(NS_TEAM_PROJECT::TokenFreq, NS_TEAM_PROJECT::TokenFreq)> comp)
{
    /* Pick middle value as pivot */
    int midpoint = tail + (head - tail) / 2;
    auto pivot = arr[midpoint];
    int left = tail;
    int right = head;
    bool done = false;

    while (!done)
    {
        while (comp(arr[left], pivot))
        {
            ++left;
        }

        while (comp(pivot, arr[right]))
        {
            --right;
        }

        if (left >= right)
        {
            done = true;
        }
        else
        {
            auto temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
            ++left;
            --right;
        }
    }
    return right;
}

void NS_TEAM_PROJECT::quickSort(std::vector<NS_TEAM_PROJECT::TokenFreq> &arr, int tail, int head, std::function<bool(NS_TEAM_PROJECT::TokenFreq, NS_TEAM_PROJECT::TokenFreq)> comp)
{

    if (tail >= head)
    {
        return;
    }

    int j = partition(arr, tail, head, comp);

    quickSort(arr, tail, j, comp);
    quickSort(arr, j + 1, head, comp);
}
