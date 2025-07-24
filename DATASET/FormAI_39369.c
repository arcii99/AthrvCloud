//FormAI DATASET v1.0 Category: Error handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  int number = 10;
  printf("Enter a number to divide 10 by: ");
  int divisor;
  scanf("%d", &divisor);
  if (divisor == 0) {
    printf("0 as a divisor? That's not allowed!\n");
    exit(1);
  }
  int result = number / divisor;
  printf("The result of the division is: %d\n", result);

  // Now let's try to access a memory location that doesn't exist
  int *p;
  *p = 10;
  printf("The value at the memory location pointed to by p is: %d\n", *p);

  // Oops, that caused a segmentation fault. Let's catch it.
  void (*pfunc)();
  pfunc = (void (*)()) NULL;
  pfunc();
  printf("You shouldn't be able to see this message because the program should have crashed already!\n");

  return 0;
}