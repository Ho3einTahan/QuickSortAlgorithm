#include <iostream>
#include <string>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    // high - 1 ==> to avoid checking the pivot

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {5, 2, 12, 8, 1, 4, 2, 15, 20, 32, 9, 3, 28};

    quickSort(arr, 0, arr.size() - 1);

    for (auto i = 0; i < arr.size(); i++)
    {
        cout << arr.at(i) << " ";
    }

    cout << endl;

    return 0;
}

// g++ quickSort.cpp -o app.exe
// ./app.exe