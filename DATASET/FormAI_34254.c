//FormAI DATASET v1.0 Category: System administration ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
  int log_fd;
  pid_t pid;
  umask(0);

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  if (setsid() < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  log_fd = open("/var/log/myprogram.log", O_WRONLY | O_CREAT, 0644);
  if (log_fd < 0) {
    exit(EXIT_FAILURE);
  }

  while (1) {
    // Your program logic goes here
    // Use syslog or write to the log file
    sleep(10);
  }

  close(log_fd);

  return 0;
}