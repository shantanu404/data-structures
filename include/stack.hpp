#ifndef _stack_h
#define _stack_h

#include <darray.hpp>

class Stack {
public:
    Stack() { this->arr = new DArray(); }
    ~Stack() { delete this->arr; }

    inline void add(int data) { this->arr->pushFront(data); }
    inline int peek() { return (*(this->arr))[0]; }
    inline int pop() { return this->arr->popFront(); }

    inline int getSize() { return this->arr->getSize(); }

    int &operator[] (size_t index) { return (*(this->arr))[index]; }
private:
    DArray *arr;
};

#endif
