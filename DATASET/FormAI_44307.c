//FormAI DATASET v1.0 Category: Socket programming ; Style: complete
// This program is a simple chat server using sockets.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void broadcast(char *message, int sender) {
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < client_count; i++) {
    if (clients[i] != sender) {
      send(clients[i], message, strlen(message), 0);
    }
  }
  pthread_mutex_unlock(&mutex);
}

void *handle_client(void *arg) {
  int client_socket = *(int *)arg;
  char buffer[BUFFER_SIZE] = {0};
  while (recv(client_socket, buffer, BUFFER_SIZE, 0) != 0) {
    broadcast(buffer, client_socket);
    memset(buffer, 0, BUFFER_SIZE);
  }
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < client_count; i++) {
    if (clients[i] == client_socket) {
      clients[i] = clients[client_count - 1];
      client_count--;
      break;
    }
  }
  pthread_mutex_unlock(&mutex);
  close(client_socket);
  return NULL;
}

int main(int argc, char *argv[]) {
  int server_socket, client_socket;
  struct sockaddr_in server_addr, client_addr;
  pthread_t thread_id;

  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(8080);

  bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

  listen(server_socket, MAX_CLIENTS);

  printf("Server started at port 8080...\n");

  while (1) {
    socklen_t client_len = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);

    pthread_mutex_lock(&mutex);
    if (client_count == MAX_CLIENTS) {
      printf("Maximum number of clients reached. Rejecting client...\n");
      close(client_socket);
      pthread_mutex_unlock(&mutex);
      continue;
    }
    clients[client_count] = client_socket;
    client_count++;
    pthread_mutex_unlock(&mutex);

    printf("Client connected! Total clients: %d\n", client_count);

    pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket);
    pthread_detach(thread_id);
  }

  close(server_socket);
  return 0;
}