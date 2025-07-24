//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXLINE 80 // Maximum input line length
#define MAXARGS 20 // Maximum number of arguments

int main(void) {
   char line[MAXLINE]; // Input line
   char* args[MAXARGS]; // Pointers to arguments
   int status; // Child process status

   printf("MyShell > "); // Print prompt
   fflush(stdout); // Flush output buffer

   while (fgets(line, MAXLINE, stdin) != NULL) { // Read input line
      int i = 0; // Argument index
      char* token = strtok(line, " \n"); // Split input line by spaces and newlines

      while (token != NULL && i < MAXARGS - 1) { // Save tokens as arguments
         args[i] = token;
         token = strtok(NULL, " \n");
         i++;
      }

      args[i] = NULL; // Null-terminate arguments list

      if (args[0] == NULL) { // User entered no command
         printf("MyShell > ");
         fflush(stdout);
         continue; // Start again
      }

      if (strcmp(args[0], "exit") == 0) { // User entered exit command
         break;
      }

      pid_t pid = fork(); // Create new process

      if (pid == 0) { // Child process
         execvp(args[0], args); // Execute command
         perror("execvp"); // Print error message (if any)
         exit(1); // Exit child process with error code
      } else if (pid < 0) { // Fork error
         perror("fork");
      } else { // Parent process
         waitpid(pid, &status, 0); // Wait for child process to finish
      }

      printf("MyShell > "); // Print prompt
      fflush(stdout); // Flush output buffer
   }

   printf("Goodbye!\n"); // Exit message

   return 0;
}