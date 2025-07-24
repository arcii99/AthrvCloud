//FormAI DATASET v1.0 Category: Socket programming ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
  int port = 9000;
  int server_fd, new_socket;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  char *message = "Hello client, it's the server here! Glad to meet you!";
  
  // Create socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Socket creation failed");
    return -1;
  }
  
  // Attach socket to the port
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = htonl(INADDR_ANY);
  address.sin_port = htons(port);
  
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("Bind failed");
    return -1;
  }
  
  // Listen for incoming connections
  if (listen(server_fd, 3) < 0) {
    perror("Listen failed");
    return -1;
  }
  
  // Accept incoming connections and handle them
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
    perror("Acceptance failed");
    return -1;
  }
  
  // Send a welcome message to the client
  send(new_socket, message, strlen(message), 0);
  
  // Receive data from the client
  int valread = read(new_socket, buffer, 1024);
  printf("Client: %s\n",buffer);
  
  // Send a reply to the client
  char *reply = "That's great to hear! I'm always happy to help.";
  send(new_socket, reply, strlen(reply), 0);
  
  // Close the socket
  close(new_socket);
  close(server_fd);
  
  return 0;
}