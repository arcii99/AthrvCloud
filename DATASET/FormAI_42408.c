//FormAI DATASET v1.0 Category: Firewall ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BLOCKED_IPS 1000 // maximum number of blocked IP addresses
#define MAX_IP_LENGTH 16 // maximum length of an IP address

// function to check if a given IP address is blocked
int is_blocked(char blocked_ips[BLOCKED_IPS][MAX_IP_LENGTH], char* ip_address) {
  for(int i=0; i<BLOCKED_IPS; i++) {
    if(strcmp(blocked_ips[i], ip_address) == 0) {
      return 1; // IP address is blocked
    }
  }
  return 0; // IP address is not blocked
}

int main() {
  char blocked_ips[BLOCKED_IPS][MAX_IP_LENGTH]; // array to store blocked IP addresses
  int num_blocked_ips = 0; // number of currently blocked IP addresses
  char input_ip[MAX_IP_LENGTH]; // user input for IP address

  while(1) { // infinite loop: keeps prompting user for input until they exit the program
    printf("Enter an IP address (or 'exit' to quit): ");
    fgets(input_ip, MAX_IP_LENGTH, stdin); // read user input from command line
    input_ip[strcspn(input_ip, "\n")] = 0; // remove newline character

    if(strcmp(input_ip, "exit") == 0) { // user wants to exit the program
      printf("\nGoodbye!\n");
      exit(0); // exit program
    }

    if(is_blocked(blocked_ips, input_ip) == 1) { // IP address is already blocked
      printf("This IP address is already blocked.\n");
    } else { // IP address is not yet blocked
      strcpy(blocked_ips[num_blocked_ips], input_ip); // add IP address to list of blocked IPs
      printf("IP address has been blocked.\n");
      num_blocked_ips++; // increment number of blocked IPs
    }
  }

  return 0;
}