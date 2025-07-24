//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MESSAGE 500
#define PORT_NUMBER 8080

void respond(int sockfd) {
  char message[MAX_MESSAGE];
  char* response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\nHello, Cyberpunk World!";
  recv(sockfd, message, MAX_MESSAGE, 0);
  send(sockfd, response, strlen(response), 0);
  close(sockfd);
}

int main() {
  int socket_desc, new_socket, c;
  struct sockaddr_in server, client;

  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_desc == -1) {
    printf("Could not create socket");
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(PORT_NUMBER);

  if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    printf("Bind failed");
    return 1;
  }

  listen(socket_desc, 3);
  printf("Listening on port %d\n", PORT_NUMBER);

  while (1) {
    c = sizeof(struct sockaddr_in);

    new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (new_socket < 0) {
      printf("Could not accept connection");
      return 1;
    }

    respond(new_socket);
  }

  return 0;
}