//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: introspective
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

  int sock;
  struct sockaddr_in server;
  char message[1024], response[4096];

  // Create socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Failed to create socket");
    return 1;
  }

  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_family = AF_INET;
  server.sin_port = htons( 80 );

  // Connect to remote server
  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    printf("Failed to connect to server");
    return 1;
  }

  printf("Connected to server\n");

  // Prepare HTTP request
  sprintf(message, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n");

  // Send HTTP request
  if (send(sock, message, strlen(message), 0) < 0) {
    printf("Failed to send HTTP request");
    return 1;
  }

  printf("HTTP request sent\n");

  // Receive HTTP response
  if (recv(sock, response, 4096, 0) < 0) {
    printf("Failed to receive HTTP response");
    return 1;
  }

  printf("HTTP response received:\n");
  printf("%s", response);

  close(sock);
  return 0;
}