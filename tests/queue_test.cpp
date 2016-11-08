#include <iostream>
#include <cassert>

#include <queue.hpp>

#define LOG_MSG(msg) cout << msg << " @ " << __FILE__ << ":" << __LINE__ << endl;

using namespace std;
int main()
{
    Queue queue;

    queue.add(1);
    queue.add(2);
    queue.add(3);

    int rc;

    rc = queue.pop();
    LOG_MSG("retuned " << rc);
    assert(rc == 1);

    queue.add(4);

    rc = queue.getSize();
    LOG_MSG("retuned " << rc);
    assert(rc == 3);

    rc = queue[0];
    LOG_MSG("retuned " << rc);
    assert(rc == 2);

    queue[0] = 3; // change 2 to 3

    rc = queue.pop();
    LOG_MSG("retuned " << rc);
    assert(rc == 3);

    rc = queue.getSize();
    LOG_MSG("retuned " << rc);
    assert(rc == 2);

    rc = queue.front();
    LOG_MSG("returned " << rc);
    assert(rc == 3);

    return 0;
}
