//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 // maximum length of command output

int main()
{
  int percent_ram_used = 0;
  char command[MAX_LEN];
  FILE *fp;

  while(1) // infinitely loop to monitor RAM usage continuously
  {
    sprintf(command, "free | grep Mem | awk '{printf \"%%.0f\", $3/$2 * 100}'"); // command to get the percentage of RAM used
    fp = popen(command, "r"); // run the command and get its output

    if(fp == NULL) // handle error if command failed to run
    {
      printf("Error: Failed to run command\n");
      return 1;
    }

    fgets(command, MAX_LEN, fp); // read the output of the command into the buffer
    percent_ram_used = atoi(command); // convert the output from string to integer

    pclose(fp); // close the command output stream

    printf("Current RAM usage: %d%%\n", percent_ram_used); // display the percentage of RAM used

    sleep(1); // delay for 1 second before checking again
  }

  return 0;
}