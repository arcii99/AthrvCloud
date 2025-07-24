//FormAI DATASET v1.0 Category: Interprocess communication ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

#define BUFF_SIZE 50
#define MESSAGE "Hello, world!"

void sender(int readfd, int writefd) {
  char buffer[BUFF_SIZE];

  strcpy(buffer, MESSAGE);
  write(writefd, buffer, sizeof(buffer));
  printf("[SENDER] Sent message to receiver.\n");

  close(readfd);  
  close(writefd);
  
  exit(EXIT_SUCCESS);
}

void receiver(int readfd, int writefd) {
  char buffer[BUFF_SIZE];

  read(readfd, buffer, sizeof(buffer));
  printf("[RECEIVER] Received message: %s\n", buffer);

  close(readfd);  
  close(writefd);
  
  exit(EXIT_SUCCESS);
}

int main() {
  int fd1[2], fd2[2];
  pid_t childpid;

  if (pipe(fd1) == -1 || pipe(fd2) == -1) {
    perror("Failed to create pipes");
    exit(EXIT_FAILURE);
  }

  childpid = fork();
  if (childpid == -1) {
    perror("Failed to fork()");
    exit(EXIT_FAILURE);
  }

  if (childpid == 0) {
    // Child process (receiver)
    close(fd1[1]);         // Close unused write end
    close(fd2[0]);         // Close unused read end
    receiver(fd1[0], fd2[1]);
  } else {
    // Parent process (sender)
    close(fd1[0]);         // Close unused read end
    close(fd2[1]);         // Close unused write end
    sender(fd2[0], fd1[1]);
  }

  wait(NULL);
  exit(EXIT_SUCCESS);
}