//FormAI DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 9000

int main() {
  int sockfd;
  struct sockaddr_in serv_addr;

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Set up server address
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Connect to server
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // Send message to server
  char message[255] = "Hello server, this is the client.";
  if (send(sockfd, message, strlen(message), 0) < 0) {
    perror("ERROR sending message");
    exit(1);
  }

  // Receive message from server
  char response[255];
  if (recv(sockfd, response, sizeof(response), 0) < 0) {
    perror("ERROR receiving message");
    exit(1);
  }

  printf("Server said: %s\n", response);

  // Close socket
  close(sockfd);

  return 0;
}