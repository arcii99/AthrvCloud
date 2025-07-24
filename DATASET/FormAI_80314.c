//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <time.h>

int main() {

  // The case of the mysterious RAM usage
  printf("It was a misty evening in London, and as I sat in my chair pondering the mysteries of the universe, I received a call from the Scotland Yard.\n");
  printf("They informed me of a peculiar case - the RAM usage of one of their machines is spiking beyond the normal range, and they have been unable to determine the cause.\n");
  printf("I accepted the case and made my way to their headquarters immediately.\n\n");

  // Gather system information
  printf("Upon arriving, I quickly got to work, gathering information about the system in question.\n");
  struct sysinfo info;
  sysinfo(&info);
  printf("Total RAM: %ld bytes\n", info.totalram);
  printf("Free RAM: %ld bytes\n\n", info.freeram);

  // Start monitoring RAM usage
  printf("After examining the system, I decided to begin monitoring the RAM usage in real-time to catch any spikes.\n");

  // Detective work
  while (1) {
    sleep(1);
    sysinfo(&info);
    time_t current_time = time(NULL);

    // Determine if RAM usage has spiked
    if (info.freeram < info.totalram / 10) {
      printf("At %s, the RAM usage spiked beyond the normal range.\n", ctime(&current_time));
      printf("Used RAM: %ld bytes\n", info.totalram - info.freeram);
      printf("Free RAM: %ld bytes\n\n", info.freeram);
    } else {
      printf("At %s, the RAM usage was within normal range.\n", ctime(&current_time));
      printf("Used RAM: %ld bytes\n", info.totalram - info.freeram);
      printf("Free RAM: %ld bytes\n\n", info.freeram);
    }
  }

  // The case is solved!
  printf("After several hours of monitoring, I finally caught the culprit - a rogue program that was consuming an excessive amount of RAM.\n");
  printf("I promptly removed the program and the RAM usage returned to normal.\n");
  printf("As usual, the case was solved by my sharp detective skills and attention to detail.\n");

  return 0;
}