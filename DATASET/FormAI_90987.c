//FormAI DATASET v1.0 Category: Chat server ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 5
#define PORT 8080

pthread_mutex_t lock;

void *handle_client(void *);

int main(int argc, char **argv) {
  int server_fd, client_fd, opt = 1;
  struct sockaddr_in address;
  int addrlen = sizeof(address);

  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt failed");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, MAX_CLIENTS) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  printf("Server started on port %d\n", PORT);

  while (1) {
    client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);

    if (client_fd < 0) {
      perror("accept failed");
      continue;
    }

    pthread_t client_thread;
    if (pthread_create(&client_thread, NULL, handle_client, (void *)&client_fd)) {
      perror("thread creation failed");
      continue;
    }

    printf("New client connected\n");
  }

  close(server_fd);
  return 0;
}

void *handle_client(void *arg) {
  int client_fd = *(int *)arg;
  char buffer[1024] = {0};

  while (1) {
    int bytes_read = read(client_fd, buffer, 1024);
    if (bytes_read < 0) {
      perror("read failed");
      break;
    } else if (bytes_read == 0) {
      printf("Client disconnected\n");
      break;
    }

    printf("Client message: %s\n", buffer);

    pthread_mutex_lock(&lock);
    printf("Enter a response: ");
    fgets(buffer, 1024, stdin);
    pthread_mutex_unlock(&lock);

    write(client_fd, buffer, strlen(buffer));
  }

  close(client_fd);
  pthread_exit(NULL);
}