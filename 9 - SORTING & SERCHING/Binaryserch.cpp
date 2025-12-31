#include <iostream>
#include <vector>
using namespace std;


int binarySearch(const vector<int>& arr, int low, int high, int target);
void displayArr(const vector<int>& arr);

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << "Array: ";
    displayArr(arr);

    int target;
    cout << "Enter your target element: ";
    cin >> target;

    int idx = binarySearch(arr, 0, arr.size() - 1, target);

    if (idx != -1)
        cout << "Element found at index: " << idx << "\n";
    else
        cout << "Element not found in the array.\n";

    return 0;
}


int binarySearch(const vector<int>& arr, int low, int high, int target) {
    if (low > high) return -1; 

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearch(arr, mid + 1, high, target);
    else return binarySearch(arr, low, mid - 1, target);
}


void displayArr(const vector<int>& arr) {
    for (int val : arr) cout << val << " ";
    cout << "\n";
}
