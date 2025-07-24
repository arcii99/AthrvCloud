//FormAI DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  
  printf("Welcome to the most unique System Administration program ever!\n\n");

  char command[100];

  printf("Please enter a command to execute: ");
  fgets(command, 100, stdin);

  printf("\nThe command you entered is: %s\n", command);

  // Check if command is valid
  if (system(command) == -1) {
    printf("\nOops! The command you entered is not valid.\n");
    return 1;
  }

  // Get system information
  printf("\n\nNow let's get some information about your system!\n\n");

  FILE *fp;
  char buffer[100];

  fp = popen("uname -a", "r");
  fgets(buffer, 100, fp);
  printf("System information: %s", buffer);
  pclose(fp);

  // Check available disk space
  fp = popen("df -h /", "r");
  fgets(buffer, 100, fp);
  if (strncmp(buffer, "Filesystem", 10) == 0) {
    fgets(buffer, 100, fp);
  }
  printf("Available disk space: %s", buffer);
  pclose(fp);

  // List all processes
  printf("\n\nNow let's take a look at all running processes:\n\n");
  system("ps aux | less");

  printf("\n\nWow, that was exciting! Thanks for using this unique System Administration program. Goodbye!\n");

  return 0;
}