//FormAI DATASET v1.0 Category: Simple Web Server ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define RESPONSE_SIZE 2048
#define HTML_SIZE 1024

int main() {

  int server_socket_fd, client_socket_fd;
  char response[RESPONSE_SIZE], html[HTML_SIZE];

  struct sockaddr_in server_address, client_address;
  socklen_t client_address_size = sizeof(client_address);

  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(8080);

  server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));
  listen(server_socket_fd, 5);

  while (1) {
    client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_address, &client_address_size);

    sprintf(html, "<html><head><title>Hello World!</title></head><body><h1>Hello World!</h1></body></html>");

    sprintf(response, "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %li\n\n%s", strlen(html), html);

    write(client_socket_fd, response, strlen(response));
    close(client_socket_fd);
  }

  return 0;
}