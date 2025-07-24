//FormAI DATASET v1.0 Category: Networking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
  int client_socket = 0;
  struct sockaddr_in server_address;
  char buffer[1024] = {0};
  char *message = "Hello from client";

  if((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("\n Error: Could not create socket \n");
    return -1;
  }

  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);

  if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
    printf("\n Error: Invalid Address \n");
    return -1;
  }

  if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    printf("\n Error: Connection failed \n");
    return -1;
  }

  send(client_socket, message, strlen(message), 0);

  printf("Message sent to server: %s\n", message);

  memset(buffer, 0, sizeof(buffer));

  read(client_socket, buffer, 1024);

  printf("Message received from server: %s\n", buffer);

  close(client_socket);

  return 0;
}