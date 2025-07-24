//FormAI DATASET v1.0 Category: System administration ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFSIZE 1024

int main(void) {
  int proc_fd, log_fd;
  char buffer[BUFSIZE];
  ssize_t num_read;
  
  proc_fd = open("/proc/cpuinfo", O_RDONLY);
  log_fd = open("/var/log/admin.log", O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
  
  if (proc_fd == -1 || log_fd == -1) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }
  
  while ((num_read = read(proc_fd, buffer, BUFSIZE)) > 0) {
    if (write(log_fd, buffer, num_read) != num_read) {
      perror("Error writing");
      exit(EXIT_FAILURE);
    }
  }
  
  if (num_read == -1) {
    perror("Error reading");
    exit(EXIT_FAILURE);
  }
  
  if (close(proc_fd) == -1 || close(log_fd) == -1) {
    perror("Error closing file");
    exit(EXIT_FAILURE);
  }
  
  return 0;
}