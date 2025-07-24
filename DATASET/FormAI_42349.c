//FormAI DATASET v1.0 Category: Firewall ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *ip_address = (char*) malloc(16 * sizeof(char));
  int port_number, decision;
  printf("Welcome to the Firewall program!\n");
  printf("Enter the IP address you want to block: ");
  scanf("%s", ip_address);
  printf("Enter the port number you want to block: ");
  scanf("%d", &port_number);
  
  while (1) {
    printf("\n\n---------------------------------------------\n");
    printf("                     MENU                      \n");
    printf("---------------------------------------------\n");
    printf("[1] Block IP address\n");
    printf("[2] Unblock IP address\n");
    printf("[3] Block port number\n");
    printf("[4] Unblock port number\n");
    printf("[5] Exit\n");
    printf("---------------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &decision);

    switch (decision) {
      case 1:
        printf("IP Address %s is now blocked!", ip_address);
        break;
      case 2:
        printf("IP Address %s is now unblocked!", ip_address);
        break;
      case 3:
        printf("Port Number %d is now blocked!", port_number);
        break;
      case 4:
        printf("Port Number %d is now unblocked!", port_number);
        break;
      case 5:
        printf("Thank you for using Firewall program!");
        exit(0);
      default:
        printf("Invalid choice! Please enter a valid choice.\n");
    }
  }
  free(ip_address);
  return 0;
}