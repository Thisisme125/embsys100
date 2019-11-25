//Define queue size
#define QUEUE_SIZE 4

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
  if (putPtr == 0)
  {
    putPtr = &QueueStore[0];
    getPtr = putPtr;
    *putPtr = data;
    putPtr++;
    return 0;
  }
  
    *putPtr = data;
    putPtr++;
    getPtr++;
    return 0;
}

int queue_get(int* data)
{
  if (getPtr == 0)
  {
    //Queue is empty
    return 1;
  }
  else 
  {
    *data = *getPtr;
    getPtr--;
    putPtr--;
  }
  
  
  
  return 1;
}


/*



// Add data to queue
// If queue is full return error
// Otherwise return success
int queue_put(int data)
{
    if (getPtr == &QueueStore[0] && putPtr == &QueueStore[QUEUE_SIZE-1])
    {
        // queue is full
        return -1;
    }
    
    if (getPtr == putPtr+1)
    {
        //queue is full
        return -1;
    }
    
    if (getPtr == 0)
    {
        getPtr = &QueueStore[0];
    }    
    
    if (putPtr == 0 || putPtr == &QueueStore[QUEUE_SIZE-1])
    {
        putPtr = &QueueStore[0];
    }
    else
    {
        putPtr++;
    }
    
    *putPtr = data;
    return 0;
}

// Get data from queue
// If queue is empty return error
// Otherwise return success
int queue_get(int* data)
{   
    if (getPtr == 0)
    {
        // queue is empty
        return -1;
    }

    *data = *getPtr;
    
    if (getPtr == putPtr)
    {
        
        getPtr = 0;
        putPtr = 0;
    }
    else if (getPtr == &QueueStore[QUEUE_SIZE-1])
    {
        // wrap
        getPtr = &QueueStore[0];
    }
    else
    {
        getPtr++;
    }
    
    return 0;
}
*/
