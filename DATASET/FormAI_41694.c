//FormAI DATASET v1.0 Category: Simple Web Server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handleHttpRequest(int socketFD);

int main() {
  int serverSocketFD = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocketFD < 0) {
    perror("Failed to create server socket");
    exit(EXIT_FAILURE);
  }

  int opt = 1;
  if (setsockopt(serverSocketFD, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("Failed to set socket options");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons(PORT);

  if (bind(serverSocketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
    perror("Failed to bind server socket to address");
    exit(EXIT_FAILURE);
  }

  if (listen(serverSocketFD, 3) < 0) {
    perror("Failed to listen for incoming connections");
    exit(EXIT_FAILURE);
  }

  printf("Simple web server listening on port %d\n", PORT);

  while(1) {
    int clientSocketFD = accept(serverSocketFD, NULL, NULL);
    if (clientSocketFD < 0) {
      perror("Failed to accept incoming connection");
      exit(EXIT_FAILURE);
    }

    handleHttpRequest(clientSocketFD);
    close(clientSocketFD);
  }
  
  return 0;
}

void handleHttpRequest(int socketFD) {
  char buffer[BUFFER_SIZE] = {0};
  int readReturnValue = read(socketFD, buffer, BUFFER_SIZE);
  if (readReturnValue < 0) {
    perror("Failed to read request from client");
    exit(EXIT_FAILURE);
  }

  printf("Received HTTP Request:\n%s", buffer);

  char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\nHello World!";
  int writeReturnValue = write(socketFD, response, strlen(response));
  if (writeReturnValue < 0) {
    perror("Failed to write response to client");
    exit(EXIT_FAILURE);
  }

  printf("HTTP Response sent to client successfully\n");
}