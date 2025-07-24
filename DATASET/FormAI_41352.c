//FormAI DATASET v1.0 Category: Client Server Application ; Style: unmistakable
/*
* This is a Client-Server Application in C which demonstrates the functionality of client
* sending a message string to the server which reverses the message string and sends it back
* to the client.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000 // Port number on which server is listening
#define MAX_BUF_SIZE 1024 // Maximum buffer size allowed

int main() {
  int sockfd = 0, clientfd = 0;   // Socket file descriptors
  struct sockaddr_in serv_addr, client_addr;  // Server and Client Address Structures
  char buf[MAX_BUF_SIZE];   // Input buffer for messages
  char rev[MAX_BUF_SIZE];   // Reversed buffer for messages
  int len, n = 0;    // Variables to store length of message and number of bytes read and written

  // Create Socket File Descriptor
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // Intialize Server Address Struct
  memset(&serv_addr, '0', sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(PORT);

  // Bind Socket to the Server Address
  bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

  // Listen to incoming client connections
  listen(sockfd, 10);

  // Loop to accept and serve incoming clients
  while(1) {
    // Accept incoming client connections
    len = sizeof(client_addr);
    clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &len);

    // Read data from the client
    n = read(clientfd, buf, MAX_BUF_SIZE);

    // Reverse the message string
    buf[n] = '\0';
    for(int i = 0; i < strlen(buf); i++) {
      rev[i] = buf[strlen(buf)-1-i];
    }
    rev[strlen(buf)] = '\0';

    // Send the reversed message back to the client
    write(clientfd, rev, strlen(rev));

    // Close the client connection
    close(clientfd);
  }
  return 0;
}