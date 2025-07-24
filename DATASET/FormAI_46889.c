//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include <stdio.h>

void countDown(int num) {
  if (num == 0) {
    printf("Blast off!\n");
  } else {
    printf("%d..\n", num);
    countDown(num - 1);
  }
}

int main() {
  printf("Let's count down from 10!\n");
  countDown(10);
  return 0;
}