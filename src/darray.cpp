#include <darray.h>
#include <cassert>

DArray::DArray()
{
    this->data = (int *)malloc(sizeof(int));
    this->used = 0;
    this->available = 1;
    this->expand_rate = 10;
}

DArray::~DArray()
{
    free(this->data);
}

void DArray::setExpandRate(size_t rate)
{
    this->expand_rate = rate;
}

void DArray::resize(size_t size)
{
    this->available = size;

    int *newdata = (int *)realloc(this->data, this->available * sizeof(int));
    if (newdata == NULL)
        assert(false && "memory error");

    this->data = newdata;
}

void DArray::pushBack(int data)
{
    if (this->used >= this->available)
        this->resize(this->used + this->expand_rate);

    this->data[this->used] = data;
    this->used ++;
}

void DArray::pushFront(int data)
{
    if (this->used >= this->available)
        this->resize(this->used + this->expand_rate);

    for (size_t x = this->used; x > 0; x --) {
        this->data[x] = this->data[x - 1];
    }
    this->data[0] = data;
    this->used ++;
}

void DArray::insertAt(size_t index, int data)
{
    if (this->used >= this->available)
        this->resize(this->used + this->expand_rate);

    for (size_t x = this->used; x > index; x --) {
        this->data[x] = this->data[x - 1];
    }
    this->data [index] = data;
    this->used ++;
}

int DArray::popBack()
{
    int rc = this->data[this->used - 1];
    this->data[this->used - 1] = 0;
    this->used --;
    return rc;
}

int DArray::popFront()
{
    int rc = this->data[0];
    for (size_t i = 1; i < this->used; i ++) {
        this->data[i - 1] = this->data[i];
    }
    this->used --;
    return rc;
}

int DArray::operator[] (size_t index) const
{
    assert(index < this->used && "index must be less than size");
    return this->data[index];
}
