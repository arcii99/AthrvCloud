//FormAI DATASET v1.0 Category: Educational ; Style: active
#include <stdio.h>

int main()
{
  int num1, num2, result;
  
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);
  
  if(num1 > num2)
  {
    result = num1 - num2;
    printf("%d is greater than %d and their difference is %d", num1, num2, result);
  }
  else if(num2 > num1)
  {
    result = num2 - num1;
    printf("%d is greater than %d and their difference is %d", num2, num1, result);
  }
  else
  {
    printf("Both numbers are equal");
  }
  
  return 0;
}