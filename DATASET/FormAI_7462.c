//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main()
{
  struct sysinfo si;
  int total_ram, current_ram, prev_ram = -1, threshold = 80;  //setting the initial threshold to 80%

  while(1)
  {
    if(sysinfo(&si) != 0)
    {
      printf("Error: Unable to get system statistics.\n");
      exit(1);
    }

    total_ram = si.totalram / 1024;    //converting the system's total ram in megabytes
    current_ram = (si.totalram - si.freeram) / 1024;    //out of the total ram, how much is currently used

    if(current_ram > threshold && prev_ram <= threshold)   //Alert the user only once RAM usage reaches the threshold value
    {
      printf("Warning!! RAM Usage exceeded %d%%\n", threshold);
      printf("Total RAM: %dMB, Current RAM Usage: %dMB\n\n", total_ram, current_ram);
    }

    prev_ram = current_ram;
    sleep(1);    //wait for 1 second before checking again
  }

  return 0;
}