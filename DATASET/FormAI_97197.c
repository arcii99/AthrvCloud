//FormAI DATASET v1.0 Category: Client Server Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main() {
   int client_socket, server_socket;
   struct sockaddr_in server_address, client_address;
   char message[1024], server_response[1024];
   socklen_t client_address_size = sizeof(client_address);
   
   // create server socket
   server_socket = socket(AF_INET, SOCK_STREAM, 0);
   if (server_socket == -1) {
      perror("Server Socket Creation Failed");
      return 1;
   }
   printf("Server Socket Created Successfully!\n");
   
   // configure server address
   server_address.sin_family = AF_INET;
   server_address.sin_addr.s_addr = INADDR_ANY;
   server_address.sin_port = htons(8080);
   
   // bind server socket to address
   if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
      perror("Server Socket Binding Failed");
      close(server_socket);
      return 1;
   }
   printf("Server Socket Bound Successfully!\n");
   
   // start listening for incoming client connections
   if (listen(server_socket, 5) == -1) {
      perror("Server Socket Listening Failed");
      close(server_socket);
      return 1;
   }
   printf("Server Waiting For Client Connections...\n");
   
   // accept incoming client connection
   client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
   if (client_socket == -1) {
      perror("Client Connection Acceptance Failed");
      close(server_socket);
      return 1;
   }
   printf("Client Connected Successfully!\n");
   
   // receive message from client
   memset(server_response, 0, sizeof(server_response));
   if (recv(client_socket, server_response, sizeof(server_response), 0) == -1) {
      perror("Message Reception Failed");
      close(client_socket);
      close(server_socket);
      return 1;
   }
   printf("Client: %s\n", server_response);
   
   // send response message to client
   printf("Server: ");
   fgets(message, sizeof(message), stdin);
   if (send(client_socket, message, strlen(message), 0) == -1) {
      perror("Message Sending Failed");
      close(client_socket);
      close(server_socket);
      return 1;
   }
   printf("Response Message Sent Successfully!\n");
   
   // close client and server sockets
   close(client_socket);
   close(server_socket);
   return 0;
}