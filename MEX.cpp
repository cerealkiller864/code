#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int start, int end) {
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quick(vector<int>& arr, int start, int end) {
    if (start < end) {
        int pivotIndex = partition(arr, start, end);

        quick(arr, start, pivotIndex - 1);
        quick(arr, pivotIndex + 1, end);
    }
}

int find_mex(vector<int> arr)
{
    int size = arr.size();
    quick(arr, 0, size-1);

    int mex = 0;
    for (int i = 0; i < size ; i++)
    {
        if (mex == arr[i])
            mex++;
        else
            return mex;
    }

    return mex;
}


int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i < n ;i++)
    {
        cin >> arr[i];
    }

    cout << find_mex(arr);

    return 0;
}