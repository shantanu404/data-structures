#ifndef _darray_h
#define _darray_h

#include <cstdlib>

class DArray {
public:
    DArray();
    ~DArray();

    inline size_t getSize() { return this->used; };

    void resize(size_t size);
    void setExpandRate(size_t rate);

    void pushBack(int data);
    void pushFront(int data);
    void insertAt(size_t index, int data);

    int popBack();
    int popFront();

    int &operator[] (size_t index);

private:
    int *data;
    size_t used;
    size_t available;
    size_t expand_rate;
};

#endif
