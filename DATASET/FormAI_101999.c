//FormAI DATASET v1.0 Category: Recursive ; Style: retro
#include <stdio.h>

void countDown(int num) {
  if(num == 0) {
    printf("Blastoff!\n");
  } else {
    printf("%d...\n", num);
    countDown(num-1);
  }
}

int main() {
  printf("Welcome to the Retro Countdown!\n");
  printf("Enter a number to start the countdown: ");
  
  int num;
  scanf("%d", &num);
  
  printf("Counting down from %d...\n", num);
  countDown(num);
  
  printf("Thanks for traveling back in time with us!\n");
  return 0;
}