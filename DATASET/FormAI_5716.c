//FormAI DATASET v1.0 Category: Simple Web Server ; Style: grateful
// include the necessary C libraries
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define LISTEN_PORT 8080

int main() {
  int socket_fd, client_fd, addr_len;
  struct sockaddr_in server_addr , client_addr;
  char response[] = "HTTP/1.1 200 OK\r\n\r\nHello World!";

  // Create a new server socket
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);

  // Configure and bind the server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons( LISTEN_PORT );
  bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  // Start listening for incoming connections
  listen(socket_fd, 3);
  printf("Server listening on port %d\n", LISTEN_PORT);

  while(1) {
    // Accept incoming client connection
    addr_len = sizeof(struct sockaddr_in);
    client_fd = accept(socket_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addr_len);

    // Send a response back to the client
    write(client_fd, response, strlen(response));

    // Close the client socket
    shutdown(client_fd, SHUT_RDWR);
    close(client_fd);
    printf("Client connection closed.\n");
  }

  // Close the server socket and exit the program
  shutdown(socket_fd, SHUT_RDWR);
  close(socket_fd);
  return 0;
}