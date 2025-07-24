//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
  // Creating socket file descriptor
  int sockfd = 0;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("\n Error: Could not create socket\n");
    return -1;
  }

  struct sockaddr_in serv_addr;
  memset(&serv_addr, '0', sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  // Convert IPv4 and IPv6 addresses from text to binary form
  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
    printf("\n Error: Invalid address/Address not supported\n");
    return -1;
  }

  // Connecting to server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("\n Error: Connection Failed\n");
    return -1;
  }

  char receive_buffer[1000] = {0};
  char send_buffer[1000] = {0};

  while (1) {
    memset(receive_buffer, 0, sizeof(receive_buffer));
    printf("Enter message to send: ");
    fgets(send_buffer, sizeof(send_buffer), stdin);

    if (send(sockfd, send_buffer, strlen(send_buffer), 0) == -1) {
      printf("\n Error: Data not sent\n");
      return -1;
    }

    if (recv(sockfd, receive_buffer, sizeof(receive_buffer), 0) == -1) {
      printf("\n Error: Data not received\n");
      return -1;
    }

    printf("Server Response: %s\n", receive_buffer);
  }

  return 0;
}