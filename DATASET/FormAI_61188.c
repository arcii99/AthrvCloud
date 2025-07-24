//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PROXY_PORT 9000

int main(int argc, char *argv[]) {
  int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_len = sizeof(client_addr);
  char buffer[BUFFER_SIZE];
  struct hostent *host;
  int n, bytes_read;

  // Create server socket
  server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (server_sock < 0) {
    perror("Error creating server socket");
    exit(1);
  }

  // Bind server socket to port
  memset((char *)&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(PROXY_PORT);
  if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding server socket to port");
    exit(1);
  }

  // Listen for client connections
  if (listen(server_sock, 5) < 0) {
    perror("Error listening for connections");
    exit(1);
  }

  fprintf(stdout, "Simple HTTP Proxy listening on port %d...\n", PROXY_PORT);

  // Accept client connections and forward requests to the server
  while (1) {
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
      perror("Error accepting client connection");
      continue;
    }

    // Parse client request
    memset(buffer, 0, BUFFER_SIZE);
    n = read(client_sock, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
      perror("Error reading client request");
      close(client_sock);
      continue;
    }

    // Extract host name and port number from the client request
    char *host_start = strstr(buffer, "Host:");
    if (host_start == NULL) {
      fprintf(stderr, "Invalid client request: no Host header\n");
      close(client_sock);
      continue;
    }

    char *host_end = strchr(host_start, '\r');
    if (host_end == NULL) {
      fprintf(stderr, "Invalid client request: no end-of-line in Host header\n");
      close(client_sock);
      continue;
    }

    *host_end = '\0';
    char *hostname = host_start + 6;  // skip the "Host:" prefix
    int port = 80;  // default HTTP port

    char *port_start = strchr(hostname, ':');
    if (port_start != NULL) {
      *port_start = '\0';
      port = atoi(port_start + 1);
    }

    // Resolve server IP address from host name
    struct in_addr server_ip;
    host = gethostbyname(hostname);
    if (host == NULL) {
      fprintf(stderr, "Unknown host %s\n", hostname);
      close(client_sock);
      continue;
    }

    memcpy(&server_ip, host->h_addr_list[0], sizeof(server_ip));

    // Connect to server and forward client request
    int server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_sock < 0) {
      perror("Error creating server socket to connect to server");
      close(client_sock);
      continue;
    }

    // Set server socket to non-blocking mode
    if (fcntl(server_sock, F_SETFL, O_NONBLOCK) < 0) {
      perror("Error setting server socket to non-blocking mode");
      close(server_sock);
      close(client_sock);
      continue;
    }

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = server_ip;
    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      if (errno != EINPROGRESS) {
      	perror("Error connecting to server");
	      close(server_sock);
	      close(client_sock);
	      continue;
      }
    }

    // Add client and server sockets to the file descriptor set
    fd_set fdset;
    FD_ZERO(&fdset);
    FD_SET(client_sock, &fdset);
    FD_SET(server_sock, &fdset);

    int max_fd = (client_sock > server_sock) ? client_sock : server_sock;

    // Forward data between client and server
    while (1) {
      select(max_fd + 1, &fdset, NULL, NULL, NULL);

      if (FD_ISSET(client_sock, &fdset)) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read = read(client_sock, buffer, BUFFER_SIZE);
        if (bytes_read <= 0) break; // End of data
        n = write(server_sock, buffer, bytes_read);
        if (n < 0) {
          perror("Error forwarding client data to server");
          break;
        }
      }

      if (FD_ISSET(server_sock, &fdset)) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read = read(server_sock, buffer, BUFFER_SIZE);
        if (bytes_read <= 0) break; // End of data
        n = write(client_sock, buffer, bytes_read);
        if (n < 0) {
          perror("Error forwarding server data to client");
          break;
        }
      }
    }

    close(server_sock);
    close(client_sock);
  }

  return 0;
}