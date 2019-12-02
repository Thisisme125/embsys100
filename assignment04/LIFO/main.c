//Stack Implementation -> LIFO: Last In First Out
#include <assert.h>
#include "stack.h"

int main()
{

    int testint;
    int result1;
    int result2;
    
    // *******************************************************************
    // Test1: Retrieve item from an empty queue
    // *******************************************************************
    // Arrange:
    result1 = 30;
    testint= 7;
    queue_init();
    
    // Act:
    result1 = queue_get(&testint);
      
    // Assert:
    assert(1 == result1);
    assert(7 == testint);
    
    
    // *******************************************************************
    // Test2: Successfully retrieve an item from the queue
    // *******************************************************************
    // Arrange:
    result1 = 30;
    result2 = 30;
    testint = 7;
    queue_init();
    
    // Act:
    result1 = queue_put(20);
    result2 = queue_get(&testint);
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert(20 == testint);
    
    
    // *******************************************************************
    // Test3: Fill queue, then get all items.
    // *******************************************************************
    // Arrange:
    testint = 30;
    queue_init();
    
    // Act:
    queue_put(10);
    queue_put(20);
    queue_put(30);
    queue_put(40); 
    queue_put(50); 
    
    // Assert:
    assert(0 == queue_get(&testint));
    assert(50 == testint);

    assert(0 == queue_get(&testint));
    assert(40 == testint);

    assert(0 == queue_get(&testint));
    assert(30 == testint);
    
    assert(0 == queue_get(&testint));
    assert(20 == testint);
    
    assert(0 == queue_get(&testint));
    assert(10 == testint);

   
    // *******************************************************************
    // Test4: Fill queue, then put one more item, should fail
    // *******************************************************************
    // Arrange:
    testint = 30;
    queue_init();
    
    // Act:
    queue_put(10);
    queue_put(20);
    queue_put(30);
    queue_put(40);
    queue_put(50);
    
    // Assert:
    assert(1 == queue_put(60));

    assert(0 == queue_get(&testint));
    assert(50 == testint);

    assert(0 == queue_get(&testint));
    assert(40 == testint);

    assert(0 == queue_get(&testint));
    assert(30 == testint);

    // ***********************************************************************
    // Test5: Fill queue, retrieve one item, then add item, then retrieve all, then retrieve one more (should fail)
    // ***********************************************************************
    // Arrange:
    testint = 70;
    queue_init();
    
    // Act:
    queue_put(100);
    queue_put(200);
    queue_put(300);
    queue_put(400);
    queue_put(500);

    // Assert:
    assert(0 == queue_get(&testint));
    assert(500 == testint);

    assert(0 == queue_put(1000));

    assert(0 == queue_get(&testint));
    assert(1000 == testint);

    assert(0 == queue_get(&testint));
    assert(400 == testint);

    assert(0 == queue_get(&testint));
    assert(300 == testint);
    
    assert(0 == queue_get(&testint));
    assert(200 == testint);
    
    assert(0 == queue_get(&testint));
    assert(100 == testint);
    
    assert(1 == queue_get(&testint));

    // ***********************************************************************
    // Test6: Fill queue and retrieve all items twice
    // ***********************************************************************
    // Arrange:
    testint = 70;
    queue_init();
    
    // Act:
    queue_put(50);
    queue_put(60);
    queue_put(70);
    queue_put(80);
    queue_put(90);
    
    // Assert:
    assert(0 == queue_get(&testint));
    assert(90 == testint);

    assert(0 == queue_get(&testint));
    assert(80 == testint);

    assert(0 == queue_get(&testint));
    assert(70 == testint);
    
    assert(0 == queue_get(&testint));
    assert(60 == testint);
      
    assert(0 == queue_get(&testint));
    assert(50 == testint);

    assert(0 == queue_put(60));
    assert(0 == queue_put(70));
    assert(0 == queue_put(80));
    assert(0 == queue_put(90));
    assert(0 == queue_put(100));    
    
    assert(1 == queue_put(110));

    assert(0 == queue_get(&testint));
    assert(100 == testint);
   
    assert(0 == queue_get(&testint));
    assert(90 == testint);

    assert(0 == queue_get(&testint));
    assert(80 == testint);
    
    assert(0 == queue_get(&testint));
    assert(70 == testint);
  
    assert(0 == queue_get(&testint));
    assert(60 == testint);

    assert(1 == queue_get(&testint)); 
    
 
    // ***********************************************************************
    // Test7: Fill queue, add 1 more (fail), remove 3, add 3, remove 5, add 1, remove 1, remove 1 more (fail)
    // ***********************************************************************
    // Arrange:
    testint = 100;
    queue_init();
    
    // Act:
    queue_put(1);
    queue_put(2);
    queue_put(3);
    queue_put(4);
    queue_put(5);
    assert(1 == queue_put(6));
    
    // Assert:
    assert(0 == queue_get(&testint));
    assert(5 == testint);
    
    assert(0 == queue_get(&testint));
    assert(4 == testint);
    
    assert(0 == queue_get(&testint));
    assert(3 == testint);
    
    assert(0 == queue_put(6));
    assert(0 == queue_put(7));
    assert(0 == queue_put(8));
    
    assert(0 == queue_get(&testint));
    assert(8 == testint);
    
    assert(0 == queue_get(&testint));
    assert(7 == testint);
    
    assert(0 == queue_get(&testint));
    assert(6 == testint);
    
    assert(0 == queue_get(&testint));
    assert(2 == testint);
    
    assert(0 == queue_get(&testint));
    assert(1 == testint);
    
    assert(0 == queue_put(5));
    
    assert(0 == queue_get(&testint));
    assert(5 == testint);
           
    assert(1 == queue_get(&testint)); 

  return 0;
}
