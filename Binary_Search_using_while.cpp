#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arrSize;

    cout << "Enter size of the array: ";
    cin >> arrSize;

    int *arr = new int[arrSize];

    int i = 0;
    while (i < arrSize)
    {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
        i++;
    }

    sort(arr, arr + arrSize);

    int target;

    cout << "Enter the target element: ";
    cin >> target;

    int result = binarySearch(arr, arrSize, target);

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    delete[] arr;

    return 0;
}

// #include <iostream>
// using namespace std;

// int main()
// {
//     int arrSize;

//     cout << "Enter size of the array: ";
//     cin >> arrSize;

//     if (arrSize <= 0)
//     {
//         cout << "Invalid array size." << endl;
//         return 1;
//     }

//     int arr[arrSize];

//     cout << "Enter sorted elements of the array:" << endl;
//     for (int i = 0; i < arrSize; i++)
//     {
//         cout << "Element " << i << ": ";
//         cin >> arr[i];
//     }

//     int target;

//     cout << "Enter the target element: ";
//     cin >> target;

//     int left = 0, right = arrSize - 1;
//     int result = -1;

//     while (left <= right)
//     {
//         int mid = left + (right - left) / 2;

//         if (arr[mid] == target)
//         {
//             result = mid;
//             break;
//         }
//         else if (arr[mid] < target)
//         {
//             left = mid + 1;
//         }
//         else
//         {
//             right = mid - 1;
//         }
//     }

//     if (result != -1)
//     {
//         cout << "Element found at index: " << result << endl;
//     }
//     else
//     {
//         cout << "Element not found." << endl;
//     }

//     return 0;
// }