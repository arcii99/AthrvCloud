//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define BUFSIZE 8192
#define MAXPENDING 100

void error_exit(char *error_message) {
  perror(error_message);
  exit(EXIT_FAILURE);
}

void handle_request(int client_socket) {
  char request[BUFSIZE];
  char *line;
  char method[BUFSIZE];
  char url[BUFSIZE];
  char version[BUFSIZE];
  char host[BUFSIZE];
  int port;
  char *path;
  int len;
  char response[BUFSIZE];
  int response_socket;
  char response_buf[BUFSIZE];
  int response_bytes;

  memset(request, 0, BUFSIZE);
  memset(method, 0, BUFSIZE);
  memset(url, 0, BUFSIZE);
  memset(version, 0, BUFSIZE);
  memset(host, 0, BUFSIZE);
  memset(response, 0, BUFSIZE);
  memset(response_buf, 0, BUFSIZE);

  if (read(client_socket, request, BUFSIZE-1) < 0) {
    error_exit("Error reading from client socket");
  }

  line = strtok(request, "\r\n");
  sscanf(line, "%s %s %s", method, url, version);

  path = strchr(url, '/');
  *path = '\0';
  ++path;

  if (strcmp(method, "CONNECT") == 0) {
    sscanf(url, "%[^:]:%d", host, &port);
    response_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in remote_address = {0};
    remote_address.sin_family = AF_INET;
    remote_address.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &remote_address.sin_addr) <= 0) {
      error_exit("Error parsing remote address");
    }
    if (connect(response_socket, (struct sockaddr *)&remote_address, sizeof(remote_address)) < 0){
      error_exit("Error connecting to remote server");
    }
    strcpy(response_buf, "HTTP/1.0 200 Connection established\r\n\r\n");
    if (send(client_socket, response_buf, strlen(response_buf), 0) != strlen(response_buf)) {
      error_exit("Error sending response to client");
    }
    while (true) {
      fd_set read_fd_set;
      FD_ZERO(&read_fd_set);
      FD_SET(client_socket, &read_fd_set);
      FD_SET(response_socket, &read_fd_set);
      int maxfd = (client_socket > response_socket) ? client_socket : response_socket;
      if (select(maxfd+1, &read_fd_set, NULL, NULL, NULL)<=0) {
        error_exit("Error in select");
      }
      if (FD_ISSET(client_socket, &read_fd_set)) {
        memset(response_buf, 0, BUFSIZE);
        response_bytes = read(client_socket, response_buf, BUFSIZE-1);
        if (response_bytes < 0) {
          error_exit("Error reading from client socket");
        }
        if (send(response_socket, response_buf, response_bytes, 0) != response_bytes) {
          error_exit("Error sending to remote server");
        }
      }
      if (FD_ISSET(response_socket, &read_fd_set)) {
        memset(response_buf, 0, BUFSIZE);
        response_bytes = read(response_socket, response_buf, BUFSIZE-1);
        if (response_bytes < 0) {
          error_exit("Error reading from remote server");
        }
        if (send(client_socket, response_buf, response_bytes, 0) != response_bytes) {
          error_exit("Error sending to client socket");
        }
      }
    }
  } else {
    response_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in remote_address = {0};
    remote_address.sin_family = AF_INET;
    remote_address.sin_port = htons(80);
    if (inet_pton(AF_INET, url, &remote_address.sin_addr) <= 0) {
      error_exit("Error parsing remote address");
    }
    if (connect(response_socket, (struct sockaddr *)&remote_address, sizeof(remote_address)) < 0){
      error_exit("Error connecting to remote server");
    }
    len = sprintf(response_buf, "%s %s %s\r\n", method, path, version);
    while (line != NULL) {
      line = strtok(NULL, "\r\n");
      if (strstr(line, "Connection:") == NULL && strstr(line, "Proxy-Connection:") == NULL) {
        len += sprintf(response_buf+len, "%s\r\n", line);
      }
    }
    len += sprintf(response_buf+len, "\r\n");
    if (send(response_socket, response_buf, strlen(response_buf), 0) != strlen(response_buf)) {
      error_exit("Error sending request to remote server");
    }
    while (true) {
      fd_set read_fd_set;
      FD_ZERO(&read_fd_set);
      FD_SET(client_socket, &read_fd_set);
      FD_SET(response_socket, &read_fd_set);
      int maxfd = (client_socket > response_socket) ? client_socket : response_socket;
      if (select(maxfd+1, &read_fd_set, NULL, NULL, NULL)<=0) {
        error_exit("Error in select");
      }
      if (FD_ISSET(client_socket, &read_fd_set)) {
        memset(response_buf, 0, BUFSIZE);
        response_bytes = read(client_socket, response_buf, BUFSIZE-1);
        if (response_bytes < 0) {
          error_exit("Error reading from client socket");
        }
        if (send(response_socket, response_buf, response_bytes, 0) != response_bytes) {
          error_exit("Error sending to remote server");
        }
      }
      if (FD_ISSET(response_socket, &read_fd_set)) {
        memset(response_buf, 0, BUFSIZE);
        response_bytes = read(response_socket, response_buf, BUFSIZE-1);
        if (response_bytes < 0) {
          error_exit("Error reading from remote server");
        }
        if (send(client_socket, response_buf, response_bytes, 0) != response_bytes) {
          error_exit("Error sending to client socket");
        }
      }
      if (response_bytes == 0) {
        break;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int server_socket;
  int client_socket;
  struct sockaddr_in server_address;
  struct sockaddr_in client_address;
  socklen_t client_address_len;

  if (argc != 2) {
    printf("Usage: %s <port number>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int port = atoi(argv[1]);

  server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (server_socket < 0) {
    error_exit("Error creating server socket");
  }

  memset(&server_address, 0, sizeof(server_address));

  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  server_address.sin_port = htons(port);

  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0){
    error_exit("Error binding server socket");
  }

  if (listen(server_socket, MAXPENDING) < 0) {
    error_exit("Error listening on server socket");
  }

  while (true) {
    client_address_len = sizeof(client_address);

    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len)) < 0) {
      error_exit("Error accepting client socket");
    }

    handle_request(client_socket);

    if (close(client_socket) < 0) {
      error_exit("Error closing client socket");
    }
  }

  return 0;
}