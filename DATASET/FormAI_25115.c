//FormAI DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>

void gratitude(int num) {
  if(num == 1) {
    printf("Thank you!\n");
  } else {
    printf("Thank you for being a friend\n");
    gratitude(num - 1);
  }
}

int main() {
  int times = 5;
  printf("To all my users: \n\n");
  gratitude(times);
  return 0;
}