#include <iostream>
#include <cassert>

#include <stack.hpp>

#define LOG_MSG(msg) cout << msg << " @ " << __FILE__ << ":" << __LINE__ << endl;

using namespace std;
int main()
{
    Stack stack;

    stack.add(1);
    stack.add(2);
    stack.add(3);

    int rc;

    rc = stack.pop();
    LOG_MSG("retuned " << rc);
    assert(rc == 3);

    stack.add(4);

    rc = stack.getSize();
    LOG_MSG("retuned " << rc);
    assert(rc == 3);

    rc = stack[0];
    LOG_MSG("retuned " << rc);
    assert(rc == 4);

    stack[0] = 3; // change 4 to 3

    rc = stack.pop();
    LOG_MSG("retuned " << rc);
    assert(rc == 3);

    rc = stack.getSize();
    LOG_MSG("retuned " << rc);
    assert(rc == 2);

    rc = stack.peek();
    LOG_MSG("returned " << rc);
    assert(rc == 2);

    return 0;
}
