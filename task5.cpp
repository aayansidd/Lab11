#include <iostream>
#include <vector>


/*
    Name: Aayan Siddiqui
    CMS: 570014
    Comparison Note:
      Selection sort always runs n*(n - 1)/2 element comparisons regardless of input
      order, making at most n - 1 swaps. Bubble sort can stop early if already sorted
      and stays stable via adjacent swaps, while heap sort runs in O(n log n) worst-case
      time without preserving equal-key order.
*/

using namespace std;

// Helper function to print the array elements cleanly
void printArray(const int arr[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i < n - 1 ? ", " : " ");
    }
    cout << "]";
}

// Helper to copy a source array into a fresh destination array
void copyArray(const int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void selectionSort(int arr[], int n) {
    int comparisons = 0;
    int swaps = 0;

    cout << "Initial array: ";
    printArray(arr, n);
    cout << "\n";

    // Edge case handling: an array of size 0 or 1 is already sorted
    if (n <= 1) {
        cout << "No passes required (n <= 1).\n";
        cout << "Total Comparisons: 0 | Total Swaps: 0\n";
        return;
    }

    // Outer loop moves the boundary of the unsorted subarray one by one
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Inner loop finds the actual minimum element in the remaining unsorted portion
        for (int j = i + 1; j < n; j++) {
            comparisons++; // Only count comparisons between array elements
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Perform a swap ONLY if the minimum element is at a different index
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }

        // Print the state of the array after each pass
        cout << "Pass " << i + 1 << ": ";
        printArray(arr, n);
        cout << "\n";
    }

    cout << "Sorted array:  ";
    printArray(arr, n);
    cout << "\nTotal Comparisons: " << comparisons << " | Total Swaps: " << swaps << "\n";
    cout << "\n";
}

int main() {
    // 1. Standard test arrays (replace values with your exact Task 4 arrays if needed)
    const int SIZE = 6;
    int unsortedOrig[SIZE] = {29, 10, 14, 37, 13, 5};
    int sortedOrig[SIZE]   = {5, 10, 13, 14, 29, 37};
    int reverseOrig[SIZE]  = {37, 29, 14, 13, 10, 5};

    int workArr[SIZE]; // Working array so original data stays untouched

    cout << "=== TEST 1: RANDOM / UNSORTED ARRAY ===\n";
    copyArray(unsortedOrig, workArr, SIZE);
    selectionSort(workArr, SIZE);

    cout << "TEST 2: ALREADY SORTED ARRAY \n";
    copyArray(sortedOrig, workArr, SIZE);
    selectionSort(workArr, SIZE);

    cout << " TEST 3: REVERSE SORTED ARRAY\n";
    copyArray(reverseOrig, workArr, SIZE);
    selectionSort(workArr, SIZE);

    // 2. Repeated values test
    cout << " TEST 4: REPEATED VALUES \n";
    int repeatedArr[] = {4, 2, 4, 1, 2, 1};
    selectionSort(repeatedArr, 6);

    // 3. Edge cases: n = 1 and n = 0
    cout << " TEST 5: SINGLE ELEMENT (n = 1) \n";
    int singleArr[] = {42};
    selectionSort(singleArr, 1);

    cout << "TEST 6: EMPTY ARRAY\n";
    int emptyArr[] = {};
    selectionSort(emptyArr, 0);

    return 0;
}