//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
  int sock = 0, valread;
  struct sockaddr_in serv_addr;
  char message[1024] = {0};
  char buffer[1024] = {0};
  int word_count = 0;
  int letter_count = 0;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("\n Socket creation error \n");
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
    printf("\nInvalid address/ Address not supported \n");
    return -1;
  }

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("\nConnection Failed \n");
    return -1;
  }

  printf("Enter a message: ");
  fgets(message, 1024, stdin);

  send(sock, message, strlen(message), 0);
  printf("Message sent to server.\n");

  valread = read(sock, buffer, 1024);
  buffer[valread] = '\0';

  for (int i = 0; i < strlen(buffer); i++) {
    if (buffer[i] != ' ') letter_count++;
    else word_count++;
  }
  word_count++;

  printf("Server response: %s\n", buffer);
  printf("Word count: %d\n", word_count);
  printf("Letter count: %d\n", letter_count);

  return 0;
}