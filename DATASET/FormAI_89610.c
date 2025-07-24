//FormAI DATASET v1.0 Category: System administration ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("Welcome to the C System Administration Example Program!\n");
  while (1) {
    printf("\n");
    printf("Enter a command (type \"help\" for a list of commands):\n");
    char command[100];
    scanf("%s", command);
    if (strcmp(command, "help") == 0) {
      printf("Commands:\n");
      printf(" - ls (list files in current directory)\n");
      printf(" - pwd (print working directory)\n");
      printf(" - date (print current date and time)\n");
      printf(" - reboot (reboot the system)\n");
      printf(" - exit (exit the program)\n");
    } else if (strcmp(command, "ls") == 0) {
      system("ls");
    } else if (strcmp(command, "pwd") == 0) {
      system("pwd");
    } else if (strcmp(command, "date") == 0) {
      system("date");
    } else if (strcmp(command, "reboot") == 0) {
      printf("Are you sure you want to reboot the system? (y/n) ");
      char confirm[10];
      scanf("%s", confirm);
      if (strcmp(confirm, "y") == 0) {
        printf("Rebooting...\n");
        sleep(1);
        printf("It was a joke! The program can't really reboot your system :)\n");
      } else {
        printf("Reboot cancelled.\n");
      }
    } else if (strcmp(command, "exit") == 0) {
      printf("Goodbye!\n");
      exit(0);
    } else {
      printf("Command not found. Type \"help\" for a list of commands.\n");
    }
  }
  return 0;
}