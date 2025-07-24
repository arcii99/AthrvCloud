//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char buf[128], *cmd;
  int a, b;
  FILE *fp;
  while(1) {
    fp = fopen("/proc/stat", "r");
    fgets(buf, sizeof(buf), fp);
    fclose(fp);
    cmd = strtok(buf, " ");
    a = b = 0;
    while(cmd) {
      cmd = strtok(NULL, " ");
      if(cmd) a += atoi(cmd);
      if(!strcmp(cmd, "cpu")) b += atoi(cmd);
    }
    printf("CPU Usage: %f%%\n", ((float)b/a)*100);
    sleep(1);
  }
  return 0;
}