//FormAI DATASET v1.0 Category: Chat server ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
  printf("Welcome to the surreal chat server!\n\n");
  
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(7777);
  server_address.sin_addr.s_addr = INADDR_ANY;
  
  bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
  
  listen(server_socket, 10);
  
  printf("Waiting for clients to connect...\n\n");
  
  int client_socket = accept(server_socket, NULL, NULL);
  
  printf("Client connected! Start chatting!\n\n");
  
  char message[256];
  
  while(1)
  {
    printf("Enter a message: ");
    fgets(message, 256, stdin);
    send(client_socket, message, sizeof(message), 0);
    
    recv(client_socket, message, sizeof(message), 0);
    printf("Client says: %s", message);
  }
  
  return 0;
}