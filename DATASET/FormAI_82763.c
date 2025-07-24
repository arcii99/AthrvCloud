//FormAI DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {

   pid_t pid1, pid2;
   int status1, status2;
   
   // Forking the first child process
   pid1 = fork();
   
   if (pid1 == 0) {
      printf("Child process 1 has started with process ID: %d\n", getpid());
      printf("Executing the command \"ls -la\"\n");
      char* args[] = {"ls", "-la", NULL};
      execvp(args[0], args);
   }
   else if (pid1 > 0) {
      printf("Parent process has called the first child with ID: %d\n", pid1);
      waitpid(pid1, &status1, 0);
      printf("First child finished with status code: %d\n", status1);
   }
   else {
      printf("Error while forking first child!\n");
      exit(1);
   }
   
   // Forking the second child process
   pid2 = fork();
   
   if (pid2 == 0) {
      printf("Child process 2 has started with process ID: %d\n", getpid());
      printf("Executing the command \"ps -ef\"\n");
      char* args[] = {"ps", "-ef", NULL};
      execvp(args[0], args);
   }
   else if (pid2 > 0) {
      printf("Parent process has called the second child with ID: %d\n", pid2);
      waitpid(pid2, &status2, 0);
      printf("Second child finished with status code: %d\n", status2);
   }
   else {
      printf("Error while forking second child!\n");
      exit(1);
   }
   
   printf("Parent process has finished execution\n");

   return 0;
}