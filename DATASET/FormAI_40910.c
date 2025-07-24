//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Failed to create socket!");
    exit(1);
  }

  struct sockaddr_in serverAddr;
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(PORT);
  serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
    perror("Failed to bind socket!");
    exit(1);
  }

  if (listen(sockfd, 10) < 0) {
    perror("Failed to listen on socket!");
    exit(1);
  }

  while (1) {
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    int clientSockfd = accept(sockfd, (struct sockaddr*)&clientAddr, &clientAddrLen);
    if (clientSockfd < 0) {
      perror("Failed to accept client connection!");
      exit(1);
    }

    char reqBuffer[1024] = {0};
    int numBytesRead = read(clientSockfd, reqBuffer, 1023);
    if (numBytesRead < 0) {
      perror("Failed to read request from client!");
      exit(1);
    }

    char* proxyUrl = "proxy.example.com";
    int proxyPort = 80;

    struct hostent* proxyHost = gethostbyname(proxyUrl);
    if (!proxyHost) {
      perror("Failed to get proxy host!");
      exit(1);
    }

    struct sockaddr_in proxyAddr;
    memset(&proxyAddr, 0, sizeof(proxyAddr));
    proxyAddr.sin_family = AF_INET;
    proxyAddr.sin_addr = *(struct in_addr*)proxyHost->h_addr_list[0];
    proxyAddr.sin_port = htons(proxyPort);

    int proxySockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxySockfd < 0) {
      perror("Failed to create proxy socket!");
      exit(1);
    }

    if (connect(proxySockfd, (struct sockaddr*)&proxyAddr, sizeof(proxyAddr)) < 0) {
      perror("Failed to connect to proxy!");
      exit(1);
    }

    if (write(proxySockfd, reqBuffer, numBytesRead) < 0) {
      perror("Failed to write request to proxy!");
      exit(1);
    }

    char resBuffer[1024] = {0};
    numBytesRead = read(proxySockfd, resBuffer, 1023);
    if (numBytesRead < 0) {
      perror("Failed to read response from proxy!");
      exit(1);
    }

    if (write(clientSockfd, resBuffer, numBytesRead) < 0) {
      perror("Failed to write response to client!");
      exit(1);
    }

    close(clientSockfd);
    close(proxySockfd);
  }

  return 0;
}