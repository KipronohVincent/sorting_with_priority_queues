#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

// Selection sort with Priority Queue

void selectionSortWithPQ(int arr[], int n) {
    // Find the smallest element in the array
    int smallest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    // Create a priority queue to hold the sorted elements
    std::priority_queue<int, std::deque<int>, std::greater<int>> pq;

    // Insert each element of the array into the priority queue
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    // Extract the sorted elements from the priority queue
    for (int i = 0; i < n; i++) {
        arr[i] = pq.top();
        pq.pop();
    }
}

// Insertion sort with Priority Queue
void insertionSortWithPQ(int arr[], int n) {
    struct Element {
        int value;
        int index;
        Element(int value, int index) : value(value), index(index) {}
        bool operator>(const Element& other) const {
            return value > other.value;
        }
    };

    // Create a priority queue to hold the sorted elements
    std::priority_queue<Element, std::deque<Element>, std::greater<Element>> pq;

    // Insert each element of the array into the priority queue
    for (int i = 0; i < n; i++) {
        pq.push(Element(arr[i], i));
    }

    // Extract the sorted elements from the priority queue
    for (int i = 0; i < n; i++) {
        Element e = pq.top();
        pq.pop();
        arr[i] = e.value;
    }
}

// Bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, choice;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Choose sorting algorithm:\n1. Selection sort with Priority Queue\n2. Insertion sort with Priority Queue\n3. Bubble sort\n";
    cin >> choice;

    switch(choice) {
        case 1:
            selectionSortWithPQ(arr, n);
            break;
        case 2:
            insertionSortWithPQ(arr, n);
            break;
        case 3:
            bubbleSort(arr, n);
            break;
        default:
            cout << "Invalid choice.\n";
            return 0;
    }

    ofstream outfile;
    outfile.open("sorted.txt");

    for (int i = 0; i < n; i++) {
        outfile << arr[i] << " ";
    }

    outfile.close();

    cout << "Sorting completed. Output written to sorted.txt.\n";

    return 0;
}
