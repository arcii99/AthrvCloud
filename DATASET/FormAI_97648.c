//FormAI DATASET v1.0 Category: Networking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
  struct sockaddr_in my_address, server_address;
  int socket_fd = 0, bytes_read;
  char buffer[MAX_BUFFER_SIZE] = {0};
  char * message = "Hello, world!";

  // create a socket
  if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket creation failed");
    return -1;
  }

  // set up my_address
  my_address.sin_family = AF_INET;
  my_address.sin_addr.s_addr = INADDR_ANY;
  my_address.sin_port = htons(PORT);

  // bind the socket to my_address
  if (bind(socket_fd, (struct sockaddr *)&my_address, sizeof(my_address)) < 0) {
    perror("bind failed");
    return -1;
  }

  // set up server_address
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);

  // convert IPv4 and IPv6 addresses from text to binary form
  if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr)<=0) { 
    printf("\nInvalid address/ Address not supported \n"); 
    return -1; 
  }

  // connect to the server
  if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("connection failed");
    return -1;
  }

  // send a message to the server
  if (send(socket_fd, message, strlen(message), 0) < 0) {
    perror("send failed");
    return -1;
  }

  // receive a message from the server
  if ((bytes_read = read(socket_fd, buffer, MAX_BUFFER_SIZE)) < 0) {
    perror("read failed");
    return -1;
  }

  printf("Server says: %s\n", buffer);

  return 0;
}