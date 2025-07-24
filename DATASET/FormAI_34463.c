//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main() {
  struct sockaddr_in server_addr, proxy_addr;
  int socket_fd, proxy_fd = 0, new_socket, client_len, valread;
  char buffer[1024] = {0};
  char response[1024] = {0};
  char *proxy_response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE html>\n<html><body><h1>Welcome to the Medieval Proxy Server!</h1></body></html>";
  
  // Creating socket file descriptor
  if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }
  
  // Setting server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  // Binding socket to server address
  if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listening for client connections
  if (listen(socket_fd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  // Accepting client connections
  while (1) {
    // Accepting new client connection
    client_len = sizeof(proxy_addr);
    if ((new_socket = accept(socket_fd, (struct sockaddr *)&proxy_addr, (socklen_t *)&client_len)) < 0) {
      perror("accept");
      exit(EXIT_FAILURE);
    }

    // Checking if server is already sending response
    if (proxy_fd != 0) {
      memset(buffer, 0, sizeof(buffer));
      valread = read(proxy_fd, buffer, 1024);
      if (valread > 0) {
        // Sending server response to client
        send(new_socket, buffer, strlen(buffer), 0);
      }
      else {
        // Server finished sending response, close connection to server and reset proxy_fd
        close(proxy_fd);
        proxy_fd = 0;

        // Sending proxy's response to client
        send(new_socket, proxy_response, strlen(proxy_response), 0);
      }
    }
    else {
      // Reading client request
      memset(buffer, 0, sizeof(buffer));
      valread = read(new_socket, buffer, 1024);

      // Printing client request
      printf("%s\n", buffer);

      // Checking if client request is a GET request
      if (strstr(buffer, "GET") == NULL) {
        // Not a GET request, sending error response to client
        char *error_response = "HTTP/1.1 400 Bad Request\r\nContent-Length: 0\r\n\r\n";
        send(new_socket, error_response, strlen(error_response), 0);
      }
      else {
        // Replacing client's Host header with Proxy's IP and Port
        char *host_ptr = strstr(buffer, "Host: ");
        host_ptr += strlen("Host: ");
        char *host_end_ptr = strstr(host_ptr, "\r\n");
        char host[256];
        memset(host, 0, 256);
        memcpy(host, host_ptr, host_end_ptr - host_ptr);

        memset(buffer, 0, sizeof(buffer));
        sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s:%d\r\nConnection: close\r\n\r\n", host_end_ptr, inet_ntoa(proxy_addr.sin_addr), ntohs(proxy_addr.sin_port));

        // Creating socket file descriptor to connect to server
        if ((proxy_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
          perror("socket failed");
          exit(EXIT_FAILURE);
        }

        // Setting server address
        struct sockaddr_in server_addr_proxy;
        server_addr_proxy.sin_family = AF_INET;
        server_addr_proxy.sin_port = htons(80);
        if (inet_pton(AF_INET, host, &server_addr_proxy.sin_addr) <= 0) {
          perror("Invalid address/ Address not supported");
          exit(EXIT_FAILURE);
        }

        // Connecting to server
        if (connect(proxy_fd, (struct sockaddr *)&server_addr_proxy, sizeof(server_addr_proxy)) < 0) {
          perror("connect failed");
          exit(EXIT_FAILURE);
        }

        // Sending client's request to server
        send(proxy_fd, buffer, strlen(buffer), 0);
      }
    }

    close(new_socket);
  }

  return 0;
}