//FormAI DATASET v1.0 Category: System process viewer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main() {
  DIR* dir;
  struct dirent* ent;
  char path[256];
  int pid;

  printf("Enter process ID: ");
  scanf("%d", &pid);
  sprintf(path, "/proc/%d", pid);

  dir = opendir(path);
  if (dir == NULL) {
    printf("Process not found.\n");
    exit(EXIT_FAILURE);
  }

  printf("Process details:\n");

  while ((ent = readdir(dir)) != NULL) {
    char filename[256];
    sprintf(filename, "%s/%s", path, ent->d_name);

    FILE* fp = fopen(filename, "r");
    if (fp != NULL) {
      char line[256];
      while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
      }
      fclose(fp);
    }
  }

  closedir(dir);
  exit(EXIT_SUCCESS);
}