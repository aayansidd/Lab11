//Aayan Siddiqui
// CMS: 570014

#include <utility>
#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i +1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i ) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 -1; i>= 0; i--) {
        maxHeapify(arr,n,i);
    }
}

void heapsort(int arr[], int n) {
    int root = 0;
    // buildMaxHeap(arr, n); since I already am passing build max heaps
    for (int i = n - 1; i >= 1; i--) {
        swap(arr[root], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main() {
    int myarr[] = {35, 12, 43, 8, 51, 27, 19};
    int n = 7;
    buildMaxHeap(myarr, n);
    heapsort(myarr, n);
    for (int i = 0; i < n; i++ ) {
        cout << myarr[i] << endl;
    }
}
