//FormAI DATASET v1.0 Category: Chat server ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

int client_sockets[MAX_CLIENTS];
pthread_t thread_id[MAX_CLIENTS];
int num_clients = 0;

void *connection_handler(void *);

int main(int argc, char const *argv[]) {
  int server_fd, new_socket;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);

  // Create server socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Allow multiple connections
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Set the address
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // Bind socket to address
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for connections
  if (listen(server_fd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  printf("Server is now listening on port %d\n", PORT);

  while (1) {
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
      perror("accept");
      exit(EXIT_FAILURE);
    }

    printf("New connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    // Add new client to array
    client_sockets[num_clients++] = new_socket;

    // Create new thread for the client
    if (pthread_create(&thread_id[num_clients-1], NULL, connection_handler, (void *)&new_socket) < 0) {
      perror("pthread_create");
      exit(EXIT_FAILURE);
    }
  }

  return 0;
}

void *connection_handler(void *socket_desc) {
  int socket = *(int *)socket_desc;
  char buffer[1024];
  int read_size;

  while ((read_size = recv(socket, buffer, 1024, 0)) > 0) {
    printf("Received message: %s\n", buffer);

    // Broadcast message to all clients
    for (int i = 0; i < num_clients; i++) {
      if (client_sockets[i] != socket) {
        write(client_sockets[i], buffer, strlen(buffer));
      }
    }

    memset(buffer, 0, sizeof(buffer)); // Reset buffer
  }

  // Remove client from array
  for (int i = 0; i < num_clients; i++) {
    if (client_sockets[i] == socket) {
      for (int j = i+1; j < num_clients; j++) {
        client_sockets[j-1] = client_sockets[j];
        thread_id[j-1] = thread_id[j];
      }
      num_clients--;
      break;
    }
  }

  printf("Client disconnected\n");
  close(socket);

  return NULL;
}