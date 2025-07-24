//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define READ_END 0
#define WRITE_END 1

int main() {
  pid_t pid;
  int fd1[2], fd2[2];
  char message1[] = {"Message1 from parent process!"};
  char message2[] = {"Message2 from child process!"};
  char buffer[1024];
  int len1 = strlen(message1) + 1;
  int len2 = strlen(message2) + 1;

  if (pipe(fd1) == -1) {
    fprintf(stderr, "Pipe failed!\n");
    return 1;
  }

  if (pipe(fd2) == -1) {
    fprintf(stderr, "Pipe failed!\n");
    return 1;
  }

  pid = fork();

  if (pid < 0) {
    fprintf(stderr, "Fork failed!\n");
    return 1;
  }

  // Parent process
  if (pid > 0) {
    close(fd1[READ_END]);
    close(fd2[WRITE_END]);

    // Write to child process
    write(fd1[WRITE_END], message1, len1);

    // Read from child process
    read(fd2[READ_END], buffer, sizeof(buffer));
    printf("Received message from child process: %s\n", buffer);

    close(fd1[WRITE_END]);
    close(fd2[READ_END]);
    wait(NULL);
  }
  // Child process
  else {
    close(fd1[WRITE_END]);
    close(fd2[READ_END]);

    // Read from parent process
    read(fd1[READ_END], buffer, sizeof(buffer));
    printf("Received message from parent process: %s\n", buffer);

    // Write to parent process
    write(fd2[WRITE_END], message2, len2);

    close(fd1[READ_END]);
    close(fd2[WRITE_END]);
    _exit(0);
  }

  return 0;
}