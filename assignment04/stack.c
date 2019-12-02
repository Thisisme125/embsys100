//Code by Omar Mahmoud

//Define queue size
#define QUEUE_SIZE 5

//Backing Store
int QueueStore[QUEUE_SIZE];

//Pointers to queue elements for adding and retrieving
int* putPtr;
int* getPtr;


//Initialize Queue Internals
void queue_init(void)
{
    putPtr = 0;
    getPtr = 0;
    
    for (int x = 0; x < QUEUE_SIZE; x++)
    {
      QueueStore[x] = '\0';
    }
    
}


//Add data to queue
int queue_put(int data)
{
  //Check it pointing at first space in stack
  if (putPtr == 0)
  {
    //Put data in first space in stack, increment put pointer by 1, and set get pointer to the first space in the stack
    putPtr = &QueueStore[0];
    getPtr = putPtr;
    *putPtr = data;
    putPtr++;
    return 0;
  }
  
  //Test if Queue is Full
  if (getPtr == &QueueStore[QUEUE_SIZE - 1])
      {
        //Queue is Full
        return 1;
      }
  
  //If currently pointing at the end of the stack, insert data but do not increment pointer beyond Queue size
  if (putPtr == &QueueStore[QUEUE_SIZE - 1])
  {
    getPtr++;
    *putPtr = data;
  }
  
  //Put data in current location, increment put and get pointers by 1.
  else
  {
    *putPtr = data;
    getPtr++;
    putPtr++;
  }

    return 0;
}

int queue_get(int* data)
{
  //Check if queue is empty
  if (getPtr == 0)
  {
    //Queue is empty
    return 1;
  }
  
  // get data from queue
   *data = *getPtr;
  
  //test if get pointer is at first place in queue
  if (getPtr == &QueueStore[0])
  {
    //Reset pointers
    getPtr = 0;
    putPtr = 0;
  }
  
  //test if get pointer is at end of queue size
  else if (getPtr == &QueueStore[QUEUE_SIZE - 1])
  {
    //Decrement get pointer by 1 but leave put pointer at end of stack
    getPtr--;
  }
  
  //Decrease get and put pointers by 1
  else
  {
   getPtr--;
   putPtr--;
  }
  
  return 0;
}