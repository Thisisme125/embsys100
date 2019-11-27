//Stack Implementation -> LIFO: Last In First Out
#include <assert.h>
#include "stack.h"

int main()
{

    int testint;
    // Arrange:
    queue_init();
    
    // Act:
    queue_put(7);
    queue_put(8);
    queue_put(9);
    
    // Assert:
    queue_get(&testint);
    assert(0 == queue_put(8));

  return 0;
}