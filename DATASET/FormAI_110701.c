//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIGNAL 100
#define MIN_SIGNAL 0

int main() {
  srand(time(NULL));
  int signal_strength = rand() % (MAX_SIGNAL + 1 - MIN_SIGNAL) + MIN_SIGNAL;
  printf("Wi-Fi Signal Strength: %d\n", signal_strength);
  
  if (signal_strength >= 80) {
    printf("Signal strength is excellent!\n");
  } else if (signal_strength >= 60 && signal_strength < 80) {
    printf("Signal strength is good.\n");
  } else if (signal_strength >= 40 && signal_strength < 60) {
    printf("Signal strength is fair.\n");
  } else if (signal_strength >= 20 && signal_strength < 40) {
    printf("Signal strength is poor.\n");
  } else {
    printf("Signal strength is very poor.\n");
  }
  
  return 0;
}