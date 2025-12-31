#include <iostream>
#include <vector>
using namespace std;


void insertionSort(vector<int>& arr);
void displayArr(const vector<int>& arr);

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

    insertionSort(arr);

    cout << "Array after sorting: ";
    displayArr(arr);

    return 0;
}


void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int current = arr[i];
        int j = i - 1;

        
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }
}


void displayArr(const vector<int>& arr) {
    for (int val : arr) cout << val << " ";
    cout << "\n";
}
