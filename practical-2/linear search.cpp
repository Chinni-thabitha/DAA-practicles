#include <iostream>
using namespace std;

class LinearSearch
{
public:
    int arr[100], n, key;

    void arrayInput()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter the elements: ";
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
        int i;

        for (i = 0; i < n; i++)
        {
            if (arr[i] == key)
            {
                cout << "Element found at index " << i << endl;
                break;
            }
        }

        if (i == n)
        {
            cout << "Element not found." << endl;
        }
    }
};

int main()
{
    LinearSearch ls;

    ls.arrayInput();

    cout << "\nArray: ";
    ls.printArray();

    ls.search();

    return 0;
}