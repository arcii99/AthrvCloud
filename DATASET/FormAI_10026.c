//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int x = 1;
  while (x) {
    int y = rand() % 101;
    printf("CPU Usage: %d%%\n", y);
    sleep(1);
    if (y >= 90) {
      printf("CPU overload detected! Terminating...\n");
      x = 0;
    }
  }
  return 0;
}