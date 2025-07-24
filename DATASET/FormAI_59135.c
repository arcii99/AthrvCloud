//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

  int ram_usage_percentage;
  char command[50];
  char buffer[1024];
  FILE* fp;

  while(1) {

    // Clear the console screen
    system("clear");

    // Get the RAM usage percentage
    fp = popen("free | awk '/^Mem:/ {print ($3 / $2)*100}'", "r");
    fgets(buffer, sizeof(buffer), fp);
    pclose(fp);
    ram_usage_percentage = atoi(buffer);

    // Print the RAM usage percentage
    printf("Current RAM usage: %d %%\n", ram_usage_percentage);

    // Show bars to represent the RAM usage percentage
    printf(" [");
    for(int i=0; i<20; i++) {
      if(i < ((ram_usage_percentage+4)/5)) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("] \n");

    // Sleep for 1 second
    sleep(1);
  }
  return 0;
}