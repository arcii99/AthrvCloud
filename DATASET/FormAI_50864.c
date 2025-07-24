//FormAI DATASET v1.0 Category: Recursive ; Style: bold
#include <stdio.h>

void print_numbers(int count) {
  /* base case */
  if (count == 0) {
    printf("BOLD: Reached the end of recursion\n");
    return;
  }
  
  /* recursive case */
  printf("BOLD: Count is currently %d\n", count);
  print_numbers(count - 1);
}

int main() {
  printf("BOLD: Welcome to my recursive example program!\n");
  printf("BOLD: Let's print some numbers using recursion.\n");
  
  print_numbers(10);
  
  printf("BOLD: Program complete.\n");
  return 0;
}