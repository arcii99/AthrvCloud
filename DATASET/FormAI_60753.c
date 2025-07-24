//FormAI DATASET v1.0 Category: Interprocess communication ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

int main() {

   int fd[2], n;
   pid_t pid;

   char message[] = "Hello from the other side!";

   char buffer[100];

   if (pipe(fd) < 0) {
      perror("pipe()");
      exit(1);
   }

   if ((pid = fork()) < 0) {
      perror("fork()");
      exit(1);
   }

   if (pid > 0) {

      close(fd[0]);
      write(fd[1], message, strlen(message)+1);

      wait(NULL);

   } else {

      close(fd[1]);
      n = read(fd[0], buffer, sizeof(buffer));

      printf("Received message: %s\n", buffer);

   }

   return 0;
}