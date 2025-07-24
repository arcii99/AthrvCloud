//FormAI DATASET v1.0 Category: Recursive ; Style: introspective
#include <stdio.h>

// Function declaration
void recursiveFunction(int num);

int main()
{
  int num;
  
  printf("Enter a number: ");
  scanf("%d", &num);
  
  // Function call
  recursiveFunction(num);
  
  return 0;
}

// Recursive function definition
void recursiveFunction(int num) {
  if (num == 0) {
    printf("Bored of recursion now\n");
    return;
  } else {
    printf("Feeling recursive with %d\n", num);
    recursiveFunction(num - 1);
  }
}