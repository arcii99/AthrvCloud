//FormAI DATASET v1.0 Category: System process viewer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(void) {
  DIR *dir;
  struct dirent *ent;
  char proc_path[256], filename[256];
  FILE *fp;

  if ((dir = opendir("/proc")) != NULL) {
    /* print all the files and directories within directory */
    while ((ent = readdir(dir)) != NULL) {
      /* Check if directory entry is a process directory */
      if (isdigit(*ent->d_name)) {
        /* Generate path of process's stat file */
        snprintf(proc_path, sizeof proc_path, "/proc/%s/stat", ent->d_name);
        /* Open the stat file */
        if ((fp = fopen(proc_path, "r")) != NULL) {
          /* Read in process name and PID */
          fscanf(fp, "%*d %s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %lu", filename);
          /* Close the file */
          fclose(fp);
          /* Print process name and PID */
          printf("Process: %s (%s)\n", filename, ent->d_name);
        }
      }
    }
    closedir(dir);
  }
  else {
    /* could not open directory */
    perror("Error: could not open directory");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}