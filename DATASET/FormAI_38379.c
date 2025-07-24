//FormAI DATASET v1.0 Category: Syntax parsing ; Style: surrealist
#include<stdio.h>

void mirror(int *ptr)
{
  int a = *ptr;
  *ptr = -*ptr;
  int b = *ptr - a;
  *ptr = *ptr + b;
}

int main()
{
  printf("Enter a number: ");
  int num;
  scanf("%d", &num);

  const char str1[] = "C syntax is like a surreal dream,";
  const char str2[] = "Where brackets dance and semicolons scream.";

  printf("%s\n%s\n", str1, str2);

  if(num % 2 == 0)
  {
    printf("This number is even and logically valid.\n");
  }
  else
  {
    printf("This number is odd and nonsensical, much like C syntax.\n");
  }

  int *ptr = &num;
  mirror(ptr);

  if(num < 0)
  {
    printf("This number has been reflected in the looking glass.\n");
  }
  else
  {
    printf("This number remains unchanged, unlike C syntax.\n");
  }

  return 0;
}