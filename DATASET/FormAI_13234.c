//FormAI DATASET v1.0 Category: Client Server Application ; Style: thoughtful
// This is a unique C Client Server Application example program that demonstrates a simple messaging app

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
  int server_fd, new_socket, val_read;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  char *hello = "Welcome to my messaging app\n";
  
  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }
  
  // Setting socket options
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt failed");
    exit(EXIT_FAILURE);
  }
  
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons( PORT );
  
  // Binding socket to port
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }
  
  // Starting listening for incoming connections
  if (listen(server_fd, 3) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }
  
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
    perror("accept failed");
    exit(EXIT_FAILURE);
  }
  
  // Send welcome message to client
  send(new_socket, hello, strlen(hello), 0);
  printf("Welcome message sent\n");
  
  while(1) {
    // Clear the buffer
    memset(buffer, 0, sizeof(buffer));
    
    // Read message from client
    val_read = read(new_socket, buffer, 1024);
    if (val_read <= 0) {
      break;
    }
    
    // Print received message
    printf("Client: %s", buffer);
    
    // Send acknowledgment to client
    send(new_socket, "Message received by server\n", strlen("Message received by server\n"), 0);
  }
  
  return 0;
}