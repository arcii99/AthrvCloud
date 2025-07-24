//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Ken Thompson
/* Ken Thompson Style Interprocess Communication Example Program */
/* Author: YOUR_NAME_HERE */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_BUF 1024

int main()
{
  pid_t pid;
  int fd[2];
  char buf[MAX_BUF];
  int n, status;

  if (pipe(fd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    /* parent process */
    close(fd[0]); /* close the read end */

    /* write to the pipe */
    if (write(fd[1], "Hello, child process!\n", 22) == -1) {
      perror("write");
      exit(EXIT_FAILURE);
    }

    close(fd[1]); /* close the write end */

    /* wait for the child process */
    if (wait(&status) == -1) {
      perror("wait");
      exit(EXIT_FAILURE);
    }

    printf("Parent process: Child process has terminated.\n");
    exit(EXIT_SUCCESS);
  }
  else {
    /* child process */
    close(fd[1]); /* close the write end */

    /* read from the pipe */
    if ((n = read(fd[0], buf, MAX_BUF)) == -1) {
      perror("read");
      exit(EXIT_FAILURE);
    }

    printf("Child process: Received message from parent: %s\n", buf);

    close(fd[0]); /* close the read end */

    printf("Child process: Finished processing message.\n");
    exit(EXIT_SUCCESS);
  }

  return 0;
}