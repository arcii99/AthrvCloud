//FormAI DATASET v1.0 Category: Socket programming ; Style: genious
// A Genius Style Example Program for C Socket Programming
// This program establishes a server-client connection using sockets and sends a message back and forth
// Written by [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(){
   int server_fd, client_fd;
   struct sockaddr_in server_address, client_address;
   int opt = 1;
   int addrlen = sizeof(server_address);
   char buffer[BUFFER_SIZE] = {0};
   char *hello = "Hello from server";

   // Create the socket
   if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
      perror("Socket creation failed");
      exit(EXIT_FAILURE);
   }
   
   // Set socket options
   if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
      perror("Setting socket options failed");
      exit(EXIT_FAILURE);
   }
   
   // Initialize server_address properties
   server_address.sin_family = AF_INET;
   server_address.sin_addr.s_addr = INADDR_ANY;
   server_address.sin_port = htons( PORT );

   // Bind the socket to the specified IP and port
   if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address))<0){
      perror("Socket binding failed");
      exit(EXIT_FAILURE);
   }

   // Wait for incoming client connections
   if (listen(server_fd, 3) < 0){
      perror("Listening for clients failed");
      exit(EXIT_FAILURE);
   }
   
   // Accept incoming client connections and communicate with them
   while(1){
      if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&addrlen))<0){
         perror("Client connection failed");
         exit(EXIT_FAILURE);
      }
      
      // Read incoming client message
      int valread = read(client_fd , buffer, BUFFER_SIZE);
      printf("Received message from client: %s\n",buffer );
      
      // Send message back to client
      send(client_fd , hello , strlen(hello) , 0 );
      printf("Message sent to client\n");
   }
   
   return 0;
}