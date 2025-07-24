//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: realistic
#include<stdio.h>

int main()
{
  int n, i, count = 0, flag = 0;
  
  printf("Enter an integer: ");
  scanf("%d", &n);
  
  printf("Prime numbers from 1 to %d are: ", n);
  
  for(i=2; i<=n; ++i)
  {
    flag = 0;
    
    for(int j=2; j<i; ++j)
    {
      if(i%j == 0)
      {
        flag = 1;
        break;
      }
    }
    
    if(flag == 0)
    {
      printf("%d ", i);
      ++count;
    }
  }
  
  printf("\nTotal prime numbers found: %d", count);
  
  return 0;
}