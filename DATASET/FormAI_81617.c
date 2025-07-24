//FormAI DATASET v1.0 Category: Firewall ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main()
{
  char packet[100], firewall[10] = "Block"; // Initializing a packet and a firewall
  int packetSize, port; // Initializing packet size and port number
  printf("\nWelcome to the Happy Firewall!\n"); // Cheerful welcome message
  printf("\nEnter packet size: "); 
  scanf("%d", &packetSize); // Getting user input for packet size
  printf("\nEnter port number: ");
  scanf("%d", &port); // Getting user input for port number
  printf("\nEnter packet content: ");
  scanf("%s", packet); // Getting user input for packet content

  // Checking if packet size is too large
  if (packetSize > 50) {
    printf("\nPacket size is too large. Firewall is %s.", firewall); // Cheerful firewall message
    return 0; // Ending the program
  }

  // Checking if port number is blocked
  if (port == 80 || port == 8080) {
    strcpy(firewall, "Block"); // Setting firewall to block
  } else {
    strcpy(firewall, "Allow"); // Setting firewall to allow
  }

  // Checking if packet contains harmful content
  if (strstr(packet, "virus") != NULL || strstr(packet, "malware") != NULL) {
    strcpy(firewall, "Block"); // Setting firewall to block
  }

  printf("\nFirewall is %s. Have a happy day!", firewall); // Cheerful final message
  return 0; // Ending the program
}