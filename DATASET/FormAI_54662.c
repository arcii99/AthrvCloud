//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_TRY 3
#define MAX_TIMEOUT 1

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("Usage: %s <target IPv4 address>\n", argv[0]);
    exit(1);
  }
  char *targetIP = argv[1];
  char *message = "Hello, is anyone there?";
  struct sockaddr_in targetAddr;
  targetAddr.sin_family = AF_INET;
  targetAddr.sin_port = htons(80);
  if(inet_pton(AF_INET, targetIP, &targetAddr.sin_addr) != 1) {
    printf("Invalid IP Address.\n");
    exit(1);
  }

  int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sock == -1) {
    printf("Unable to create socket.\n");
    exit(1);
  }

  struct timeval tv;
  tv.tv_sec = MAX_TIMEOUT;
  tv.tv_usec = 0;
  if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
    printf("Unable to set socket options.\n");
    exit(1);
  }

  if(connect(sock, (struct sockaddr *)&targetAddr, sizeof(targetAddr)) < 0) {
    printf("Unable to connect to target.\n");
    exit(1);
  }

  printf("Connection established with %s\n", targetIP);
  
  for (int i = 0; i < MAX_TRY; i++) {
    if (send(sock, message, strlen(message), 0) < 0) {
      printf("Error sending message.\n");
      exit(1);
    } else {
      printf("Message sent to %s: %s\n", targetIP, message);
    }

    char response[256];
    memset(response, 0, sizeof response);
    int bytesRecvd = recv(sock, response, sizeof(response), 0);
    if(bytesRecvd < 0) {
      printf("Unable to receive response from target.\n");
      exit(1);
    } else if(bytesRecvd == 0) {
      printf("Connection closed by %s.\n", targetIP);
      exit(0);
    } else {
      printf("Response from %s (%d bytes):\n%s\n", targetIP, bytesRecvd, response);
    }
    sleep(1);
  }

  close(sock);
  printf("Connection closed.\n");
  return 0;
}