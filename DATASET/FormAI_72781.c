//FormAI DATASET v1.0 Category: Socket programming ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT_NUM 8080
#define BUF_SIZE 256

int main() {
  printf("=== Chat Program ===\n");

  // Create a socket for the server
  int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sockfd < 0) {
    perror("Error opening server socket");
    exit(1);
  }

  // Set up the server address structure
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY; // Listen on any interface
  server_address.sin_port = htons(PORT_NUM);

  // Bind the socket to the specified port
  if (bind(server_sockfd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
    perror("Error binding server socket");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(server_sockfd, 5) < 0) {
    perror("Error listening for connections");
    exit(1);
  }

  // Set up the client address structure
  struct sockaddr_in client_address;
  socklen_t client_address_len = sizeof(client_address);

  // Accept connections and handle messages from clients
  while (1) {
    // Accept a new client connection
    printf("Waiting for new connection...\n");
    int client_sockfd = accept(server_sockfd, (struct sockaddr*) &client_address, &client_address_len);
    if (client_sockfd < 0) {
      perror("Error accepting client connection");
      continue;
    }
    printf("Accepted new connection #%d from %s:%d\n", client_sockfd, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    // Read and send messages to/from this client
    char buf[BUF_SIZE];
    while (1) {
      // Read message from client
      memset(buf, 0, sizeof(buf));
      int len = read(client_sockfd, buf, sizeof(buf));
      if (len < 0) {
        perror("Error reading from client socket");
        break;
      } else if (len == 0) {
        printf("Connection closed by client #%d\n", client_sockfd);
        break;
      }
      printf("Client #%d sent: %s", client_sockfd, buf);

      // Send message to all other connected clients (except sender)
      for (int i = 0; i < FD_SETSIZE; i++) {
        if (i == server_sockfd || i == client_sockfd)
          continue;
        if (send(i, buf, len, 0) < 0) {
          perror("Error sending message to client");
          continue;
        }
      }
    }

    // Close the connection to this client
    close(client_sockfd);
  }

  // Close the server socket
  close(server_sockfd);

  return 0;
}