//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(){
  int server_socket, client_socket;
  struct sockaddr_in server_address, client_address;
  socklen_t addr_size;
  char recv_buffer[1024];

  // Create the server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    perror("Error creating server socket");
    exit(EXIT_FAILURE);
  }

  // Initialize server address and bind the socket to it
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(8080); // port number of the server

  if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
    perror("Error binding socket");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections and accept them
  if (listen(server_socket, 5) < 0) {
    perror("Error listening");
    exit(EXIT_FAILURE);
  }

  printf("Server is listening on port %d...\n", ntohs(server_address.sin_port));

  while (1) {
    addr_size = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr*) &client_address, &addr_size);
    if (client_socket < 0) {
      perror("Error accepting client connection");
      exit(EXIT_FAILURE);
    }

    printf("Client %s:%d connected\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    // Read incoming request from the client and send the response back
    while (recv(client_socket, recv_buffer, sizeof(recv_buffer), 0) > 0) {
      printf("%s\n", recv_buffer);
      send(client_socket, "OK", 2, 0);
    }

    close(client_socket);
    printf("Client %s:%d disconnected\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
  }

  return 0;
}