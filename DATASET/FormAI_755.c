//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
  int pid = getpid();
  char cmd[50];
  sprintf(cmd, "ps -p %d -o %%cpu | tail -1", pid);

  while(1)
  {
    printf("Current CPU Usage: ");
    fflush(stdout);

    FILE* file = popen(cmd, "r");
    if (!file)
    {
      printf("Failed to open command\n");
      return 1;
    }

    char buffer[1024];
    fgets(buffer, 1024, file);

    pclose(file);

    printf("%s", buffer);
    fflush(stdout);

    sleep(1);
  }

  return 0;
}