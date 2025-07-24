//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8888
#define MAX_MSG_LENGTH 1024

int main() {
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0); // create TCP socket
  if (sock_fd < 0) {
    fprintf(stderr, "Error creating socket.\n");
    exit(1);
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    fprintf(stderr, "Error binding socket.\n");
    exit(1);
  }

  if (listen(sock_fd, 5) < 0) {
    fprintf(stderr, "Error listening on socket.\n");
    exit(1);
  }

  printf("Server is listening on port %d...\n", PORT);

  while (1) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_len); // accept incoming connection
    if (client_fd < 0) {
      fprintf(stderr, "Error accepting incoming connection.\n");
      continue;
    }

    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN); // get client IP address
    printf("Connected to client %s:%d\n", client_ip, ntohs(client_addr.sin_port));

    char msg[MAX_MSG_LENGTH];
    int msg_len = recv(client_fd, &msg, MAX_MSG_LENGTH, 0); // receive message from client
    if (msg_len < 0) {
      fprintf(stderr, "Error receiving message from client.\n");
      close(client_fd);
      continue;
    }

    printf("Received message from client: %s", msg);

    char reply[] = "Hello, client!\n";
    int reply_len = strlen(reply) + 1;

    if (send(client_fd, &reply, reply_len, 0) != reply_len) { // send reply to client
      fprintf(stderr, "Error sending message to client.\n");
      close(client_fd);
      continue;
    }

    close(client_fd);
  }

  close(sock_fd);
  return 0;
}