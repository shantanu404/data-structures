#include <iostream>
#include <cassert>

#include <linkedlist.hpp>

#define LOG_MSG(msg) cout << msg << " @ " << __FILE__ << ":" << __LINE__ << endl;

using namespace std;
int main()
{
    LinkedList list;

    list.pushBack(1);
    list.pushBack(2);
    list.pushFront(3);

    int rc;

    rc = list.popBack();
    LOG_MSG("retuned " << rc);
    assert(rc == 2);

    rc = list.popFront();
    LOG_MSG("retuned " << rc);
    assert(rc == 3);

    rc = list.getSize();
    LOG_MSG("retuned " << rc);
    assert(rc == 1);

    rc = list.getAt(0);
    LOG_MSG("retuned " << rc);
    assert(rc == 1);

    list.setAt(0, 2); // set 1 to 2

    rc = list.popBack();
    LOG_MSG("retuned " << rc);
    assert(rc == 2);

    rc = list.getSize();
    LOG_MSG("retuned " << rc);
    assert(rc == 0);

    return 0;
}
