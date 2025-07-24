//FormAI DATASET v1.0 Category: Socket programming ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BACKLOG 10

int main() {
   int server_fd, new_socket, valread;
   struct sockaddr_in address;
   int opt = 1;
   int addrlen = sizeof(address);
   char buffer[1024] = {0};
   char *hello = "Hello from server";

   // Creating socket file descriptor
   if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
      perror("socket failed");
      exit(EXIT_FAILURE);
   }
   
   // Attaching socket to the port 8080
   if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
      &opt, sizeof(opt))) {
      perror("setsockopt");
      exit(EXIT_FAILURE);
   }
   
   address.sin_family = AF_INET;
   address.sin_addr.s_addr = INADDR_ANY;
   address.sin_port = htons( PORT );
   
   // Binding socket to the address and port number
   if (bind(server_fd, (struct sockaddr *)&address,
      sizeof(address))<0) {
      perror("bind failed");
      exit(EXIT_FAILURE);
   }
   
   // Listening for client connections
   if (listen(server_fd, BACKLOG) < 0) {
      perror("listen");
      exit(EXIT_FAILURE);
   }
   
   // Accepting client connections
   if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
      (socklen_t*)&addrlen))<0) {
      perror("accept");
      exit(EXIT_FAILURE);
   }
   
   // Sending a message to the connected client
   send(new_socket, hello, strlen(hello), 0);
   printf("Hello message sent\n");
   
   // Reading the message sent by the client
   valread = read(new_socket, buffer, 1024);
   printf("%s\n",buffer );
   
   // Closing the socket
   close(new_socket);
   close(server_fd);
   
   return 0;
}