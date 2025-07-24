//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: authentic
#include <stdio.h>          // Standard Input/Output Library
#include <stdlib.h>         // Standard Library
#include <string.h>         // String Library
#include <arpa/inet.h>      // For Inet_ntoa Function
#include <sys/socket.h>     // Socket Programming Library
#include <unistd.h>         // For Close Function
#include <pthread.h>        // For Threading

#define PORT 8080          // Port Number of Server

void *handle_client(void *);

int main(int argc, char **argv) {
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);

  // Creating Socket
  server_fd = socket(AF_INET, SOCK_STREAM, 0);

  // Attach Socket to Port and IP Address
  if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // Binding Socket to Port and IP Address
  if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Waiting for Incoming Connections
  if(listen(server_fd, 3) < 0){
    perror("listen");
    exit(EXIT_FAILURE);
  }

  printf("Server is now online, Listening on Port %d\n", PORT);

  while(1){
    if((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0){
      perror("accept");
      exit(EXIT_FAILURE);
    }

    printf("Connection Request from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    pthread_t client_thread;
    if(pthread_create(&client_thread, NULL, handle_client, (void *)&new_socket) < 0){
      perror("pthread_create");
      exit(EXIT_FAILURE);
    }
  }

  // Closing the Socket
  close(server_fd);
  return 0;
}

void *handle_client(void *new_socket){
  int sfd = *(int *)new_socket;
  int valread;
  char buffer[1024] = {0};
  char *message = "Welcome to the Server\n";

  // Send Welcome Message to Client
  send(sfd, message, strlen(message), 0);

  // Receive the Message from Client
  valread = read(sfd, buffer, 1024);
  printf("Client: %s\n", buffer);

  // Send Acknowledgement Message to Client
  message = "Message Received\n";
  send(sfd, message, strlen(message), 0);

  // Closing the Socket
  close(sfd);
  return NULL;
}