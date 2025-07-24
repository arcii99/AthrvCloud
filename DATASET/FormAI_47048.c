//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int uptime = rand() % 101;
  char *message;

  if (uptime < 50) {
    message = "Website is down! Code red!";
  } else if (uptime < 75) {
    message = "Website is experiencing issues. Code yellow.";
  } else {
    message = "Website is up and running. Code green.";
  }

  printf("%s\n", message);
  printf("Current uptime: %d%%\n", uptime);

  return 0;
}