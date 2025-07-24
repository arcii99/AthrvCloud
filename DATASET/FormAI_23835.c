//FormAI DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
   int childpid, child_status;
   
   printf("My PID is %d\n", getpid());
   
   childpid = fork();
   
   if (childpid == -1) {
      perror("fork failed");
      exit(1);
   } else if (childpid == 0) {
      printf("Child process begins with PID %d\n", getpid());
      printf("Running the 'ps' command to list processes...\n");
      execl("/bin/ps", "ps", "-ef", NULL);
      perror("execl failed");
      exit(1);
   } else {
      printf("Parent process waiting for child to finish...\n");
      wait(&child_status);
      printf("Child process finished with status %d\n", WEXITSTATUS(child_status));
   }
   
   return 0;
}