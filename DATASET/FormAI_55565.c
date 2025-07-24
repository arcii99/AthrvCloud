//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUF_SIZE 1024

struct sockaddr_in addr;
int sock_fd, client_fd;
pthread_t server_thread, client_thread;

void *server_func(void *arg);
void *client_func(void *arg);

int main(int argc, char *argv[]) {
  int port = 8888;

  if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(1);
  }

  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(port);

  if (bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    exit(1);
  }

  if (listen(sock_fd, 5) == -1) {
    perror("listen");
    exit(1);
  }

  printf("Server waiting for connection...\n");

  if (pthread_create(&server_thread, NULL, server_func, NULL) != 0) {
    perror("pthread_create");
    exit(1);
  }

  if (pthread_create(&client_thread, NULL, client_func, NULL) != 0) {
    perror("pthread_create");
    exit(1);
  }

  pthread_join(server_thread, NULL);
  pthread_join(client_thread, NULL);

  close(sock_fd);

  return 0;
}

void *server_func(void *arg) {
  while (1) {
    socklen_t addr_len = sizeof(addr);
    char buf[BUF_SIZE] = {0};
    memset(buf, 0, BUF_SIZE);

    if ((client_fd = accept(sock_fd, (struct sockaddr *)&addr, &addr_len)) == -1) {
      perror("accept");
      exit(1);
    }

    printf("Server connected to client %s\n", inet_ntoa(addr.sin_addr));

    if (recv(client_fd, buf, BUF_SIZE, 0) == -1) {
      perror("recv");
      exit(1);
    }

    printf("Server received: %s", buf);

    if (send(client_fd, "Server: Hello client!\n", 23, 0) == -1) {
      perror("send");
      exit(1);
    }

    close(client_fd);
  }
}

void *client_func(void *arg) {
  while (1) {
    sleep(1);
    char buf[BUF_SIZE] = {0};
    memset(buf, 0, BUF_SIZE);

    if (connect(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
      perror("connect");
      exit(1);
    }

    printf("Client connected to server\n");

    if (send(sock_fd, "Client: Hello server!\n", 23, 0) == -1) {
      perror("send");
      exit(1);
    }

    if (recv(sock_fd, buf, BUF_SIZE, 0) == -1) {
      perror("recv");
      exit(1);
    }

    printf("Client received: %s", buf);

    close(sock_fd);
  }
}