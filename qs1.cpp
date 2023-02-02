#include <iostream>
using namespace std;
int partition(int arr[], int biggest, int smallest)
{
    int pivot = arr[biggest];
    int count = 0;
    for (int i = biggest + 1; i <= smallest; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }
    int x = biggest + count;
    swap(arr[x], arr[biggest]);
    int i = biggest, j = smallest;
    while (i < x && j > x)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < x && j > x)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return x;
}

void quickSort(int arr[], int biggest, int smallest)
{
    if (biggest >= smallest)
        return;
    int p = partition(arr, biggest, smallest);
    quickSort(arr, biggest, p - 1);
    quickSort(arr, p + 1, smallest);
}
void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 8, 5, 3, 0, 1,10 };
    int n = 6;
    cout << " The array before QuickSort is: \n";
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    cout << " The array after QuickSort is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}