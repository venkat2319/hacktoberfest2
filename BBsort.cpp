#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Binary Search to find the position for insertion
int binarySearch(const vector<int>& arr, int item, int low, int high) {
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == arr[mid])
        return mid + 1;

    if (item > arr[mid])
        return binarySearch(arr, item, mid + 1, high);

    return binarySearch(arr, item, low, mid - 1);
}

// Binary Insertion Sort
void binaryInsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Find location where key should be inserted
        int loc = binarySearch(arr, key, 0, j);

        // Move elements to make space for key
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nChoose sorting method:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Binary Sort (Binary Insertion Sort)\n";
    cout << "Enter choice (1 or 2): ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr);
            cout << "\nSorted using Bubble Sort:\n";
            break;
        case 2:
            binaryInsertionSort(arr);
            cout << "\nSorted using Binary Sort:\n";
            break;
        default:
            cout << "Invalid choice!\n";
            return 0;
    }

    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
