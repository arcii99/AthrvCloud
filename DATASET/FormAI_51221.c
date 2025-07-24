//FormAI DATASET v1.0 Category: Networking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main() {
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    perror("Failed to create socket");
    exit(1);
  }

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9000);
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

  int connection_status = connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address));
  if (connection_status == -1) {
    perror("Failed to connect to server");
    close(client_socket);
    exit(1);
  }
  
  char buffer[BUFFER_SIZE];
  memset(buffer, '\0', sizeof(buffer));

  printf("Connected to server. Enter a message: ");
  fgets(buffer, sizeof(buffer), stdin);

  int send_status = send(client_socket, buffer, strlen(buffer), 0);
  if (send_status == -1) {
    perror("Failed to send message");
    close(client_socket);
    exit(1);
  }

  printf("Message sent. Waiting for response...\n");

  int receive_status = recv(client_socket, buffer, sizeof(buffer), 0);
  if (receive_status == -1) {
    perror("Failed to receive message");
    close(client_socket);
    exit(1);
  }

  printf("Response received: %s\n", buffer);

  close(client_socket);
  return 0;
}