//FormAI DATASET v1.0 Category: Networking ; Style: shocked
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("ERROR: Incorrect number of arguments\n");
    printf("USAGE: ./networking-example <IP ADDRESS> <PORT>\n");
    exit(1);
  }

  int sock;
  struct sockaddr_in server_addr;
  char message[100];

  sock = socket(AF_INET, SOCK_STREAM, 0);

  if (sock == -1) {
    printf("ERROR: Failed to create socket\n");
    exit(1);
  }

  server_addr.sin_addr.s_addr = inet_addr(argv[1]);
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));

  if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    printf("ERROR: Failed to connect to server\n");
    exit(1);
  }

  printf("Connected to server!\n");
  printf("Enter a message to send: ");
  scanf("%[^\n]s", message);

  if (send(sock, message, strlen(message), 0) < 0) {
    printf("ERROR: Failed to send message\n");
    exit(1);
  }

  printf("Message sent successfully!\n");

  close(sock);

  return 0;
}