#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int key;
    cout << "Enter key to search: " << endl;
    cin >> key;
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at index: " << i;
            return 0;
        }
    }
    return 0;
}