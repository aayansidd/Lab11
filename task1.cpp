//Aayan Siddiqui
//CMS: 570014

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

int main() {
    // 1. Main array
    int myarr[] = {35, 12, 43, 8, 51, 27, 19};
    int n = 7;
    buildMaxHeap(myarr, n);

    cout << "Main array heap:" << endl;
    for (int i = 0; i < n; i++) {
        cout << myarr[i] << endl;
    }
    for (int i = 0; i <= n / 2 - 1; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && myarr[i] < myarr[left]) {
            cout << "Violation at parent " << myarr[i] << " and left child " << myarr[left] << endl;
        }
        if (right < n && myarr[i] < myarr[right]) {
            cout << "Violation at parent " << myarr[i] << " and right child " << myarr[right] << endl;
        }
    }
    cout << "Main array parent-child check" << endl << endl;

    // 2. Empty array (n = 0)
    int* emptyArr = nullptr;
    int emptyN = 0;
    buildMaxHeap(emptyArr, emptyN);

    cout << "Empty array heap:" << endl;
    for (int i = 0; i < emptyN; i++) {
        cout << emptyArr[i] << endl;
    }
    for (int i = 0; i <= emptyN / 2 - 1; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < emptyN && emptyArr[i] < emptyArr[left]) {
            cout << "Violation at parent " << emptyArr[i] << " and left child " << emptyArr[left] << endl;
        }
        if (right < emptyN && emptyArr[i] < emptyArr[right]) {
            cout << "Violation at parent " << emptyArr[i] << " and right child " << emptyArr[right] << endl;
        }
    }
    cout << "Empty array parent-child check" << endl << endl;

    // 3. Single element
    int singleArr[] = {42};
    int singleN = 1;
    buildMaxHeap(singleArr, singleN);

    cout << "Single element heap:" << endl;
    for (int i = 0; i < singleN; i++) {
        cout << singleArr[i] << endl;
    }
    for (int i = 0; i <= singleN / 2 - 1; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < singleN && singleArr[i] < singleArr[left]) {
            cout << "Violation at parent " << singleArr[i] << " and left child " << singleArr[left] << endl;
        }
        if (right < singleN && singleArr[i] < singleArr[right]) {
            cout << "Violation at parent " << singleArr[i] << " and right child " << singleArr[right] << endl;
        }
    }
    cout << "Single element parent-child check" << endl << endl;

    // 4. Repeated values
    int dupArr[] = {10, 20, 10, 30, 20, 30, 5};
    int dupN = 7;
    buildMaxHeap(dupArr, dupN);

    cout << "Repeated values heap:" << endl;
    for (int i = 0; i < dupN; i++) {
        cout << dupArr[i] << endl;
    }
    for (int i = 0; i <= dupN / 2 - 1; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < dupN && dupArr[i] < dupArr[left]) {
            cout << "Violation at parent " << dupArr[i] << " and left child " << dupArr[left] << endl;
        }
        if (right < dupN && dupArr[i] < dupArr[right]) {
            cout << "Violation at parent " << dupArr[i] << " and right child " << dupArr[right] << endl;
        }
    }
    cout << "Repeated values parent-child check" << endl;

    return 0;
}