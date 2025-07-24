//FormAI DATASET v1.0 Category: Simple Web Server ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  char *hello = "Hello from the other side!";

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&address,sizeof(address)) < 0) {
    perror("Binding failed");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 3) < 0) {
    perror("Listening failed");
    exit(EXIT_FAILURE);
  }

  while (1) {
    printf("\n--- Waiting for new connection ---\n");

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
      perror("Accepting failed");
      exit(EXIT_FAILURE);
    }

    printf("New connection accepted\n");

    valread = read(new_socket, buffer, 1024);
    printf("Request message:\n%s\n", buffer);

    char response[1024] = {0};
    strcat(response, "HTTP/1.1 200 OK\n");
    strcat(response, "Content-Type: text/html\n");
    strcat(response, "\n");
    strcat(response, "<html><body><h1>");
    strcat(response, hello);
    strcat(response, "</h1></body></html>");

    send(new_socket, response, strlen(response), 0);
    printf("Response message sent:\n%s\n", response);

    close(new_socket);
    printf("Connection closed\n");
  }

  return 0;
}