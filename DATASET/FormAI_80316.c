//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
  // Create socket
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0)
  {
    perror("Socket creation error");
    exit(EXIT_FAILURE);
  }

  // Setup server address
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);

  // Convert IPv4 and IPv6 addresses from text to binary form
  if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0)
  {
    perror("Invalid server address");
    exit(EXIT_FAILURE);
  }

  // Connect to server
  if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
  {
    perror("Could not connect to server");
    exit(EXIT_FAILURE);
  }

  printf("Connected to server\n");

  char status_message[256];
  char qoe_message[256];

  while(1)
  {
    // Send status request to server
    strcpy(status_message, "GET QOS STATUS");
    if (send(socket_fd, status_message, strlen(status_message), 0) < 0)
    {
      perror("Status message not sent");
      exit(EXIT_FAILURE);
    }

    // Receive status response from server
    memset(qoe_message, 0, 256);
    if (recv(socket_fd, qoe_message, 256, 0) < 0)
    {
      perror("Status message not received");
      exit(EXIT_FAILURE);
    }

    printf("%s\n", qoe_message);

    // Delay for 5 seconds
    sleep(5);
  }

  return 0;
}