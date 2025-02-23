#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    string ch;
    do
    {
        cout << "Enter the number you want to search: ";
        cin >> target;

        int result = binarySearch(arr, size, target);

        if (result != -1)
        {
            cout << "Element found at index " << result << endl;
        }
        else
        {
            cout << "Element not found in the array" << endl;
        }
        cout << "Do You Want To Continue (No to Exit): " << endl;
        cin >> ch;

    } while (ch == "Yes" || ch == "yes");

    return 0;
}
