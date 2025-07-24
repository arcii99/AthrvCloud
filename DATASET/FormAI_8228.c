//FormAI DATASET v1.0 Category: Client Server Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_MSG_LEN 2000
#define PORT 8080

void serve_client(int sock) {
  char msg[MAX_MSG_LEN] = {0};
  while (1) {
    memset(msg, 0, MAX_MSG_LEN);
    int read_val = recv(sock, msg, MAX_MSG_LEN, 0);
    if (read_val <= 0) {
      break;
    }
    printf("Client message: %s\n", msg);
    send(sock, msg, strlen(msg), 0);
    if (strcmp(msg, "exit") == 0) {
      break;
    }
  }
}

int main(int argc, char const *argv[]) {
  int server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock == -1) {
    printf("Hippity Hoppity, the socket creation has failed.\n");
    return -1;
  }

  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(server_sock, (struct sockaddr *)&address, sizeof(address)) < 0 ) {
    printf("Server couldn't bind. Something went wrong.\n");
    return -1;
  }

  if (listen(server_sock, 3) < 0) {
    printf("Server could not listen. Something went wrong.\n");
    return -1;
  }

  printf("Server listening on port %d\n", PORT);

  while (1) {
    struct sockaddr_in client_address;
    int client_sock;
    int address_len = sizeof(client_address);
    if ((client_sock = accept(server_sock, (struct sockaddr *)&client_address, (socklen_t *)&address_len)) < 0) {
      printf("Server failed to accept a client.\n");
      return -1;
    }
    printf("Client connected.\n");
    serve_client(client_sock);
    close(client_sock);
    printf("Client disconnected.\n");
  }
  return 0;
}