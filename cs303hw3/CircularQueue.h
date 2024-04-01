

#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

class CircularQueue {

private:
    static const size_t DEFAULT_CAPACITY = 10;
    size_t capacity;
    size_t num_items;
    size_t front_index;
    size_t rear_index;
    int* the_data;

public:
    CircularQueue(size_t size);
    CircularQueue(const CircularQueue& other);
    ~CircularQueue();

    // Function declarations
    bool empty() const;
    bool full() const;
    void push(int value);
    void pop();
    int front() const;
    size_t size() const;
    void move_to_rear();   //move to rear function
};

#endif // CIRCULARQUEUE_H




