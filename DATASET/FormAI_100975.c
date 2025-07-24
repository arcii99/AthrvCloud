//FormAI DATASET v1.0 Category: System process viewer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
  DIR *dir;
  struct dirent *dirInfo;
  char procPath[50] = "/proc/";
  dir = opendir(procPath);
  
  while ((dirInfo = readdir(dir)) != NULL) {
    if (dirInfo->d_name[0] >= '0' && dirInfo->d_name[0] <= '9') {
      char fileName[50];
      snprintf(fileName, sizeof(fileName), "%s%s/stat", procPath, dirInfo->d_name);
      FILE *file = fopen(fileName, "r");
      
      if (file) {
        int pid;
        char comm[50] = {0};
        fscanf(file, "%d %s", &pid, comm);
        fclose(file);
        printf("PID: %d, Command: %s\n", pid, comm);
      }
    }
  }
  
  closedir(dir);
  return 0;
}