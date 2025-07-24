//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000 // default port

int main(int argc, char const *argv[]) {
  int sock = 0, valread;
  struct sockaddr_in serv_addr;

  // create socket
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("\n Socket creation error \n");
    return -1;
  }

  // set server address and port number
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  // convert IPv4 and IPv6 addresses from text to binary form
  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
    printf("\nInvalid address/ Address not supported \n");
    return -1;
  }

  // connect to server
  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("\nConnection Failed \n");
    return -1;
  }

  // simulate network traffic QoS
  while (1) {
    char buffer[1024] = {0};
    char message[256];
    int message_len;
    int bytes_received;
    int bytes_sent;

    // generate random message
    snprintf(message, 256, "This is a test message from client. Random number: %d", rand() % 1000);
    message_len = strlen(message);

    // send message to server
    bytes_sent = send(sock, message, message_len, 0);
    if (bytes_sent < 0) {
      printf("\nError sending message to server.\n");
      break;
    }

    // receive response from server
    bytes_received = recv(sock, buffer, 1024, 0);
    if (bytes_received < 0) {
      printf("\nError receiving response from server.\n");
      break;
    }

    // print response and sleep for random time
    printf("Received: %s\n", buffer);
    usleep((rand() % 1000) * 1000); // sleep for 0-1 second
  }

  close(sock);

  return 0;
}