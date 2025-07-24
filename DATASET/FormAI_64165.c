//FormAI DATASET v1.0 Category: Simple Web Server ; Style: beginner-friendly
/* C Simple Web Server */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int server_fd, new_socket, val_read;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char buffer[MAX_BUFFER_SIZE] = {0};
  char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";
  
  /* Create a socket file descriptor */
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }
  
  /* Set the server socket options */
  int opt = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt failed");
    exit(EXIT_FAILURE);
  }
  
  /* Bind the socket to the specified port */
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);
  
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }
  
  /* Listen for incoming connections */
  if (listen(server_fd, 3) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }
  
  printf("Server listening on port %d...\n", PORT);
  
  /* Handle incoming client connections */
  while (1) {
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
      perror("accept failed");
      exit(EXIT_FAILURE);
    }
    
    /* Read the incoming client request */
    val_read = read(new_socket, buffer, MAX_BUFFER_SIZE);
    printf("Client sent: %s\n", buffer);
    
    /* Send the response back to the client */
    send(new_socket, response, strlen(response), 0);
    printf("Response sent.\n");
    
    /* Clean up */
    close(new_socket);
  }
  
  return 0;
}