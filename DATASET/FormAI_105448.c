//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: optimized
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

int main() {
  // create proxy server socket
  int proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (proxy_fd < 0) {
    perror("Error creating proxy socket\n");
    exit(EXIT_FAILURE);
  }

  // set proxy server info
  struct sockaddr_in proxy_addr;
  memset(&proxy_addr, 0, sizeof(proxy_addr));
  proxy_addr.sin_family = AF_INET;
  proxy_addr.sin_port = htons(SERVER_PORT);
  proxy_addr.sin_addr.s_addr = INADDR_ANY;

  // bind the proxy socket to the proxy address
  if (bind(proxy_fd, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr)) < 0) {
    perror("Error binding proxy socket\n");
    exit(EXIT_FAILURE);
  }

  // listen for incoming client requests
  if (listen(proxy_fd, BACKLOG) < 0) {
    perror("Error listening for client connections\n");
    exit(EXIT_FAILURE);
  }

  // accept incoming client connections
  while (true) {
    int client_fd = accept(proxy_fd, NULL, NULL);
    if (client_fd < 0) {
      perror("Error accepting client connection\n");
      continue;
    }

    // spawn child process to handle client request
    pid_t child_pid = fork();
    if (child_pid < 0) {
      perror("Error forking process to handle client request\n");
      exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
      // handle client request
      char client_buffer[BUFFER_SIZE];
      memset(client_buffer, 0, sizeof(client_buffer));
      ssize_t n = read(client_fd, client_buffer, sizeof(client_buffer)-1);
      if (n < 0) {
        perror("Error reading client request\n");
        exit(EXIT_FAILURE);
      }

      // extract client request info
      char method[BUFFER_SIZE], url[BUFFER_SIZE], version[BUFFER_SIZE];
      sscanf(client_buffer, "%s %s %s", method, url, version);

      // parse client request URL
      char* url_ptr = strstr(url, "://");
      if (url_ptr != NULL) url_ptr += 3; // skip "://"
      else url_ptr = url;

      char* port_ptr = strstr(url_ptr, ":");
      char* path_ptr = strstr(url_ptr, "/");
      if (path_ptr == NULL) path_ptr = url_ptr + strlen(url_ptr);

      char host[BUFFER_SIZE], port_str[BUFFER_SIZE], path[BUFFER_SIZE];
      memset(host, 0, sizeof(host));
      memset(port_str, 0, sizeof(port_str));
      memset(path, 0, sizeof(path));

      int port = 80; // assume default port is 80
      if (port_ptr != NULL && port_ptr < path_ptr) {
        strncpy(host, url_ptr, port_ptr-url_ptr);
        strncpy(port_str, port_ptr+1, path_ptr-port_ptr-1);
        port = atoi(port_str);
      } else {
        strncpy(host, url_ptr, path_ptr-url_ptr);
      }
      if (*path_ptr != '\0') strncpy(path, path_ptr, sizeof(path)-1);

      // create socket for server connection
      int server_fd = socket(AF_INET, SOCK_STREAM, 0);
      if (server_fd < 0) {
        perror("Error creating server socket\n");
        exit(EXIT_FAILURE);
      }

      // get server address info from host and port
      struct sockaddr_in server_addr;
      memset(&server_addr, 0, sizeof(server_addr));
      server_addr.sin_family = AF_INET;
      server_addr.sin_port = htons(port);

      if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        perror("Error converting server address\n");
        exit(EXIT_FAILURE);
      }

      // connect to server
      if (connect(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server\n");
        exit(EXIT_FAILURE);
      }

      // send client request to server
      if (write(server_fd, client_buffer, strlen(client_buffer)) != strlen(client_buffer)) {
        perror("Error sending client request to server\n");
        exit(EXIT_FAILURE);
      }

      // forward server response to client
      char server_buffer[BUFFER_SIZE];
      ssize_t m;
      while ((m = read(server_fd, server_buffer, sizeof(server_buffer))) > 0) {
        if (write(client_fd, server_buffer, m) != m) {
          perror("Error forwarding server response to client\n");
          exit(EXIT_FAILURE);
        }
      }
      if (m < 0) {
        perror("Error reading server response\n");
        exit(EXIT_FAILURE);
      }

      // close sockets and exit child process
      close(server_fd);
      close(client_fd);
      exit(EXIT_SUCCESS);
    } else {
      // close client socket and continue listening for new client requests
      close(client_fd);
    }
  }

  // close proxy socket and exit
  close(proxy_fd);
  return 0;
}