//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int server_socket, client_socket;
  struct sockaddr_in server_address, client_address;
  char response[1024], request[1024];

  // Create socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Bind socket to IP address and port
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(8080);

  bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

  // Listen for connections
  listen(server_socket, 5);

  while (1)
  {
    // Accept incoming connection
    int client_address_size = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&client_address_size);

    // Read client request
    read(client_socket, request, 1024);

    // Generate response
    sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, World!\r\n\r\n");
    
    // Send response to client
    write(client_socket, response, strlen(response));
    
    // Close socket
    close(client_socket);
  }

  return 0;
}