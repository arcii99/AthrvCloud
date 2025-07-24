//FormAI DATASET v1.0 Category: Networking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int client_socket;
  struct sockaddr_in server_address;
  char message[1000], server_reply[2000];

  // Create a socket (IPv4, TCP)
  if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    printf("Could not create socket\n");
    return 1;
  }

  // Set up the server address and port
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_address.sin_port = htons(8080);

  // Connect to the server
  if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
    printf("Could not connect to server\n");
    return 1;
  }

  // Send a message to the server
  sprintf(message, "Hello world!");
  if (send(client_socket, message, strlen(message), 0) == -1) {
    printf("Could not send message to server\n");
    return 1;
  }

  // Receive a reply from the server
  if (recv(client_socket, server_reply, 2000, 0) < 0) {
    printf("Could not receive message from server\n");
    return 1;
  }

  printf("Server reply: %s\n", server_reply);

  // Close the socket
  close(client_socket);

  return 0;
}