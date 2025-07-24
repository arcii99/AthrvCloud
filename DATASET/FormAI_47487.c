//FormAI DATASET v1.0 Category: Client Server Application ; Style: beginner-friendly
// C Client Server Application Example
// This program demonstrates socket programming in C.
// The server listens for connections from clients and sends back a message to the client.
// The client connects to the server, sends a message and receives a response from the server.

// Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Constants
#define SERVER_PORT 5000
#define MAX_MSG_SIZE 1024

// Main function
int main(int argc, char *argv[]) {
  // Variables
  int sock;
  struct sockaddr_in server_addr;
  char message[MAX_MSG_SIZE], server_reply[MAX_MSG_SIZE];

  // Create socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Could not create socket");
    return 1;
  }
  printf("Socket created\n");

  // Set server address
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);

  // Connect to server
  if (connect(sock , (struct sockaddr *)&server_addr , sizeof(server_addr)) < 0) {
    perror("Connect failed. Error");
    return 1;
  }
  printf("Connected to server\n");

  // Send data to server
  printf("Enter message: ");
  fgets(message, MAX_MSG_SIZE, stdin); // Get user input
  message[strcspn(message, "\n")] = '\0'; // Remove newline character
  if (send(sock, message, strlen(message), 0) < 0) {
    printf("Send failed");
    return 1;
  }
  printf("Message sent: %s\n", message);

  // Receive data from server
  if (recv(sock, server_reply, MAX_MSG_SIZE, 0) < 0) {
    printf("Receive failed");
    return 1;
  }
  printf("Server reply: %s\n", server_reply);

  // Close socket
  close(sock);
  return 0;
}