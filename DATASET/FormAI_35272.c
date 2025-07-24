//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: medieval
#include <stdio.h>
#include <unistd.h>

int main(void) {
  double load[3];
  while (1) {
    if (getloadavg(load, 3) != -1) {
      printf("CPU Usage: %.2f%%\n", load[0]*100);
    } else {
      printf("Error while getting CPU usage\n");
    }
    sleep(1);
  }
  return 0;
}