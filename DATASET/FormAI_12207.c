//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define SERVER_PORT 8080

void handle_client(int client_socket, struct sockaddr_in client_address) {
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("Failed to create socket");
    exit(1);
  }
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(80);
  if(inet_pton(AF_INET, "www.google.com", &server_address.sin_addr) <= 0) {
    perror("Invalid IP address / Address not supported");
    exit(1);
  }
  if (connect(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
    perror("Failed to connect to server");
    exit(1);
  }
  char buffer[2048]; // Buffer to store HTTP request or response
  int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("Failed to receive from client");
    exit(1);
  }
  printf("Received from client: %.*s\n", bytes_received, buffer);
  if (send(server_socket, buffer, bytes_received, 0) == -1) {
    perror("Failed to send to server");
    exit(1);
  }
  bytes_received = recv(server_socket, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("Failed to receive from server");
    exit(1); 
  }
  printf("Received from server: %.*s\n", bytes_received, buffer);
  if (send(client_socket, buffer, bytes_received, 0) == -1) {
    perror("Failed to send to client");
    exit(1);
  }
  close(server_socket);
  close(client_socket);
}

int main() {
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("Failed to create socket");
    exit(1);
  }
  struct sockaddr_in server_address, client_address;
  memset(&server_address, 0, sizeof(server_address));
  memset(&client_address, 0, sizeof(client_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(SERVER_PORT);
  server_address.sin_addr.s_addr = INADDR_ANY;
  if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
    perror("Failed to bind socket");
    exit(1);
  }
  if (listen(server_socket, 10) == -1) {
    perror("Failed to listen to socket");
    exit(1);
  }
  socklen_t client_length = sizeof(client_address);
  while(1) {
    int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_length);
    if (client_socket == -1) {
      perror("Failed to accept client connection");
      exit(1);
    }
    printf("Accepted connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    pid_t pid = fork();
    if (pid == -1) {
      perror("Failed to fork");
      exit(1);
    } else if (pid == 0) { // Child process
      handle_client(client_socket, client_address);
      exit(0);
    } else { // Parent process
      close(client_socket);
    }
  }
  close(server_socket);
  return 0;
}