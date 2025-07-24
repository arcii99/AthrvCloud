//FormAI DATASET v1.0 Category: Firewall ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  // Initializing variables
  char userInput[50];
  int i, j, k, l, m;

  // Gathering user input
  printf("Enter password: ");
  fgets(userInput, sizeof(userInput), stdin);

  // Looping through password to encrypt it
  for (i = 0; i < sizeof(userInput); i++) {
    userInput[i] = userInput[i] + 3;
  }

  // Initializing firewall rules
  char *allowedIPs[4] = {"192.168.0.1", "192.168.0.2", "192.168.0.3", "192.168.0.4"};
  char *blockedIPs[3] = {"10.0.0.1", "10.0.0.2", "10.0.0.3"};
  char *allowedPorts[2] = {"80", "443"};

  // Initializing variables for user input
  char userIP[15];
  char userPort[5];

  // Looping through IP and port to check if they match rules
  while (1) {
    // Gathering user input for IP and port
    printf("Enter IP address: ");
    fgets(userIP, sizeof(userIP), stdin);

    printf("Enter port number: ");
    fgets(userPort, sizeof(userPort), stdin);

    // Looping through allowedIPs
    for (j = 0; j < sizeof(allowedIPs); j++) {
      if (strcmp(userIP, allowedIPs[j]) == 0) {
        // If IP address is allowed, loop through allowedPorts
        for (k = 0; k < sizeof(allowedPorts); k++) {
          if (strcmp(userPort, allowedPorts[k]) == 0) {
            // If IP address and port number are both allowed, allow access
            printf("Access granted.\n");
            exit(0);
          }
        }
        // If IP address is allowed but port number is not, block access
        printf("Port blocked.\n");
        exit(0);
      }
    }

    // Looping through blockedIPs
    for (l = 0; l < sizeof(blockedIPs); l++) {
      if (strcmp(userIP, blockedIPs[l]) == 0) {
        // If IP address is blocked, block access
        printf("IP address blocked.\n");
        exit(0);
      }
    }

    // If IP address is not allowed or blocked, deny access
    printf("Access denied.\n");
  }

  return 0;
}