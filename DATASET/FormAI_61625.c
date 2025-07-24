//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <math.h>

#define PORT 80

int main(int argc, char *argv[]) {
  // check if user provides the right arguments
  if (argc != 2) {
    printf("Usage: %s <IP address>\n", argv[0]);
    return 1;
  }
  
  // create the socket
  int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sockfd == -1) {
    perror("Error: cannot create the socket");
    return 1;
  }
  
  // set up the server address
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
  
  // connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("Error: cannot connect to the server");
    close(sockfd);
    return 1;
  }
  
  // perform the scan
  printf("IP address: %s\n", argv[1]);
  printf("Open ports: ");
  int found_open_port = 0;
  for (int port = 1; port < 65535; port++) {
    // create a new socket for each port
    int sock_port = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_port == -1) {
      perror("Error: cannot create the socket");
      break;
    }
  
    // set up the server address for the port
    struct sockaddr_in serv_port;
    memset(&serv_port, 0, sizeof(serv_port));
    serv_port.sin_family = AF_INET;
    serv_port.sin_port = htons(port);
    inet_pton(AF_INET, argv[1], &serv_port.sin_addr);
    
    // connect to the server on the port
    if (connect(sock_port, (struct sockaddr *)&serv_port, sizeof(serv_port)) == 0) {
      // port is open
      found_open_port = 1;
      printf("%d ", port);
    }
    
    // close the socket for the port
    close(sock_port);
  }
  
  // clean up and return
  printf("\n");
  if (!found_open_port) {
    printf("No open ports found\n");
  }
  close(sockfd);
  return 0;
}