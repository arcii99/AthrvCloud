//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Romeo and Juliet
// The Tragic Tale of Romeo and Juliet - A Simple Web Server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define port number and buffer size
#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
  int serverfd, new_socket;
  long valread;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char buffer[BUFFER_SIZE] = {0};
  char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";

  // Create socket
  if ((serverfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Set socket to allow multiple connections
  if (setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &(int){1}, sizeof(int)) < 0) {
    perror("setsockopt failed");
    exit(EXIT_FAILURE);
  }

  // Initialize server address and port
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr("127.0.0.1");
  address.sin_port = htons(PORT);

  // Bind server socket to address and port
  if (bind(serverfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(serverfd, 3) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  // Romeo waits for Juliet's requests
  printf("Romeo waits for Juliet's requests...\n");

  while (1) {
    // Accept incoming connection and send response
    if ((new_socket = accept(serverfd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
      perror("accept failed");
      exit(EXIT_FAILURE);
    }

    valread = read(new_socket, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);
    write(new_socket, hello, strlen(hello));
    printf("Message sent to Juliet: %s\n", hello);
    close(new_socket);
  }

  return 0;
}