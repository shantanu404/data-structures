#include <iostream>
#include <cassert>

#include <darray.h>

#define LOG_MSG(msg) cout << msg << " @ " << __FILE__ << ":" << __LINE__ << endl;

using namespace std;
int main()
{
    DArray list;

    list.pushBack(1);
    list.pushBack(2);
    list.pushFront(3);
    list.insertAt(1, 4);

    int rc;

    rc = list.popBack();
    LOG_MSG("retuned " << rc);
    assert(rc == 2);

    rc = list.popFront();
    LOG_MSG("retuned " << rc);
    assert(rc == 3);

    rc = list.getSize();
    LOG_MSG("retuned " << rc);
    assert(rc == 2);

    rc = list[0];
    LOG_MSG("retuned " << rc);
    assert(rc == 4);

    list[0] = 3; // change 4 to 3

    rc = list.popBack();
    LOG_MSG("retuned " << rc);
    assert(rc == 1);

    rc = list.getSize();
    LOG_MSG("retuned " << rc);
    assert(rc == 1);

    rc = list.popFront();
    LOG_MSG("returned " << rc);
    assert(rc == 3);

    return 0;
}
