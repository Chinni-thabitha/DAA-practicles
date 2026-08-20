#include <iostream>
using namespace std;

class BinarySearch
{
public:
    int arr[100], n, key;

    void arrayInput()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter the sorted elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << "Enter the element to search: ";
        cin >> key;
    }

    void printArray()
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void search()
    {
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] == key)
            {
                cout << "Element found at index " << mid << endl;
                return;
            }
            else if (key < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << "Element not found." << endl;
    }
};

int main()
{
    BinarySearch bs;

    bs.arrayInput();

    cout << "\nArray: ";
    bs.printArray();

    bs.search();

    return 0;
}