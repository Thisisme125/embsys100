  
void swap(int* x, int* y)
{
 int* temp = x;
 x = y;
 y = temp;
}

int main(void)
{
 int x = 1;
 int y = 2;
 swap(&x, &y);
  
 return 0;
}
