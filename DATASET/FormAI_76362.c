//FormAI DATASET v1.0 Category: Client Server Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

// Define constants for IP address and port number
#define IP_ADDRESS "127.0.0.1"
#define PORT 8080
#define MESSAGE_BUFFER_SIZE 512

int main(int argc, char const *argv[]) {
  int socket_fd;
  struct sockaddr_in server_address;

  // Create TCP socket
  if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Socket creation failed");
    return 1;
  }

  // Assign IP address and Port number
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr(IP_ADDRESS);
  server_address.sin_port = htons(PORT);

  // Connect to server
  if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Connection failed");
    return 1;
  }

  char message[MESSAGE_BUFFER_SIZE];
  while (1) {
    // Read message from user
    printf("Enter message: ");
    fgets(message, MESSAGE_BUFFER_SIZE, stdin);
    message[strcspn(message, "\n")] = 0;

    // Send message to server
    if (send(socket_fd, message, strlen(message), 0) < 0) {
      perror("Send failed");
      return 1;
    }

    // Quit if user sends "quit"
    if (strcmp(message, "quit") == 0) {
      break;
    }

    // Receive reply from server
    char reply[MESSAGE_BUFFER_SIZE];
    if (recv(socket_fd, reply, MESSAGE_BUFFER_SIZE, 0) < 0) {
      perror("Recv failed");
      return 1;
    }

    printf("Server reply: %s\n", reply);
  }

  // Close socket
  close(socket_fd);

  return 0;
}