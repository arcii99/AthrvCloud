//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
  int socket_fd;
  struct sockaddr_in server_address;
  char *message = "Hello, Artistic Programming!\n";
  char buffer[1024] = {0};

  if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      perror("Socket creation error");
      exit(EXIT_FAILURE);
  }

  memset(&server_address, '0', sizeof(server_address));

  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);

  if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
      perror("Invalid address/ Address not supported");
      exit(EXIT_FAILURE);
  }

  if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
      perror("Connection failed");
      exit(EXIT_FAILURE);
  }

  send(socket_fd, message, strlen(message), 0);
  printf("Hello message sent\n");

  /* Chatting with the server and showing the response from the server */
  while (1) {
      memset(buffer, 0, sizeof(buffer));
      printf("Your message: ");
      scanf("%[^\n]%*c", &buffer);
      send(socket_fd, buffer, strlen(buffer), 0);
      printf("Message sent\n");
      read(socket_fd, buffer, sizeof(buffer));
      printf("Server says: %s\n", buffer);
  }

  return 0;
}