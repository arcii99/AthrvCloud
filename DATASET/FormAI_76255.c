//FormAI DATASET v1.0 Category: Chat server ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 5000
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* handle_client(void* arg) {
  char buffer[BUFFER_SIZE];
  int client_fd = *((int*) arg);
  int read_size;

  while ((read_size = recv(client_fd, buffer, BUFFER_SIZE, 0)) > 0) {
    buffer[read_size] = '\0';
    printf("Received message from client %d: '%s'\n", client_fd, buffer);

    pthread_mutex_lock(&mutex);
    // Send message to all clients except this one
    for (int i = 0; i < MAX_CLIENTS; i++) {
      if (clients[i] != 0 && clients[i] != client_fd) {
        send(clients[i], buffer, strlen(buffer), 0);
      }
    }
    pthread_mutex_unlock(&mutex);
  }

  // Client disconnected
  printf("Client %d disconnected\n", client_fd);

  pthread_mutex_lock(&mutex);
  // Remove client from list
  for (int i = 0; i < MAX_CLIENTS; i++) {
    if (clients[i] == client_fd) {
      clients[i] = 0;
      break;
    }
  }
  pthread_mutex_unlock(&mutex);

  close(client_fd);
  return NULL;
}

int main() {
  // Initialize clients array
  for (int i = 0; i < MAX_CLIENTS; i++) {
    clients[i] = 0;
  }

  // Create TCP socket
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    perror("socket() error");
    exit(EXIT_FAILURE);
  }

  // Bind socket to port
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
    perror("bind() error");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_fd, MAX_CLIENTS) < 0) {
    perror("listen() error");
    exit(EXIT_FAILURE);
  }

  printf("Server listening on port %d\n", PORT);

  // Accept incoming connections and create new thread for each client
  while (1) {
    int client_fd = accept(server_fd, NULL, NULL);
    if (client_fd < 0) {
      perror("accept() error");
      continue;
    }

    // Add client to list
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
      if (clients[i] == 0) {
        clients[i] = client_fd;
        break;
      }
    }
    pthread_mutex_unlock(&mutex);

    pthread_t thread;
    pthread_create(&thread, NULL, handle_client, (void*) &client_fd);
  }

  close(server_fd);
  return 0;
}