#include <iostream>
using namespace std;

//Aayan Siddiqui
//CMS: 570014

// Prints elements on one line separated by spaces
void printArr(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i + 1 < n) cout << " "; // avoid trailing space at the end
    }
    cout << "\n";
}

// Standard bubble sort: always runs up to n - 1 passes
void bubbleSort(int arr[], int n) {
    long long comps = 0;
    long long swaps = 0;

    // 0 or 1 element is already sorted, so no passes needed
    if (n <= 1) {
        cout << "Comparisons: " << comps << ", Swaps: " << swaps << "\n";
        return;
    }

    for (int pass = 0; pass < n - 1; pass++) {
        // Last 'pass' elements are already in place, so shrink the inner loop bound
        for (int j = 0; j < n - 1 - pass; j++) {
            comps++;
            if (arr[j] > arr[j + 1]) { // swap only when left > right
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swaps++;
            }
        }
        cout << "After pass " << (pass + 1) << ": ";
        printArr(arr, n);
    }

    cout << "Comparisons: " << comps << ", Swaps: " << swaps << "\n";
}

// Optimized bubble sort: stops early if a full pass makes zero swaps
void bubbleSortOptimized(int arr[], int n) {
    long long comps = 0;
    long long swaps = 0;

    if (n <= 1) {
        cout << "Comparisons: " << comps << ", Swaps: " << swaps << "\n";
        return;
    }

    for (int pass = 0; pass < n - 1; pass++) {
        bool swapped = false;

        for (int j = 0; j < n - 1 - pass; j++) {
            comps++;
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swaps++;
                swapped = true; // mark that the array changed in this pass
            }
        }

        cout << "After pass " << (pass + 1) << ": ";
        printArr(arr, n);

        if (!swapped) {
            break; // no swaps means everything is in order
        }
    }

    cout << "Comparisons: " << comps << ", Swaps: " << swaps << "\n";
}

// Copies n elements into dest so each test starts with a fresh array
void copyArray(const int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void runCase(const string& label, const int base[], int n) {
    int work[20]; // scratch buffer; keep larger than any test array

    cout << "=== " << label << " (n = " << n << ") ===\n";

    cout << "[Standard]\n";
    copyArray(base, work, n);
    bubbleSort(work, n);

    cout << "[Optimized]\n";
    copyArray(base, work, n);
    bubbleSortOptimized(work, n);
    cout << "\n";
}

int main() {
    // Required test arrays + edge cases (duplicates, size 1, size 0)
    int c1[] = {5, 1, 4, 2, 8};
    int c2[] = {1, 2, 4, 5, 8};
    int c3[] = {8, 5, 4, 2, 1};
    int dupes[] = {4, 2, 4, 1, 2, 4};
    int single[] = {42};
    int emptyArr[1] = {};

    runCase("Unsorted", c1, 5);
    runCase("Already Sorted", c2, 5);
    runCase("Reverse Sorted", c3, 5);
    runCase("Repeated Values", dupes, 6);
    runCase("Single Element", single, 1);
    runCase("Empty Array", emptyArr, 0);

    return 0;
}