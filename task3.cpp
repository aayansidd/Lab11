//Aayan Siddiqui
//CMS: 570014

#include <iostream>
#include <utility>
using namespace std;

struct Job {
    int id;
    int priority;
};

void siftDown(Job heap[], int size, int i) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left].priority > heap[largest].priority) {
            largest = left;
        }
        if (right < size && heap[right].priority > heap[largest].priority) {
            largest = right;
        }
        if (largest == i) {
            break;
        }

        swap(heap[i], heap[largest]);
        i = largest;
    }
}

void siftUp(Job heap[], int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[i].priority > heap[parent].priority) {
            swap(heap[i], heap[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

bool insertJob(Job heap[], int& size, int capacity, Job item) {
    if (size >= capacity) {
        return false;
    }
    heap[size] = item;
    siftUp(heap, size);
    size++;
    return true;
}

bool peekJob(const Job heap[], int size, Job& item) {
    if (size <= 0) {
        return false;
    }
    item = heap[0];
    return true;
}

bool removeJob(Job heap[], int& size, Job& item) {
    if (size <= 0) {
        return false;
    }
    item = heap[0];
    size--;
    if (size > 0) {
        heap[0] = heap[size];
        siftDown(heap, size, 0);
    }
    return true;
}

void displayHeapOrder(const Job heap[], int size) {
    cout << "--- Current Queue Contents (Heap Order, NOT Service Order) ---\n";
    if (size == 0) {
        cout << "[Empty]\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << " -> ID: " << heap[i].id
             << ", Priority: " << heap[i].priority << "\n";
    }
}

void runAutomatedTests() {
    cout << "================ AUTOMATED TEST SUITE ================\n\n";

    // 1. Empty-queue operations
    const int TEST_CAP = 4;
    Job q[TEST_CAP];
    int size = 0;
    Job out;

    cout << "[Test 1: Empty-Queue Operations]\n";
    cout << "Peek on empty queue -> " << (peekJob(q, size, out) ? "Found" : "Failed (empty)") << "\n";
    cout << "Remove on empty queue -> " << (removeJob(q, size, out) ? "Removed" : "Failed (empty)") << "\n\n";

    // 2. Main sequence: insert (101, 3), (102, 5), (103, 1), (104, 4)
    cout << "[Test 2: Insert (101, 3), (102, 5), (103, 1), (104, 4)]\n";
    Job batch1[] = {{101, 3}, {102, 5}, {103, 1}, {104, 4}};
    for (Job j : batch1) {
        bool ok = insertJob(q, size, TEST_CAP, j);
        cout << "Insert (" << j.id << ", " << j.priority << ") -> "
             << (ok ? "OK" : "FULL") << " (size = " << size << ")\n";
    }
    displayHeapOrder(q, size);
    cout << "\n";

    // 3. Attempt one insertion beyond capacity (capacity is 4, size is now 4)
    cout << "[Test 3: Overflow Insertion Beyond Capacity]\n";
    Job overflowJob{999, 10};
    bool overflowOk = insertJob(q, size, TEST_CAP, overflowJob);
    cout << "Attempt insert (" << overflowJob.id << ", " << overflowJob.priority
         << ") when size=" << size << "/capacity=" << TEST_CAP << " -> "
         << (overflowOk ? "OK" : "REJECTED (Capacity reached)") << "\n\n";

    // 4. Peek and verify size is unchanged
    cout << "[Test 4: Peek & Verify Size Unchanged]\n";
    int sizeBeforePeek = size;
    if (peekJob(q, size, out)) {
        cout << "Peeked job -> ID: " << out.id << ", Priority: " << out.priority << "\n";
    }
    cout << "Size before peek: " << sizeBeforePeek << ", Size after peek: " << size << "\n\n";

    // 5. Remove one job (check service order)
    cout << "[Test 5: Remove One Job]\n";
    if (removeJob(q, size, out)) {
        cout << "Served/Removed -> ID: " << out.id << ", Priority: " << out.priority
             << " (remaining size = " << size << ")\n";
    }
    displayHeapOrder(q, size);
    cout << "\n";

    // 6. Insert (105, 6)
    cout << "[Test 6: Insert (105, 6)]\n";
    if (insertJob(q, size, TEST_CAP, {105, 6})) {
        cout << "Inserted (105, 6) -> size = " << size << "\n";
    }
    displayHeapOrder(q, size);
    cout << "\n";

    // 7. Remove all remaining jobs in service order
    cout << "[Test 7: Remove All Remaining Jobs (Service Order)]\n";
    int step = 1;
    while (removeJob(q, size, out)) {
        cout << "Service #" << step++ << " -> ID: " << out.id
             << ", Priority: " << out.priority << " (remaining size = " << size << ")\n";
    }
    cout << "Final queue size: " << size << "\n\n";
}

void runInteractiveMenu() {
    const int CAPACITY = 10;
    Job heap[CAPACITY];
    int size = 0;
    int choice = 0;

    cout << "================ INTERACTIVE MENU ================\n";
    while (true) {
        cout << "\n1. Insert Job\n"
             << "2. Peek Highest-Priority Job\n"
             << "3. Remove Highest-Priority Job\n"
             << "4. Display Queue (Heap Order)\n"
             << "5. Exit\n"
             << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number 1-5.\n";
            continue;
        }

        if (choice == 1) {
            Job item;
            cout << "Enter Job ID and Priority: ";
            if (cin >> item.id >> item.priority) {
                if (insertJob(heap, size, CAPACITY, item)) {
                    cout << "Job inserted successfully (size = " << size << ").\n";
                } else {
                    cout << "Queue is full (max capacity = " << CAPACITY << ").\n";
                }
            }
        } else if (choice == 2) {
            Job top;
            int before = size;
            if (peekJob(heap, size, top)) {
                cout << "Highest-priority job -> ID: " << top.id
                     << ", Priority: " << top.priority
                     << " (size unchanged: " << before << " -> " << size << ")\n";
            } else {
                cout << "Queue is empty.\n";
            }
        } else if (choice == 3) {
            Job removed;
            if (removeJob(heap, size, removed)) {
                cout << "Removed job -> ID: " << removed.id
                     << ", Priority: " << removed.priority
                     << " (size = " << size << ")\n";
            } else {
                cout << "Queue is empty.\n";
            }
        } else if (choice == 4) {
            displayHeapOrder(heap, size);
        } else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid option. Choose 1 through 5.\n";
        }
    }
}

int main() {
    runAutomatedTests();
    runInteractiveMenu();
    return 0;
}