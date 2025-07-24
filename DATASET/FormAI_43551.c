//FormAI DATASET v1.0 Category: Network Ping Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void pingServer(char *host, int port) {
  printf("Pinging %s on port %d...\n", host, port);
  
  // create socket
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    perror("Error creating socket");
    exit(1);
  }
  
  // set server address and port number
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr(host);
  server_address.sin_port = htons(port);
  
  // connect to server
  int connect_result = connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address));
  if (connect_result < 0) {
    perror("Error connecting to server");
    exit(1);
  }
  
  // send a message to server
  char *message = "Ping";
  send(socket_fd, message, strlen(message), 0);
  
  // receive a response from server
  char buffer[BUFFER_SIZE];
  ssize_t n = recv(socket_fd, buffer, BUFFER_SIZE, 0);
  if (n < 0) {
    perror("Error receiving response");
    exit(1);
  }
  
  // close socket
  close(socket_fd);
  
  printf("Received response from %s: %s\n", host, buffer);
}

int main() {
  pingServer("127.0.0.1", 8080);
  pingServer("192.168.1.1", 80);
  pingServer("www.google.com", 443);
  return 0;
}