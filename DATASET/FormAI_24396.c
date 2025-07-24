//FormAI DATASET v1.0 Category: Recursive ; Style: shocked
#include <stdio.h>

void recursive_function(int n) {
  if (n <= 0) {
    printf("What?! You want me to do recursion?!\n");
    return;
  } else {
    printf("Ok, fine! I will do recursion.\n");
    recursive_function(n-1);
    printf("I hate recursion! Especially %d times!\n", n);
  }
}
  
int main(void) {
  printf("Are you ready for some recursion?\n");
  printf("Enter a positive integer: ");
  
  int n;
  scanf("%d", &n);
  
  printf("Alright, let's do this!\n");
  recursive_function(n);
  printf("Finally, it's over.\n");
  
  return 0;
}