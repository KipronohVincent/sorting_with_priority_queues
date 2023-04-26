#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

class Sorter {
public:
    static void selectionSortWithPQ(int arr[], int n) {
        int smallest = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < smallest) {
                smallest = arr[i];
            }
        }
        std::priority_queue<int, std::deque<int>, std::greater<int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
        }
        for (int i = 0; i < n; i++) {
            arr[i] = pq.top();
            pq.pop();
        }
    }

    static void insertionSortWithPQ(int arr[], int n) {
        struct Element {
            int value;
            int index;
            Element(int value, int index) : value(value), index(index) {}
            bool operator>(const Element& other) const {
                return value > other.value;
            }
        };
        std::priority_queue<Element, std::deque<Element>, std::greater<Element>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(Element(arr[i], i));
        }
        for (int i = 0; i < n; i++) {
            Element e = pq.top();
            pq.pop();
            arr[i] = e.value;
        }
    }

    static void bubbleSort(int arr[], int n) {
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

    static void sort(int arr[], int n, int choice) {
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
                return;
        }
    }
};

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

    Sorter::sort(arr, n, choice);

    ofstream outfile;
    outfile.open("sorted.txt");

    for (int i = 0; i < n; i++) {
        outfile << arr[i] << " ";
    }

    outfile.close();

    cout << "Sorting completed. Output written to sorted.txt.\n";

    return 0;
}
