// cs303hw3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "CircularQueue.h"     // Circular Queue headerfile

using namespace std;

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int recursiveLinearSearch(std::vector<int>& arr, int target, int index = 0, int lastOccurrence = -1) {
    if (index == arr.size()) {
        return lastOccurrence;
    }
    else {
        if (arr[index] == target) {
            lastOccurrence = index;
        }
        return recursiveLinearSearch(arr, target, index + 1, lastOccurrence);
    }
}


int main()
{
    CircularQueue cir_queue(10);

    //Push elements into queue
    for (int i = 10; i <= 100; i += 10) {
        try {
            cir_queue.push(i);
        }
        catch (const exception& e) {
            cerr << e.what() << '\n';
        }
    }

    // Create a copy of the queue
    CircularQueue cir_queue_copy = cir_queue;

    // Convert queue copy to vector
    vector<int> vec;
    while (!cir_queue_copy.empty()) {
        vec.push_back(cir_queue_copy.front());
        cir_queue_copy.pop();
    }

    insertionSort(vec);

    // Pop elements from the queue and print them
    while (!cir_queue.empty()) {
        try {
            std::cout << "Front element: " << cir_queue.front() << '\n';
            cir_queue.pop();
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }

    // Search for last occurrence of target in vector
    int target = 20;
    int lastOccurrence = recursiveLinearSearch(vec, target);
    if (lastOccurrence != -1) {
        cout << "The last occurrence of " << target << " is at index " << lastOccurrence << ".\n";
    }
    else {
        cout << target << " is not in the array.\n";
    }

    // Move front element to rear
    try {
        cir_queue.move_to_rear();
    }
    catch (const exception& e) {
        cerr << e.what() << '\n';
    }

   
    return 0;
}
   
    



