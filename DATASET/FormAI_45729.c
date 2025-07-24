//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_REQUEST_SIZE 8192 // Maximum size of the incoming request
#define MAX_RESPONSE_SIZE 16384 // Maximum size of the outgoing response

int main(int argc, char *argv[]) {
  int listenfd, connfd;
  struct sockaddr_in servaddr, cliaddr;
  char request[MAX_REQUEST_SIZE], response[MAX_RESPONSE_SIZE], buffer[4096];
  ssize_t request_len, response_len, bytes;
  socklen_t cliaddr_len;
  int proxyPort;

  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  proxyPort = atoi(argv[1]);

  // Create a listening socket
  if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket error");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(proxyPort);

  // Bind the socket to the specified port
  if (bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
    perror("bind error");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(listenfd, 10) < 0) {
    perror("listen error");
    exit(1);
  }

  printf("Proxy server listening on port %d...\n", proxyPort);

  // Serve incoming requests
  while (1) {
    // Accept an incoming connection
    cliaddr_len = sizeof(cliaddr);
    if ((connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &cliaddr_len)) < 0) {
      perror("accept error");
      continue;
    }

    // Clear the request and response buffers
    memset(request, 0, sizeof(request));
    memset(response, 0, sizeof(response));

    // Read the incoming request
    if ((request_len = recv(connfd, request, MAX_REQUEST_SIZE, 0)) < 0) {
      perror("recv error");
      close(connfd);
      continue;
    }

    // Parse the request, and extract the host and port
    char *host = 0;
    char *port = 0;

    if ((host = strstr(request, "Host: ")) != NULL) {
      host += 6;
      port = strchr(host, ':');
      if (port) *port++ = 0;
      else {
        port = strchr(host, '\r');
        if (port) *port = 0;
      }
    }

    // Use the default port if one could not be extracted from the request
    if (!port) port = "80";

    printf("Request received for %s:%s\n", host, port);

    // Resolve the hostname to an IP address
    struct addrinfo hints, *addr_list;
    int addr_info_result;
    struct in_addr resolved_ip;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if ((addr_info_result = getaddrinfo(host, port, &hints, &addr_list)) != 0) {
      printf("getaddrinfo error: %s\n", gai_strerror(addr_info_result));
      close(connfd);
      continue;
    }

    resolved_ip.s_addr = ((struct sockaddr_in *) addr_list->ai_addr)->sin_addr.s_addr;
    freeaddrinfo(addr_list);

    // Create the outgoing socket
    int outgoing_socket;
    struct sockaddr_in outgoing_addr;

    if ((outgoing_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      perror("socket error");
      close(connfd);
      continue;
    }

    memset(&outgoing_addr, 0, sizeof(outgoing_addr));
    outgoing_addr.sin_family = AF_INET;
    outgoing_addr.sin_addr.s_addr = resolved_ip.s_addr;
    outgoing_addr.sin_port = htons(atoi(port));

    // Connect to the remote server
    if (connect(outgoing_socket, (struct sockaddr *) &outgoing_addr, sizeof(outgoing_addr)) < 0) {
      perror("connect error");
      close(connfd);
      close(outgoing_socket);
      continue;
    }

    // Send the request to the remote server
    if (send(outgoing_socket, request, request_len, 0) < 0) {
      perror("send error");
      close(connfd);
      close(outgoing_socket);
      continue;
    }

    // Read the response from the remote server
    response_len = 0;
    while ((bytes = recv(outgoing_socket, buffer, sizeof(buffer), 0)) > 0) {
      if (response_len + bytes > MAX_RESPONSE_SIZE - 1) break;
      memcpy(response + response_len, buffer, bytes);
      response_len += bytes;
      memset(buffer, 0, sizeof(buffer));
    }

    // Send the response back to the client
    if (send(connfd, response, response_len, 0) < 0) {
      perror("send error");
      close(connfd);
      close(outgoing_socket);
      continue;
    }

    printf("Response sent to client\n");

    close(connfd);
    close(outgoing_socket);
  }

  return 0;
}