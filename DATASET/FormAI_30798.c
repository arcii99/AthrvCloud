//FormAI DATASET v1.0 Category: Firewall ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Welcome message
  printf("Welcome to the Firewall program!\n");
  printf("Please enter your username: ");

  // Input username
  char username[100];
  scanf("%s", username);
  printf("Welcome, %s!\n", username);

  // Input number of IP addresses to block
  int num_blocks;
  printf("How many IP addresses would you like to block? ");
  scanf("%d", &num_blocks);

  // Input and store blocked IP addresses
  char blocked_ips[num_blocks][16]; // Maximum IP length is 15 characters
  for (int i = 0; i < num_blocks; i++) {
    printf("Enter blocked IP address #%d: ", i+1);
    scanf("%s", blocked_ips[i]);
  }

  // Request access from user
  char access_request[100];
  printf("Please enter the IP address you are requesting access from: ");
  scanf("%s", access_request);

  // Check if IP address is blocked
  int is_blocked = 0;
  for (int i = 0; i < num_blocks; i++) {
    if (strcmp(access_request, blocked_ips[i]) == 0) {
      is_blocked = 1;
      break;
    }
  }

  // Output result of access request
  if (is_blocked) {
    printf("Access denied! Your IP address has been blocked by the Firewall.\n");
  } else {
    printf("Access granted! You may proceed.\n");
  }

  return 0;
}