//FormAI DATASET v1.0 Category: Chat server ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 5000
#define BUFFER_SIZE 1024

int main(){
  int server_fd, new_socket, val_read;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[BUFFER_SIZE] = {0};
  
  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Attach socket to port
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt))){
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // Bind socket to specified address and port number
  if (bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0){
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_fd, 3) < 0){
    perror("listen");
    exit(EXIT_FAILURE);
  }
  printf("Chat Server Listening on port: %d \n", PORT);

  // Accept incoming connection
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address,(socklen_t*)&addrlen))<0){
    perror("accept");
    exit(EXIT_FAILURE);
  }

  // Communication between Client and Server 
  while(1){
    // Reading message from Client
    val_read = read(new_socket, buffer, BUFFER_SIZE);
    if(val_read == 0){
      printf("Client Disconnecting\n");
      break;
    }
    printf("Client says: %s", buffer);
    memset(buffer, 0, BUFFER_SIZE); // Clearing buffer

    // Sending message to Client
    printf("Enter Your Message (type 'quit' to stop): ");
    gets(buffer);
    send(new_socket, buffer, strlen(buffer), 0);
    if(strcmp(buffer, "quit") == 0){
      printf("Closing Connection...\n");
      break;
    }
    memset(buffer, 0, BUFFER_SIZE);
  }
  close(new_socket);
  close(server_fd);
  return 0;
}