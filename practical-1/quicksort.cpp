#include <iostream>
using namespace std;
class QuickSort
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

    int partition(int arr[], int lb, int ub)
    {
        int pivot = arr[lb];
        int start = lb;
        int end = ub;

        while (start < end)
        {
            while (arr[start] <= pivot && start < ub)
            {
                start++;
            }

            while (arr[end] > pivot)
            {
                end--;
            }

            if (start < end)
            {
                swap(arr[start], arr[end]);
            }
        }

        swap(arr[lb], arr[end]);

        return end;
    }
    void quicksort(int arr[], int lb, int ub)
    {
        if (lb < ub)
        {
            int location = partition(arr, lb, ub);

            quicksort(arr, lb, location - 1);
            quicksort(arr, location + 1, ub);
        }
    }

    void sort()
    {
        quicksort(arr, 0, n - 1);
    }
};

int main()
{
    QuickSort qs;

    qs.arrayInput();

    cout << "\nBefore Sorting: ";
    qs.printArray();

    qs.sort();

    cout << "After Sorting: ";
    qs.printArray();

    return 0;
}