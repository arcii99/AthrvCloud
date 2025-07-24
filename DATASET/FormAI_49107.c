//FormAI DATASET v1.0 Category: Recursive ; Style: enthusiastic
#include <stdio.h>

void recursiveFunction(int num) {
  if(num == 0) {
    printf("All done!");
  } else {
    printf("This is so exciting! We are at %d!\n", num);
    recursiveFunction(num-1);
  }
}

int main() {
  printf("Let's get started with some recursion!\n");
  printf("How many times do you want to recurse? ");
  int num;
  scanf("%d", &num);
  printf("\n");
  recursiveFunction(num);
  return 0;
}