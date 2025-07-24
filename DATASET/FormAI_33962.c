//FormAI DATASET v1.0 Category: System process viewer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main() {
  DIR *dp;
  struct dirent *ep;
  dp = opendir ("/proc/"); // open the /proc directory
  if (dp != NULL) {
    printf("PID\tPPID\tSTATE\tCMD\n"); // print table header
    while ((ep = readdir(dp))) { // while iterating through /proc
      int pid = atoi(ep->d_name);
      if (pid == 0) continue; // ignore non-numeric filenames
      char filename[256];
      snprintf(filename, sizeof(filename), "/proc/%d/status", pid); // build path to process file
      FILE *file = fopen(filename, "r"); 
      if (file) {
        char line[256];
        char state[3];
        int ppid = 0;
        char cmd[256];
        while (fgets(line, sizeof(line), file)) { // read lines from process file
          if (strncmp(line, "PPid:", 5) == 0) {
            ppid = atoi(line + 6);
          } else if (strncmp(line, "State:", 6) == 0) {
            sscanf(line + 7, "%c", &state[0]);
            state[1] = '\0';
          } else if (strncmp(line, "Name:", 5) == 0) {
            strncpy(cmd, line + 6, sizeof(cmd));
            cmd[sizeof(cmd) - 1] = '\0';
            char *pos = strchr(cmd, '\n');
            if (pos) *pos = '\0';
          }
        }
        fclose(file);
        if (ppid > 0) {
          printf("%d\t%d\t%s\t%s\n", pid, ppid, state, cmd); // print process info
        }
      }
    }
    closedir(dp);
  }
  return 0;
}