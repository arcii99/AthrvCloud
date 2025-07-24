//FormAI DATASET v1.0 Category: Socket programming ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
   // create a socket
   int server_socket = socket(AF_INET, SOCK_STREAM, 0);
   if (server_socket < 0) {
      perror("Failed to create socket");
      exit(1);
   }

   // bind the socket to an IP address and port
   struct sockaddr_in server_address;
   server_address.sin_family = AF_INET;
   server_address.sin_port = htons(8080);
   server_address.sin_addr.s_addr = INADDR_ANY;
   int bind_result = bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
   if (bind_result < 0) {
      perror("Failed to bind socket");
      exit(1);
   }

   // listen for incoming connections
   listen(server_socket, 5);
   printf("Server listening on port 8080...\n");

   // accept incoming client connections
   int client_socket;
   struct sockaddr_in client_address;
   socklen_t client_address_len = sizeof(client_address);
   client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_len);
   if (client_socket < 0) {
      perror("Failed to accept client connection");
      exit(1);
   }

   // communicate with the client
   char buffer[256];
   memset(buffer, 0, 256);
   int num_bytes = read(client_socket, buffer, 255);
   if (num_bytes < 0) {
      perror("Failed to read from client socket");
      exit(1);
   }
   printf("Received message from client: %s", buffer);

   const char* reply = "Hello from server!";
   num_bytes = write(client_socket, reply, strlen(reply));
   if (num_bytes < 0) {
      perror("Failed to write to client socket");
      exit(1);
   }

   // close sockets
   close(client_socket);
   close(server_socket);
   return 0;
}