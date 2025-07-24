//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  double loadavg[3];
  while(1) {
    if (getloadavg(loadavg, 3) != -1) {
      printf("CPU Load: %.2f", loadavg[0]);
      printf("%%\n");
    } else {
      printf("Failed to get CPU load\n");
    }
    sleep(1); // wait for 1 second
  }
  return 0;
}