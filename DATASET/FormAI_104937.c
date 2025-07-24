//FormAI DATASET v1.0 Category: Recursive ; Style: excited
#include<stdio.h>
#include<stdlib.h>

void recursive_function(int num) {
  if(num == 0) {
    printf("Blast off!\n");
    return;
  }
  printf("%d\n", num);
  recursive_function(num-1);
}

int main() {
  int starting_num;
  printf("Enter a starting number to countdown from: ");
  scanf("%d", &starting_num);
  printf("Starting countdown...\n");
  recursive_function(starting_num);
  printf("Countdown complete!\n");
  return 0;
}