
// CircularQueue.cpp

#include "CircularQueue.h"
#include <stdexcept>   // include header for exceptions

using namespace std;

CircularQueue::CircularQueue(size_t size) {         // Initialize the queue with the given size
    capacity = size;
    num_items = 0;
    front_index = 0;
    rear_index = capacity - 1;                      // Initialize rear_index to the last position
    the_data = new int[capacity];
}
    

CircularQueue::~CircularQueue() {               // Destructor: Clean up any dynamically allocated memory
    delete[] the_data;
}

bool CircularQueue::empty() const {   
    return num_items == 0;
}

bool CircularQueue::full() const {
    return num_items == capacity;
}

void CircularQueue::push(int value) {
    if (num_items == capacity) {                     // Queue is full; throw an exception 
        throw exception("Queue is full. Cannot push more items.");
    }
    num_items++;
    rear_index = (rear_index + 1) % capacity;
    the_data[rear_index] = value;
}

void CircularQueue::pop() {
    if (empty()) {
        throw exception("Queue is empty. Cannot pop item");
    }
    front_index = (front_index + 1) % capacity;
    num_items--;
}

int CircularQueue::front() const {
    if (empty()) {
        throw exception("Queue is empty. Cannot show item.");
    }
    return the_data[front_index];
}

size_t CircularQueue::size() const {
    return num_items;
}

//move to rear function 
void CircularQueue::move_to_rear() {
    if (empty()) {
        throw exception("Queue is empty. Cannot move item.");
    }
    int front_element = front();
    pop();
    rear_index = (rear_index + 1) % capacity;
    the_data[rear_index] = front_element;
    num_items++;
}

CircularQueue::CircularQueue(const CircularQueue& other) {
    capacity = other.capacity;
    num_items = other.num_items;
    front_index = other.front_index;
    rear_index = other.rear_index;
    the_data = new int[capacity];
    for (size_t i = 0; i < capacity; ++i) {
        the_data[i] = other.the_data[i];
    }
}
