//FormAI DATASET v1.0 Category: Chat server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8000
#define MAX_CONN 10
#define BUFFER_SIZE 1024

void handle_client(int client_socket, char* client_ip);

int main(){
  // Declare and initialize server variables
  int server_socket, client_socket;
  struct sockaddr_in server_addr, client_addr;
  char buffer[BUFFER_SIZE];

  // Create server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if(server_socket < 0){
    perror("Failed to create socket\n");
    exit(1);
  }

  // Bind socket to port and IP address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  if(bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0){
    perror("Failed to bind socket\n");
    exit(1);
  }

  // Listen for incoming connections
  if(listen(server_socket, MAX_CONN) < 0){
    perror("Failed to listen for incoming connections\n");
    exit(1);
  }

  printf("Chat server is listening on port %d\n", SERVER_PORT);

  // Accept incoming connections
  socklen_t client_size = sizeof(client_addr);
  while(1){
    client_socket = accept(server_socket, (struct sockaddr*) &client_addr, &client_size);

    if(client_socket < 0){
      perror("Failed to accept incoming connection\n");
      continue;
    }

    char* client_ip = inet_ntoa(client_addr.sin_addr);
    printf("Accepted incoming connection from %s\n", client_ip);

    handle_client(client_socket, client_ip);
  }

  close(server_socket);
  return 0;
}

void handle_client(int client_socket, char* client_ip){
  char buffer[BUFFER_SIZE];
  char client_message[BUFFER_SIZE];
  int read_size;

  // Send welcome message to client
  write(client_socket, "Welcome to the chat server!\n\n", strlen("Welcome to the chat server!\n\n"));

  while((read_size = recv(client_socket, client_message, BUFFER_SIZE, 0)) > 0){
    client_message[read_size] = '\0';

    // Check if client wants to quit the chat server
    if(strncmp(client_message, "/quit", 5) == 0){
      printf("%s has quit the chat server\n", client_ip);
      break;
    }

    // Display message from client
    printf("%s: %s", client_ip, client_message);

    // Relay message to all other connected clients
    int i;
    for(i = 0; i < MAX_CONN; i++){
      if(i != client_socket){
        write(i, client_message, strlen(client_message));
      }
    }
  }

  // Close client socket
  close(client_socket);
}