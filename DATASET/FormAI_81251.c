//FormAI DATASET v1.0 Category: System process viewer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>

int main(){
  DIR *d;
  struct dirent *dir;
  char *stat_file_name = malloc(sizeof(char)*1024);
  char *stat_file_pointer = malloc(sizeof(char)*1024);
  
  d = opendir("/proc");
  if (d) {
    printf("%-10s \t %-10s \t %-20s \t %-10s \t %-10s\n", "PID", "PPID", "CMDLINE", "STATE", "MEMORY");
    while ((dir = readdir(d)) != NULL) {
      if (isdigit(*dir->d_name)) {
        sprintf(stat_file_name, "/proc/%s/stat", dir->d_name);
        FILE *stat_file = fopen(stat_file_name, "r");
        if(stat_file != NULL){
          fgets(stat_file_pointer, sizeof(char)*1024, stat_file);
          fclose(stat_file);
          int pid, ppid;
          char comm[1024], state, scomm[1024];
          long unsigned int rss;
          sscanf(stat_file_pointer, "%d %s %c %d %s %lu", &pid, comm, &state, &ppid, scomm, &rss);
          sprintf(stat_file_name, "/proc/%s/cmdline", dir->d_name);
          FILE *cmdline_file = fopen(stat_file_name, "r");
          char cmdline[1024];
          if(cmdline_file != NULL){
            fgets(cmdline, sizeof(cmdline), cmdline_file);
            fclose(cmdline_file);
          }
          printf("%-10d \t %-10d \t %-20s \t %-10c \t %-10lu\n", pid, ppid, cmdline, state, rss);
        }
      }
    }
    closedir(d);
  }
  free(stat_file_name);
  free(stat_file_pointer);
  return 0;
}