//FormAI DATASET v1.0 Category: System administration ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int choice;

  do {
    // Prompt the user for a choice
    printf("Enter a number to perform a system operation\n");
    printf("1. Check system uptime\n");
    printf("2. List currently running processes\n");
    printf("3. Reboot the system (Requires root access)\n");
    printf("4. Exit program\n");
    scanf("%d", &choice);

    // Perform the chosen operation
    switch (choice) {
      case 1:
        // Execute the 'uptime' command
        system("uptime");
        break;

      case 2:
        // Fork a new process to execute the 'ps' command
        int pid;
        pid = fork();

        if (pid == 0) {
          // Child process
          execl("/bin/ps", "ps", "-ef", NULL);
        } else if (pid > 0) {
          // Parent process
          wait(NULL); // Wait for child process to complete
        } else {
          // Fork failed
          printf("Fork failed\n");
        }
        break;

      case 3:
        // Reboot the system, requires root access
        printf("WARNING: This will reboot the system. Are you sure? (y/n)\n");
        char confirm;
        scanf(" %c", &confirm);

        if (confirm == 'y' || confirm == 'Y') {
          printf("Rebooting...\n");
          system("sudo reboot");
        } else {
          printf("Cancelled reboot.\n");
        }
        break;

      case 4:
        // Exit the program
        printf("Exiting program.\n");
        exit(0);
        break;

      default:
        // Invalid choice
        printf("Invalid choice. Please try again.\n");
        break;
    }
  } while (1);

  return 0;
}