  
void swapPtr(int** Ptr1, int** Ptr2);
void swap_effective(int* x, int* y);

int main(void)
{
 int x = 1;
 int y = 2;
 int* xPtr = &x;
 int* yPtr = &y;
 
 swap_effective(&x, &y);
 swapPtr(&xPtr, &yPtr);
 return 0;
}

void swapPtr(int** Ptr1, int** Ptr2)
{
  int* tempPtr = *Ptr1;
  *Ptr1 = *Ptr2;
  *Ptr2 = tempPtr;
}

void swap_effective(int* x, int* y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}