//FormAI DATASET v1.0 Category: Networking ; Style: lively
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
  
  // define the server address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;
  
  // bind the socket to the specified IP address and port number
  bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
  
  // listen to incoming connections
  listen(server_socket, 5);
  
  // accept incoming connections
  int client_socket;
  while (1) {
    client_socket = accept(server_socket, NULL, NULL);
    
    // receive data from the client
    char client_message[256];
    recv(client_socket, &client_message, sizeof(client_message), 0);

    // reverse the message
    int len = strlen(client_message);
    char reversed_message[256];
    for (int i = 0; i < len; i++) {
        reversed_message[i] = client_message[len - i - 1];
    }
    reversed_message[len] = '\0';
    
    // send the reversed message back to the client
    send(client_socket, reversed_message, sizeof(reversed_message), 0);

    // close the client socket
    close(client_socket);
  }

  // close the server socket
  close(server_socket);

  return 0;
}