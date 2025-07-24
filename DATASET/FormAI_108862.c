//FormAI DATASET v1.0 Category: Simple Web Server ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <signal.h>

#define BUF_SIZE 2048
#define QUEUE_SIZE 10

static void sig_handler(int signum);

int main(int argc, char *argv[]) {
  signal(SIGINT, sig_handler);
  signal(SIGTERM, sig_handler);

  char *ip_address = "0.0.0.0";
  int port = 8080;

  // Parse command line arguments
  int opt;
  while ((opt = getopt(argc, argv, "i:p:")) != -1) {
    switch (opt) {
      case 'i':
        ip_address = optarg;
        break;
      case 'p':
        port = atoi(optarg);
        break;
      case '?':
        fprintf(stderr, "Usage: %s [-i ip_address] [-p port]\n", argv[0]);
        exit(EXIT_FAILURE);
      default:
        exit(EXIT_FAILURE);
    }
  }

  // Create socket
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set socket options
  int optval = 1;
  if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) == -1) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Bind to IP address and port
  struct sockaddr_in server_addr = {0};
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(ip_address);
  server_addr.sin_port = htons(port);
  if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // Set socket to non-blocking mode
  int flags = fcntl(sock_fd, F_GETFL, 0);
  if (flags == -1) {
    perror("fcntl");
    exit(EXIT_FAILURE);
  }
  if (fcntl(sock_fd, F_SETFL, flags | O_NONBLOCK) == -1) {
    perror("fcntl");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(sock_fd, QUEUE_SIZE) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  fd_set read_fds;
  FD_ZERO(&read_fds);
  FD_SET(sock_fd, &read_fds);

  while (true) {
    fd_set tmp_fds = read_fds;
    if (select(FD_SETSIZE, &tmp_fds, NULL, NULL, NULL) == -1) {
      if (errno == EINTR) {
        continue;
      } else {
        perror("select");
        exit(EXIT_FAILURE);
      }
    }

    for (int i = 0; i < FD_SETSIZE; i++) {
      if (FD_ISSET(i, &tmp_fds)) {
        if (i == sock_fd) {
          // Accept incoming connection
          struct sockaddr_in client_addr = {0};
          socklen_t client_addr_len = sizeof(client_addr);
          int client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_addr_len);
          if (client_fd == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
              break;
            } else {
              perror("accept");
              exit(EXIT_FAILURE);
            }
          }

          // Set client socket to non-blocking mode
          int flags = fcntl(client_fd, F_GETFL, 0);
          if (flags == -1) {
            perror("fcntl");
            exit(EXIT_FAILURE);
          }
          if (fcntl(client_fd, F_SETFL, flags | O_NONBLOCK) == -1) {
            perror("fcntl");
            exit(EXIT_FAILURE);
          }

          FD_SET(client_fd, &read_fds);
        } else {
          // Handle data from client
          char buf[BUF_SIZE] = {0};
          ssize_t num_bytes = recv(i, buf, BUF_SIZE, 0);
          if (num_bytes == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
              break;
            } else {
              perror("recv");
              exit(EXIT_FAILURE);
            }
          } else if (num_bytes == 0) {
            FD_CLR(i, &read_fds);
            close(i);
          } else {
            // Send response
            char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, world";
            ssize_t response_len = strlen(response);
            ssize_t num_sent = send(i, response, response_len, 0);
            if (num_sent == -1) {
              perror("send");
              FD_CLR(i, &read_fds);
              close(i);
            }
          }
        }
      }
    }
  }

  return EXIT_SUCCESS;
}

static void sig_handler(int signum) {
  printf("Received signal %d. Exiting.\n", signum);
  exit(EXIT_SUCCESS);
}