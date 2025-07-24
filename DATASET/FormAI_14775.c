//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define URL_MAX_LENGTH 255

int main(void) {

  char url[URL_MAX_LENGTH];
  int timeout;
  int downtime = 0;

  printf("Welcome to the Surrealist Website Uptime Monitor\n");
  printf("Please enter the website URL: ");
  scanf("%s", url);
  printf("Please enter the timeout in seconds: ");
  scanf("%d", &timeout);

  printf("Initiating website monitoring...\n");

  while(1) {

    sleep(timeout);

    // Generate a random failure
    srand(time(NULL));
    int failure = rand() % 10;
    if(failure == 0) {
      printf("ERROR: Website is temporarily down.\n");
      downtime += timeout;
    }
    else {
      printf("SUCCESS: Website is up and running.\n");
    }

    // Print out the total downtime so far
    int minutes = downtime / 60;
    int seconds = downtime % 60;
    printf("Total downtime so far: %d minutes %d seconds.\n", minutes, seconds);

  }

  return 0;
}