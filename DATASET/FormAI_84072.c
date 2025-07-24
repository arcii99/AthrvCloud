//FormAI DATASET v1.0 Category: Recursive ; Style: happy
#include <stdio.h>

void happyCountdown(int num) {
  if (num == 0) {
    printf("YAY! HAPPY NEW YEAR!!\n");
    return;
  }

  printf("Countdown: %d...\n", num);
  happyCountdown(num - 1);
  
  printf("HAPPY %d!\n", num);
}

int main() {
  printf("Ready to count down?\n");
  happyCountdown(10);

  return 0;
}