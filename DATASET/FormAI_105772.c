//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int minutes = 0;
  int uptime = 0;

  srand(time(0));

  printf("Welcome to the Cyberpunk Website Uptime Monitor Program\n");
  printf("The program will monitor the uptime of your website every minute,\n");
  printf("and alert you if your website goes down\n");
  printf("Please enter the maximum uptime you want to allow (in minutes): ");
  scanf("%d", &uptime);

  while (uptime > 0) {
    int random = rand() % 100;
    if (random < 10) {
      printf("Website is down! Alert!\n");
      return 1;
    }
    uptime--;
    minutes++;
    printf("Website is up! Uptime: %d minutes\n", minutes);
    sleep(60);
  }

  printf("Maximum uptime of %d minutes reached! Program exiting...\n", minutes);
  return 0;
}