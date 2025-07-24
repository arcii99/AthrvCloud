//FormAI DATASET v1.0 Category: Networking ; Style: expert-level
//This program demonstrates a server-client communication using sockets in C.
//The server waits for a client to connect, then receives a message from the client
//and sends a reply message back to the client.

//Header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 12345

int main(int argc, char *argv[]) {

  //Create a socket
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  
  if (server_fd == -1) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }
  
  //Set socket options
  int opt = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }
  
  //Bind socket to address and port
  struct sockaddr_in server_addr;
  
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);
  
  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }
  
  //Listen for incoming connections
  if (listen(server_fd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }
  
  //Accept incoming connections
  int client_fd;
  struct sockaddr_in client_addr;
  int addrlen = sizeof(client_addr);
  
  if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen)) < 0) {
    perror("accept");
    exit(EXIT_FAILURE);
  }
  
  printf("client connected: %s\n", inet_ntoa(client_addr.sin_addr));
  
  //Receive message from client
  char recv_buffer[1024] = {0};
  
  if (read(client_fd, recv_buffer, 1024) < 0) {
    perror("read");
    exit(EXIT_FAILURE);
  }
  
  printf("received message from client: %s\n", recv_buffer);
  
  //Send reply message to client
  char *msg = "Hello from the server!";
  
  if (send(client_fd, msg, strlen(msg), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }
  
  printf("reply message sent to client\n");
  
  //Close socket
  close(server_fd);
  
  return 0;
}