#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> temp;
    int i = start, j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= end) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++) {
        arr[start + k] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}


void displayArr(const vector<int>& arr) {
    for (int val : arr) cout << val << " ";
    cout << "\n";
}

int main() {
    vector<int> arr;
    int size;

    cout << "Enter number of elements: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        int val;
        cout << "Enter element " << i + 1 << ": ";
        cin >> val;
        arr.push_back(val);
    }

    cout << "Array before sorting: ";
    displayArr(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Array after sorting: ";
    displayArr(arr);

    return 0;
}
