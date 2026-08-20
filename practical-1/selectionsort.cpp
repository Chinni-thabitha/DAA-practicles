#include <iostream>
using namespace std;

class SelectionSort
{
public:
    int arr[100], n;
    void arrayInput()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
    void logic()
    {
        int i, j, min, temp;

        for (i = 0; i < n - 1; i++)
        {
            min = i;

            for (j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
            }
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    void printArray()
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    SelectionSort ss;

    ss.arrayInput();

    cout << "Before Sorting: ";
    ss.printArray();

    ss.logic();

    cout << "After Sorting: ";
    ss.printArray();

    return 0;
}