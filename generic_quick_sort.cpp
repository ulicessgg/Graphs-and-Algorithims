#include <iostream>

template <typename T>
int partition(std::vector<T> &arr, int tail, int head)
{
    /* Pick middle value as pivot */
    int midpoint = tail + (head - tail) / 2;
    auto pivot = arr[midpoint];
    int left = tail;
    int right = head;
    bool done = false;

    while (!done)
    {

        while (arr[left] < pivot)
        {
            ++left;
        }

        while (pivot < arr[right])
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

template <typename T>
void quickSort(std::vector<T> &arr, int tail, int head)
{

    if (tail >= head)
    {
        return;
    }

    int j = partition(arr, tail, head);

    quickSort(arr, tail, j);
    quickSort(arr, j + 1, head);
}

int main()
{

    std::vector<int> nums = {80, 10, 20, 4343, 303, 120};
    int size = nums.size() - 1;
    quickSort(nums, 0, size);

    for (int num : nums)
    {
        std::cout << num << std::endl;
    }

    return 0;
}