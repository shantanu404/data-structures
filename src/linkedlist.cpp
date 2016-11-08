#include <linkedlist.hpp>
#include <cassert>

LinkedList::LinkedList()
{
    this->root = NULL;
    this->size = 0;
}

LinkedList::~LinkedList()
{
    list_node *cur = this->root;
    while (cur != NULL) {
        list_node *tmp = cur->next;
        free(cur);
        cur = tmp;
    }
}

void LinkedList::pushBack(int data)
{
    list_node *node = (list_node *)malloc(sizeof(list_node));
    node->data = data;
    node->next = NULL;

    if (this->size == 0) {
        this->root = node;
    } else {
        list_node *cur = this->root;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = node;
    }
    this->size ++;
}

void LinkedList::pushFront(int data)
{
    list_node *node = (list_node *)malloc(sizeof(list_node));
    node->data = data;
    node->next = this->root;
    this->root = node;

    this->size ++;
}

int LinkedList::popBack()
{
    int rc;
    if (this->size == 0) {
        assert(false && "The list is empty");
    } else if (this->size == 1) {
        return this->popFront();
    } else {
        list_node *cur = this->root;
        while (cur->next->next != NULL) {
            cur = cur->next;
        }
        list_node *node = cur->next;
        cur->next = NULL;
        rc = node->data;
        free(node);
    }

    this->size --;
    return rc;
}

int LinkedList::popFront()
{
    int rc;
    if (this->size == 0) {
        assert(false && "The list is empty");
    } else {
        list_node *node = this->root;
        this->root = node->next;
        rc = node->data;
        free(node);
    }
    this->size --;
    return rc;
}

void LinkedList::insertAt(size_t index, int data)
{
    if (index < this->size) {
        list_node *node = (list_node *)malloc(sizeof(list_node));
        node->data = data;

        size_t i = 0;
        list_node *cur = this->root;

        while (i < index - 1) {
            cur = cur->next;
            i ++;
        }

        list_node *tmp = cur->next;
        node->next = tmp;
        cur->next = node;
    } else {
        assert(index < this->size && "index must be less than size");
    }
}

int LinkedList::getAt(size_t index)
{
    int rc;
    if (index < this->size) {
        size_t i = 0;
        list_node *cur = this->root;

        while (i < index) {
            cur = cur->next;
            i ++;
        }

        rc = cur->data;
    } else {
        assert(index < this->size && "index must be less than size");
    }

    return rc;
}

void LinkedList::setAt(size_t index, int data)
{
    if (index < this->size) {
        size_t i = 0;
        list_node *cur = this->root;

        while (i < index) {
            cur = cur->next;
            i ++;
        }

        cur->data = data;
    } else {
        assert(index < this->size && "index must be less than size");
    }
}
