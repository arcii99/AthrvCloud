//FormAI DATASET v1.0 Category: Networking ; Style: energetic
// Energized Networking Program

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

int main(){

   int serverSocket, newSocket, readVal, opt = 1;
   struct sockaddr_in address;
   int addrlen = sizeof(address);

   char buffer[1024] = {0};
   char *greeting = "Hello World!";

   // Creating a new server socket
   if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
      perror("Socket Creation Failed! Exiting...");
      exit(EXIT_FAILURE);
   }

   // Setting socket options for reuse
   if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
      perror("setsockopt Failed! Exiting...");
      exit(EXIT_FAILURE);
   }

   // Setting up socket address
   address.sin_family = AF_INET;
   address.sin_addr.s_addr = INADDR_ANY;
   address.sin_port = htons( PORT );

   // Binding socket to the address
   if (bind(serverSocket, (struct sockaddr *)&address, sizeof(address))<0) {
      perror("Bind Failed! Exiting...");
      exit(EXIT_FAILURE);
   }

   // Listening for new clients
   if (listen(serverSocket, 3) < 0) {
      perror("Listen Failed! Exiting...");
      exit(EXIT_FAILURE);
   }

   // Waiting for connection by a client
   if ((newSocket = accept(serverSocket, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
      perror("Accept Failed! Exiting...");
      exit(EXIT_FAILURE);
   }

   // Sending the greeting message to the client
   send(newSocket , greeting , strlen(greeting) , 0 );

   // Receiving message from client
   readVal = read( newSocket , buffer, 1024);
   printf("%s\n",buffer );

   close(serverSocket);
   return 0;
}