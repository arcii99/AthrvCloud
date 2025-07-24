//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define RESPONSE "<html><body><h1>Hello, World!</h1></body></html>"

int main(int argc, char *argv[]) {
  int server_socket, client_socket, client_size;
  struct sockaddr_in server_addr, client_addr;
  char buffer[1024], response[4096];

  // Create socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Bind the socket to address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

  // Listen for incoming connections
  listen(server_socket, 5);
  printf("Listening on port 8080...\n");

  // Handle incoming connections
  while (1) {
    client_size = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_size);
    printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Receive data from client
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, sizeof(buffer), 0);

    // Send response to client
    sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n%s", strlen(RESPONSE), RESPONSE);
    send(client_socket, response, strlen(response), 0);

    // Close the socket
    printf("Closing connection...\n");
    close(client_socket);
  }

  // Close the server socket
  close(server_socket);

  return 0;
}