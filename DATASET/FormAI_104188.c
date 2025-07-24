//FormAI DATASET v1.0 Category: Chat server ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10

typedef struct {
  int socket_fd;
  struct sockaddr_in address;
  char username[20];
} client_t;

int client_count = 0;
client_t clients[MAX_CLIENTS];

void *handle_client(void *args) {
  int client_id = *(int *)args;
  char buffer[1024];
  char username[20];

  // Get the username of the client
  if (recv(clients[client_id].socket_fd, username, sizeof(username), 0) <= 0) {
    printf("Client %d disconnected\n", client_id);
    close(clients[client_id].socket_fd);
    pthread_exit(NULL);
  } else {
    strcpy(clients[client_id].username, username);
    printf("Client %d connected from %s:%d (%s)\n", client_id,
           inet_ntoa(clients[client_id].address.sin_addr),
           ntohs(clients[client_id].address.sin_port),
           username);
  }

  while (1) {
    memset(buffer, '\0', sizeof(buffer));
    
    // Receive message from client
    if (recv(clients[client_id].socket_fd, buffer, sizeof(buffer), 0) <= 0) {
      printf("Client %d disconnected\n", client_id);
      close(clients[client_id].socket_fd);
      pthread_exit(NULL);
    }

    // Send message to all other clients
    for (int i = 0; i < client_count; i++) {
      if (i != client_id && clients[i].socket_fd != 0) {
        char msg[1024];
        sprintf(msg, "%s: %s", clients[client_id].username, buffer);
        send(clients[i].socket_fd, msg, strlen(msg), 0);
      }
    }
  }
}

int main() {
  int server_fd, client_fd;
  struct sockaddr_in server_address, client_address;
  pthread_t thread_id;

  // Create server socket
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == -1) {
    printf("Could not create server socket\n");
    return 1;
  }

  // Configure server address
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(9999);

  // Bind server socket to address
  if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    printf("Could not bind server to address\n");
    return 1;
  }

  // Listen for connections
  if (listen(server_fd, 3) < 0) {
    printf("Could not listen for connections\n");
    return 1;
  }

  printf("Server started on port 9999\n");

  while (1) {
    printf("Waiting for connections...\n");

    // Accept incoming connections
    int client_size = sizeof(client_address);
    client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&client_size);
    if (client_fd < 0) {
      printf("Could not accept connection\n");
      continue;
    }

    // Add new client to array
    clients[client_count].socket_fd = client_fd;
    clients[client_count].address = client_address;

    // Spawn a new thread to handle the client
    pthread_create(&thread_id, NULL, handle_client, (void *)&client_count);
    pthread_detach(thread_id);

    // Increment client count
    client_count++;
  }

  return 0;
}