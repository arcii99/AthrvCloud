//FormAI DATASET v1.0 Category: System process viewer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void printProcessInfo(int pid) {
  char filename[30];
  char processName[50];

  sprintf(filename, "/proc/%d/cmdline", pid);
  FILE* fp = fopen(filename, "r");
  fgets(processName, 50, fp);
  fclose(fp);

  char processStatus[20];
  sprintf(filename, "/proc/%d/status", pid);
  fp = fopen(filename, "r");

  char line[256];
  while(fgets(line, 256, fp)) {
    if(strncmp(line, "State:", 6) == 0) {
      sscanf(line, "State:\t%s", processStatus);
    }
  }
  fclose(fp);

  printf("%d\t %s\t %s\n", pid, processName, processStatus);
}

int main() {
  printf("PID\t Process Name\t\t Status\n");
  printf("----------------------------------------\n");

  DIR* dir = opendir("/proc");
  struct dirent* dirEntry;

  while((dirEntry = readdir(dir)) != NULL) {
    if(!isdigit(dirEntry -> d_name[0])) continue;

    int pid = atoi(dirEntry -> d_name);
    printProcessInfo(pid);
  }
  closedir(dir);
  return 0;
}