//FormAI DATASET v1.0 Category: Networking ; Style: relaxed
/* 
A chatbot for a simple messaging application with server and client functionality 
Written by [Your Name]

Relax and enjoy this program
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
  int sock_fd;
  struct sockaddr_in server;
  char message[1024] = {0};

  // Creating socket file descriptor
  if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  memset(&server, '0', sizeof(server));

  // Port and address configuration
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);

  if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) <= 0) {
    perror("inet_pton error");
    exit(EXIT_FAILURE);
  }

  // Connecting to server
  if (connect(sock_fd, (struct sockaddr*)&server, sizeof(server)) < 0) {
    perror("connect error");
    exit(EXIT_FAILURE);
  }

  printf("Connection Established!\n");

  while (1) {
    memset(message, 0, sizeof(message));

    printf("Enter message to send: ");
    scanf("%[^\n]%*c", message);

    // Sending message to server
    int send_size = send(sock_fd, message, strlen(message), 0);

    if (send_size < 0) {
      perror("send error");
      exit(EXIT_FAILURE);
    }

    printf("Message sent!\n");

    // Receiving message from server
    char buffer[1024] = {0};
    int read_size = read(sock_fd, buffer, 1024);

    if (read_size < 0) {
      perror("read error");
      exit(EXIT_FAILURE);
    }

    printf("Server: %s\n", buffer);
  }

  return 0;
}