##  Algorithms & Data Structures

- Implementing a program prompts the user to enter the number of elements.

## Tasks :page_with_curl:

- For this programming assignment, you will implement several different sorting algorithms.
    - Selection sort with the help of a Priority Queue
    - Insertion sort with the help of a Priority Queue
    - Bubble sort however you like
    - In your main function you should read in from a file a sequence of number that are the 
        numbers to sort, the first line in your file contains a number that represent the total 
        number of lines. (you will create this file)
        You should ask the user to choose one algorithm. 
    - Redirect the output of the sorting algorithm to a .txt file
    - Exit your program
    - Each of the algorithms should print out each step of the sorting process. 

## Solution :page_with_curl:


The program starts by including the necessary `C++` standard libraries: `iostream` for `input/output`, `fstream` for file handling, and ``queue` for priority `queue` data structure. Then, the program defines three sorting functions: `selectionSortWithPQ`, `insertionSortWithPQ`, and `bubbleSort`.

The `selectionSortWithPQ` function takes an array of integers `arr` and its size `n` as input. It creates a `priority_queue` of integers `pq` with the greater comparator. Then, it iterates over the input array `arr` and inserts each element into the priority queue `pq`. After that, it iterates over the input array again and replaces each element with the top element of the priority queue `pq`. Since the greater comparator is used, the priority queue returns the smallest element first, resulting in a sorted array.

The `insertionSortWithPQ` function is almost identical to the `selectionSortWithPQ` function, except that it uses the `insert` function of the priority queue instead of pushing all elements at once. This results in a slightly different behavior of the priority queue, but the resulting sorted array is the same.

The `bubbleSort` function takes an array of integers `arr` and its size `n` as input. It uses a nested loop to compare adjacent elements of the input array and `swap` them if they are in the wrong order. This process is repeated until the array is sorted.

In the main function, the program prompts the user to enter the number of elements and the elements themselves, and stores them in an array arr. Then, it prompts the user to choose a sorting algorithm and calls the corresponding sorting function based on the user's choice. After the array is sorted, the program opens a file called `sorted.txt` for writing and writes the sorted array to it. Finally, it prints a message to the console indicating that the sorting is completed and the output is written to the file.