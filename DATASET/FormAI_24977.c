//FormAI DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
  pid_t pid, sid;

  // Create child process
  pid = fork();
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  // If parent process, exit
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  // Create new session and process group
  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  // Close standard file descriptors
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  // Open log file
  int logfd = open("/var/log/myprogram.log", O_RDWR | O_CREAT, 0666);
  if (logfd < 0) {
    exit(EXIT_FAILURE);
  }

  // Redirect standard file descriptors to log file
  dup2(logfd, STDIN_FILENO);
  dup2(logfd, STDOUT_FILENO);
  dup2(logfd, STDERR_FILENO);

  // Your program's main code goes here

  // Example: Log some output to log file
  printf("Hello World!\n");

  // Close log file descriptor
  close(logfd);

  // Exit program
  exit(EXIT_SUCCESS);
}