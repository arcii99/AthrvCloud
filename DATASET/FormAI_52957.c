//FormAI DATASET v1.0 Category: Socket programming ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the port number and maximum buffer size 
#define PORT 8080 
#define MAX_BUFFER_SIZE 1024 

int main(int argc, char const *argv[]) { 

  int server_socket, new_socket, valread; 
  struct sockaddr_in address; 
  int opt = 1; 
  int address_length = sizeof(address); 
  char buffer[MAX_BUFFER_SIZE] = {0}; 

  // Create the socket 
  if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
    perror("Socket creation failed");
    exit(EXIT_FAILURE); 
  } 

  // Attach the socket to the port number 
  if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
    perror("Setsockopt failed");
    exit(EXIT_FAILURE); 
  } 
  address.sin_family = AF_INET; 
  address.sin_addr.s_addr = INADDR_ANY; 
  address.sin_port = htons(PORT); 

  // Bind the socket to the IP address and port number 
  if (bind(server_socket, (struct sockaddr *)&address, sizeof(address))<0) { 
    perror("Bind failed");
    exit(EXIT_FAILURE); 
  } 

  // Listen for client connections 
  if (listen(server_socket, 3) < 0) { 
    perror("Listen failed");
    exit(EXIT_FAILURE); 
  } 
  printf("Waiting for client connections...\n");

  // Accept client connections 
  if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&address_length))<0) { 
    perror("Accept failed");
    exit(EXIT_FAILURE); 
  } 
  printf("Connection accepted from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

  // Read the message from the client 
  valread = read(new_socket, buffer, MAX_BUFFER_SIZE); 
  printf("Received message: %s\n",buffer ); 

  // Send a response back to the client 
  char* response = "I am the great detective Sherlock Holmes and I have received your message.\n"; 
  send(new_socket , response , strlen(response) , 0 ); 
  printf("Response sent\n");
  return 0; 
}