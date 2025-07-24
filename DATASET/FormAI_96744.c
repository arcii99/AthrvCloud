//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
  int client_socket = 0;
  struct sockaddr_in server_address;

  // Creating and initializing the client socket file descriptor
  if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Socket creation error");
    exit(1);
  }

  // Setting up the server_address structure with the IP address and port number
  memset(&server_address, '0', sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);

  if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
    perror("Invalid address/ Address not supported");
    exit(1);
  }

  // Connecting to the server
  if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Connection Failed");
    exit(1);
  }

  // Sending messages to the server
  char buffer[BUFFER_SIZE] = {0};
  printf("Enter message to send to server: ");
  fgets(buffer, BUFFER_SIZE, stdin);
  send(client_socket, buffer, strlen(buffer), 0);

  // Receiving message from server
  int valread = read(client_socket, buffer, BUFFER_SIZE);
  printf("Received message from server: %s\n", buffer);

  return 0;
}