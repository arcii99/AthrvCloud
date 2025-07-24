//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/time.h>

int main() {
  double loadavg[3];
  struct tms tmsbuf;
  clock_t clktck;
  int interval; // in seconds

  // get clock ticks per second
  if ((clktck = sysconf(_SC_CLK_TCK)) < 0) {
    perror("sysconf");
    exit(EXIT_FAILURE);
  }

  // prompt user for interval
  printf("Enter monitor interval (in seconds): ");
  scanf("%d", &interval);

  printf("Monitoring CPU usage every %d seconds:\n", interval);

  while (1) {
    // get system load average
    if (getloadavg(loadavg, 3) < 0) {
      perror("getloadavg");
      exit(EXIT_FAILURE);
    }
    printf("  System load avg: %.2f %.2f %.2f\n",
           loadavg[0], loadavg[1], loadavg[2]);

    // get process CPU usage in user and system mode
    if (times(&tmsbuf) < 0) {
      perror("times");
      exit(EXIT_FAILURE);
    }
    double user_time = (double)tmsbuf.tms_utime / clktck;
    double system_time = (double)tmsbuf.tms_stime / clktck;
    printf("  Process CPU usage: user=%.2fs, system=%.2fs\n",
           user_time, system_time);

    sleep(interval);
  }

  return 0;
}