//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: energetic
/* Hey there! Welcome to my TCP/IP Programming example program.
 * Get ready for a fun and energetic ride!
 * This program uses socket programming to create a client-server model and send messages between them.
 * Let's get started!
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080  // choosing a random port number

int main() {
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  char *hello = "Hey there! This is a TCP/IP Programming example program.\nLet's send some messages!\n";

  // creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // set socket options
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt failed");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  memset(address.sin_zero, '\0', sizeof address.sin_zero);

  // bind the socket to the specified port
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // listen for incoming connections
  if (listen(server_fd, 3) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  printf("Server listening on port %d...\n", PORT);

  // accept incoming connections
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
    perror("accept failed");
    exit(EXIT_FAILURE);
  }

  // send initial message to client
  send(new_socket, hello, strlen(hello), 0);

  printf("Initial message sent to client.\n");

  while(1) {
    // receive message from client
    valread = read(new_socket, buffer, 1024);
    printf("Received message from client: %s\n", buffer);

    if(strcmp(buffer, ":exit") == 0) {
      printf("Client disconnected\n");
      break;
    }

    // send message to client
    send(new_socket, buffer, strlen(buffer), 0);
    printf("Message sent to client.\n");
  }

  // close socket and exit program
  close(new_socket);
  close(server_fd);
  return 0;
}