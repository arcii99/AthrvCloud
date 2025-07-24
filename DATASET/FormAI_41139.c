//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFLEN 1024

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <ip address>\n", argv[0]);
    return -1;
  }

  // Create a raw socket to listen to all traffic
  int sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);

  // Set socket option to receive all packages
  int enable = 1;
  if (setsockopt(sock_raw, IPPROTO_IP, IP_HDRINCL, &enable, sizeof(enable)) < 0) {
    printf("Error setting IP_HDRINCL option.\n");
    return -1;
  }

  // Define the address we want to listen to
  struct sockaddr_in my_addr;
  my_addr.sin_family = AF_INET;
  my_addr.sin_addr.s_addr = inet_addr(argv[1]);
  my_addr.sin_port = 0;

  // Bind our socket to the address
  if (bind(sock_raw, (struct sockaddr *)&my_addr, sizeof(my_addr)) < 0) {
    printf("Error binding socket.\n");
    return -1;
  }

  // Start listening for packets
  printf("Monitoring network traffic...\n");
  while (1) {
    char buffer[BUFLEN];
    struct sockaddr_in client_addr;
    int client_addr_len = sizeof(client_addr);

    // Receive a packet
    int packet_len = recvfrom(sock_raw, buffer, BUFLEN, 0, (struct sockaddr *)&client_addr, &client_addr_len);
    if (packet_len < 0) {
      printf("Error receiving packet.\n");
      continue;
    }

    // Print packet information
    printf("Received %d byte packet from %s:%d\n", packet_len, inet_ntoa(client_addr.sin_addr), htons(client_addr.sin_port)); 
    printf("Packet contents:\n");

    // Print packet contents as hex
    for (int i = 0; i < packet_len; i++) {
      printf("%02x ", (unsigned char)buffer[i]);
    }
    printf("\n\n");
  }

  return 0;
}