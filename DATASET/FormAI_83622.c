//FormAI DATASET v1.0 Category: System process viewer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
  DIR* dir;
  struct dirent* entry;
  char* proc_path = "/proc";
  
  // Open the proc filesystem directory
  dir = opendir(proc_path);
  if (dir == NULL) {
    perror("opendir");
    exit(EXIT_FAILURE);
  }

  // Iterate through the directories in the proc filesystem
  while ((entry = readdir(dir)) != NULL) {
    // Check if the entry is a directory (i.e. a process ID)
    if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
      int pid = atoi(entry->d_name);
      
      // Print the process ID, name, and status
      char pid_stat_path[1024];
      sprintf(pid_stat_path, "%s/%d/status", proc_path, pid);
      FILE* pid_stat_file = fopen(pid_stat_path, "r");
      char line[1024], name[1024], status[1024];
      while (fgets(line, sizeof(line), pid_stat_file)) {
        if (sscanf(line, "Name:\t%s\n", name) == 1);
        if (sscanf(line, "State:\t%s\n", status) == 1);
      }
      fclose(pid_stat_file);
      printf("%d %s %s\n", pid, name, status);
    }
  }

  // Close the proc filesystem directory
  closedir(dir);

  return 0;
}