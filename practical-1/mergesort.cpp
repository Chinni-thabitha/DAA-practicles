#include <iostream>
using namespace std;

class MergeSort
{
public:
    int arr[100],n;
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
    void merge(int low, int mid, int high)
    {
        int temp[100];
        int i = low;
        int j = mid + 1;
        int k = low;

        while (i <= mid && j <= high)
        {
            if (arr[i] < arr[j])
            {
                temp[k] = arr[i];
                i++;
            }
            else
            {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }
        while (i <= mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        while (j <= high)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
        for (i = low; i <= high; i++)
        {
            arr[i] = temp[i];
        }
    }
    void logic(int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;
            logic(low, mid);
            logic(mid + 1, high);
            merge(low, mid, high);
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
    MergeSort ms;

    ms.arrayInput();

    cout << "Before Sorting: ";
    ms.printArray();

    ms.logic(0, ms.n - 1);

    cout << "After Sorting: ";
    ms.printArray();

    return 0;
}