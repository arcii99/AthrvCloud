//FormAI DATASET v1.0 Category: Simple Web Server ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
  int server_fd, new_socket, valread;

  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};

  char *hello = "Welcome to my Simple Web Server\n";

  // Create a socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    printf("Oh my goodness! Failed to create socket :( \n");
    return -1;
  }

  address.sin_family = AF_INET;  // Address family IPv4
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);  // Port 8080

  // Bind the socket to the address and port number
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    printf("Uh oh! Could not bind socket :( \n");
    return -1;
  }

  // Listen for incoming connections
  if (listen(server_fd, 3) < 0) {
    printf("Yikes! Failed to listen :( \n");
    return -1;
  }

  printf("Hooray! Server listening on port %d\n", PORT);

  // Accept incoming connections
  while (1) {
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0) {
      printf("Oops! Connection failure\n");
      return -1;
    }

    printf("New connection established!\n");

    // Send welcome message
    send(new_socket, hello, strlen(hello), 0);

    // Receive and send message
    valread = read(new_socket, buffer, 1024);
    printf("Message Received: %s\n", buffer);
    send(new_socket, buffer, strlen(buffer), 0);
    memset(buffer, 0, 1024);

    // Close the connection
    close(new_socket);
  }

  return 0;
}