#include <iostream>
using namespace std;

class MaxHeap
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

    void printArray()
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void maxheapify(int arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            maxheapify(arr, n, largest);
        }
    }

    void heapsort()
    {
        // Build Max Heap
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            maxheapify(arr, n, i);
        }

        // Heap Sort
        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            maxheapify(arr, i, 0);
        }
    }
};

int main()
{
    MaxHeap mh;

    mh.arrayInput();

    cout << "\nBefore Sorting: ";
    mh.printArray();

    mh.heapsort();

    cout << "After Sorting: ";
    mh.printArray();

    return 0;
}