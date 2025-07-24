//FormAI DATASET v1.0 Category: Simple Web Server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>

int main() {
   int server_socket = socket(AF_INET, SOCK_STREAM, 0);
   struct sockaddr_in server_address;
   server_address.sin_family = AF_INET;
   server_address.sin_port = htons(8080);
   server_address.sin_addr.s_addr = INADDR_ANY;

   bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
   listen(server_socket, 5);

   while(1) {
      int client_socket = accept(server_socket, NULL, NULL);

      char response_headers[1024] = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\n";
      char response_data[1024] = "Hello World!";

      write(client_socket, response_headers, strlen(response_headers));
      write(client_socket, response_data, strlen(response_data));

      close(client_socket);
   }

   close(server_socket);
   return 0;
}