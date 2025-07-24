//FormAI DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
  int option;
  char command[50];
  
  printf("Welcome to the System Administration Program.\n");
  do {
    printf("\nEnter an option:\n1. View system status\n2. Check system logs\n3. Run a command\n4. Exit\n");
    scanf("%d", &option);
    
    switch(option) {
      case 1:
        system("top"); // displays the system status
        break;
      
      case 2:
        system("tail /var/log/syslog -n 20"); // displays the last 20 lines of the system log
        break;
      
      case 3:
        printf("\nEnter a command to run: ");
        scanf("%s", command);
        system(command); // runs the user-inputted command
        break;
        
      case 4:
        printf("\nExiting System Administration Program...\n");
        break;
        
      default: // if an invalid option is entered
        printf("\nInvalid option. Please enter a number from 1-4.\n");
        break;
    }
  } while(option != 4);
  
  return 0;
}