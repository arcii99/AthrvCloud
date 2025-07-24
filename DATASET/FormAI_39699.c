//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // seed random number generator
  int uptime = rand() % 100; // generate a random uptime between 0 and 100

  while(1) { // infinite loop to monitor website uptime
    if(uptime <= 50) {
      printf("The website is down!\n");
    } else {
      printf("The website is up!\n");
    }
    sleep(5); // wait for 5 seconds before checking website uptime again
    uptime = rand() % 100; // generate a new random uptime value
  }
  return 0;
}