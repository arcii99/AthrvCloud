//FormAI DATASET v1.0 Category: Recursive ; Style: surprised
#include <stdio.h>

void recursive_function(int num) {
  if(num > 0) {
    printf("%d ", num);
    recursive_function(num - 1);
  } else {
    // Huh? Where did all the numbers go?
    printf("Wait, where did all the numbers go?\n");
    return;
  }
}

int main() {
  // Let's call the recursive function with 10 as the argument
  printf("Calling recursive function with argument 10:\n");
  recursive_function(10);
  
  // Oh no, we forgot to call the function again!
  printf("Oops, we forgot to call the function again!\n");
  
  // Let's fix that and call the function again
  printf("Calling recursive function again with argument 5:\n");
  recursive_function(5);
  
  return 0;
}