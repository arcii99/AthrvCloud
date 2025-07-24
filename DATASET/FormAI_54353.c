//FormAI DATASET v1.0 Category: Socket programming ; Style: energetic
// Energized C Socket Programming Example
// By Chatbot

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char *argv[]) {

  int sock = 0, valread;
  struct sockaddr_in serv_addr;
  char *hello = "Hello from the client!";
  char buffer[1024] = {0};

  // Create a socket
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("\n Socket creation error \n");
    return -1;
  }

  // Convert IPv4 and IPv6 addresses from text to binary form
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
    printf("\nInvalid address/ Address not supported \n");
    return -1;
  }

  // Connect to the server
  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("\nConnection Failed \n");
    return -1;
  }

  // Send message to the server
  send(sock, hello, strlen(hello), 0);
  printf("Client: Hello message sent!\n");

  // Read server response
  valread = read(sock, buffer, 1024);
  printf("Client: Server response: %s\n", buffer);

  // Close the socket
  close(sock);

  return 0;
}