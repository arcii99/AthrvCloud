//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PROXY_PORT 1234
#define SERVER_PORT 80
#define MAX_BUFFER_SIZE 65536

void error(char *msg) {
  printf("\033[0;31m[ERROR] %s\033[0m\n", msg);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    error("Usage: ./proxy <server-ip>");
    exit(1);
  }

  struct sockaddr_in proxy_addr, server_addr;
  int proxy_fd, server_fd, client_fd, addr_len, n;
  char buffer[MAX_BUFFER_SIZE], request[MAX_BUFFER_SIZE], response[MAX_BUFFER_SIZE];
  memset(buffer, 0, MAX_BUFFER_SIZE);

  proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (proxy_fd < 0) {
    error("Failed to create proxy socket.");
    exit(1);
  }

  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    error("Failed to create server socket.");
    exit(1);
  }

  bzero((char *) &proxy_addr, sizeof(proxy_addr));
  proxy_addr.sin_family = AF_INET;
  proxy_addr.sin_addr.s_addr = INADDR_ANY;
  proxy_addr.sin_port = htons(PROXY_PORT);

  if (bind(proxy_fd, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
    error("Failed to bind to proxy address.");
    exit(1);
  }

  listen(proxy_fd, 1);
  printf("Proxy server listening on port %d...\n", PROXY_PORT);

  addr_len = sizeof(server_addr);
  bzero((char *) &server_addr, addr_len);
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) < 0) {
    error("Invalid server IP address.");
    exit(1);
  }

  while (1) {
    client_fd = accept(proxy_fd, (struct sockaddr *) &proxy_addr, &addr_len);
    if (client_fd < 0) {
      error("Failed to accept client connection.");
      continue;
    } else {
      printf("Client connected.\n");
    }

    memset(request, 0, MAX_BUFFER_SIZE);
    n = read(client_fd, request, MAX_BUFFER_SIZE-1);
    if (n < 0) {
      error("Failed to read request message.");
      close(client_fd);
      continue;
    }

    // Processing the incoming request
    printf("Request message from client:\n");
    printf("%s\n", request);

    // Forwarding the request to server
    if (connect(server_fd, (struct sockaddr *) &server_addr, addr_len) < 0) {
      error("Failed to connect to server.");
      close(client_fd);
      continue;
    }

    n = write(server_fd, request, strlen(request));
    if (n < 0) {
      error("Failed to write to server.");
      close(client_fd);
      close(server_fd);
      continue;
    }

    // Getting response from server
    memset(response, 0, MAX_BUFFER_SIZE);
    n = read(server_fd, response, MAX_BUFFER_SIZE-1);
    if (n < 0) {
      error("Failed to read server response.");
      close(client_fd);
      close(server_fd);
      continue;
    }

    // Processing the response from server
    printf("\nResponse message from server:\n");
    printf("%s\n", response);

    // Forwarding the response to client
    n = write(client_fd, response, strlen(response));
    if (n < 0) {
      error("Failed to write to client.");
      close(client_fd);
      close(server_fd);
      continue;
    }

    printf("Proxy server sent response to the client.\n");
    close(client_fd);
    close(server_fd);
  }

  return 0;
}