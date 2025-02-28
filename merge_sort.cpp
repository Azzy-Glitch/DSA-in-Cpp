#include <iostream>
#include <vector>

// Function to merge two sorted subarrays
void merge(std::vector<int> &arr, int left, int mid, int right)
{
    // Size of the left subarray
    int n1 = mid - left + 1; 
    // Size of the right subarray
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into the original array
    // Initial index of the first subarray
    int i = 0;
    // Initial index of the second subarray
    int j = 0;
    // Initial index of the merged subarray
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Main function that sorts arr[left...right] using merge()
void mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Utility function to print the array
void printArray(const std::vector<int> &arr)
{
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Given array is \n";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "\nSorted array is \n";
    printArray(arr);

    return 0;
}