#ifndef _queue_h
#define _queue_h

#include <darray.hpp>

class Queue {
public:
    Queue() { this->arr = new DArray(); }
    ~Queue() { delete this->arr; }

    inline void add(int data) { this->arr->pushBack(data); }
    inline int front() { return (*(this->arr))[0]; }
    inline int pop() { return this->arr->popFront(); }

    inline int getSize() { return this->arr->getSize(); }

    int &operator[] (size_t index) { return (*(this->arr))[index]; }
private:
    DArray *arr;
};

#endif
