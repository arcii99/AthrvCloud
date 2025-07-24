//FormAI DATASET v1.0 Category: Simple Web Server ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
#define PORT 8080

int main() {
  int server_socket, client_socket;
  struct sockaddr_in server_address, client_address;
  
  // create server socket
  if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }
  
  // set server address
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);
  
  // bind server socket to address
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }
  
  // listen for incoming connections
  if (listen(server_socket, 3) < 0) {
    perror("Listen failed");
    exit(EXIT_FAILURE);
  }
  
  printf("Listening on port %d...\n", PORT);
  
  while (1) {
    unsigned int client_address_length = sizeof(client_address);
    
    // accept client connection
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length)) < 0) {
      perror("Accept failed");
      continue;
    }
    
    printf("New client connection accepted\n");
    
    char buffer[BUFFER_SIZE] = {0};
    read(client_socket, buffer, BUFFER_SIZE);
    
    // handle HTTP GET request
    printf("Received HTTP request:\n%s\n", buffer);
    char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, world!";
    
    // send HTTP response
    send(client_socket, response, strlen(response), 0);
    printf("HTTP response sent\n");
    
    close(client_socket);
    printf("Client connection closed\n");
  }
  
  return 0;
}