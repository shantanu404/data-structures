#ifndef _linkedlist_h
#define _linkedlist_h

#include <cstdlib>

struct list_node {
    int data;
    list_node *next;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    inline size_t getSize() { return this->size; };

    void pushBack(int data);
    void pushFront(int data);
    void insertAt(size_t index, int data);

    int popBack();
    int popFront();
    int getAt(size_t index);


private:
    list_node *root;
    size_t size;
};

#endif
