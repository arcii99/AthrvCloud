//FormAI DATASET v1.0 Category: Simple Web Server ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to handle the incoming HTTP requests
void handle_request(int client_socket) {
   char buffer[1024];
   memset(buffer, 0, sizeof(buffer));
   int recv_length = recv(client_socket, buffer, sizeof(buffer), 0);
   if (recv_length <= 0) {
      close(client_socket);
      return;
   }
   printf("%s\n", buffer); // Print the HTTP request
   char html[] = "<html><body><h1>Hello, World!</h1></body></html>";
   char response[1024];
   memset(response, 0, sizeof(response));
   sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\nContent-Type: text/html\r\n\r\n%s", strlen(html), html);
   send(client_socket, response, strlen(response), 0);
   close(client_socket);
}

int main(int argc, char *argv[]) {
   int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
   if (server_socket == -1) {
      perror("Error creating socket");
      exit(EXIT_FAILURE);
   }
   int port_number = 8080;
   struct sockaddr_in server_address;
   memset(&server_address, 0, sizeof(server_address));
   server_address.sin_family = AF_INET;
   server_address.sin_addr.s_addr = INADDR_ANY;
   server_address.sin_port = htons(port_number);
   if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
      perror("Error binding socket");
      exit(EXIT_FAILURE);
   }
   if (listen(server_socket, 10) == -1) {
      perror("Error listening on socket");
      exit(EXIT_FAILURE);
   }
   printf("Simple Web Server is listening on port %d...\n", port_number);
   while (1) {
      struct sockaddr_in client_address;
      socklen_t client_address_length = sizeof(client_address);
      int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
      if (client_socket == -1) {
         perror("Error accepting client connection");
         continue;
      }
      handle_request(client_socket);
   }
   close(server_socket);
   return 0;
}