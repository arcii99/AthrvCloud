//FormAI DATASET v1.0 Category: Networking ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 3000

int main(int argc, char const *argv[]) {
  int server_fd, conn_fd;
  struct sockaddr_in server_address, client_address;
  char buffer[1024] = {0};
  const char *message = "Hello from server!";
  
  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    printf("Error creating socket!\n");
    return -1;
  }
  
  // Setting up server address
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);
  
  // Binding socket to the specified address and port
  if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    printf("Error binding socket!\n");
    return -1;
  }

  // Listening for incoming connections
  if (listen(server_fd, 3) < 0) {
    printf("Error listening for connections!\n");
    return -1;
  }
  
  printf("Server is now listening on port %d.\n", PORT);
  
  while (1) {
    socklen_t client_address_len = sizeof(client_address);
    
    // Accepting incoming connection
    if ((conn_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_len)) < 0) {
      printf("Error accepting incoming connection!\n");
      continue;
    }
    
    printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    
    int read_size;
    
    // Receiving data from client
    while ((read_size = recv(conn_fd, buffer, 1024, 0)) > 0 ) {
      printf("Received from client: %s\n", buffer);
      
      // Sending a response to client
      send(conn_fd, message, strlen(message), 0);
      
      memset(buffer, 0, sizeof(buffer)); // Clearing buffer
    }
    
    if (read_size == 0) {
      // Client disconnected
      printf("Client disconnected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    } else {
      printf("Error receiving from client!\n");
    }
  }
  
  return 0;
}