//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
  pid_t pid = getpid();
  printf("PID: %d\n", (int) pid);
  char stat_path[32];
  sprintf(stat_path, "/proc/%d/stat", pid);
  FILE* stat_file = fopen(stat_path, "r");
  if (stat_file == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }
  char comm[32];
  int status = fscanf(stat_file, "%*d (%31[^)])", comm);
  if (status != 1) {
    perror("fscanf");
    exit(EXIT_FAILURE);
  }
  printf("Command: %s\n", comm);
  fclose(stat_file);
  struct rusage usage;
  if (getrusage(RUSAGE_SELF, &usage) != 0) {
    perror("getrusage");
    exit(EXIT_FAILURE);
  }
  printf("User Time: %ld.%06lds\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
  printf("System Time: %ld.%06lds\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
  printf("Max Resident Set Size: %ld KB\n", usage.ru_maxrss);
  int max_fds = sysconf(_SC_OPEN_MAX);
  printf("Max Open Files: %d\n", max_fds);
  int n_open_fds = 0;
  char fd_path[32];
  for (int fd = 0; fd < max_fds; fd++) {
    sprintf(fd_path, "/proc/%d/fd/%d", pid, fd);
    struct stat fd_stat;
    if (lstat(fd_path, &fd_stat) == 0) {
      n_open_fds++;
    }
  }
  printf("Number of Open Files: %d\n", n_open_fds);
  return EXIT_SUCCESS;
}