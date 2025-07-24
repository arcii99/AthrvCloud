//FormAI DATASET v1.0 Category: Socket programming ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
  int serverSocket, clientSocket;
  struct sockaddr_in serverAddress, clientAddress;

  // Create a socket
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket < 0) {
    printf("Error creating socket\n");
    exit(0);
  }

  // Set up the server address
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons(8080);

  // Bind the socket to the address
  if (bind(serverSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) < 0) {
    printf("Error binding socket\n");
    exit(0);
  }

  // Listen for incoming connections
  listen(serverSocket, 5);

  // Accept incoming connections
  socklen_t clientAddressLength = sizeof(clientAddress);
  clientSocket = accept(serverSocket, (struct sockaddr*) &clientAddress, &clientAddressLength);
  if (clientSocket < 0) {
    printf("Error accepting incoming connection\n");
    exit(0);
  }

  // Receive data from the client
  char buffer[256];
  bzero(buffer, 256);
  int n = read(clientSocket, buffer, 255);
  if (n < 0) {
    printf("Error reading from socket\n");
    exit(0);
  }

  // Send a response back to the client
  const char* response = "Hello client!";
  n = write(clientSocket, response, strlen(response));
  if (n < 0) {
    printf("Error writing to socket\n");
    exit(0);
  }

  // Close the sockets
  close(clientSocket);
  close(serverSocket);

  return 0;
}