//FormAI DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  // check if ip and port arguments were passed
  if (argc != 3) {
    printf("Usage: %s <ip address> <port number>\n", argv[0]);
    return 0;
  }

  // convert port number to integer
  int port = atoi(argv[2]);

  // create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error: could not create socket\n");
    return 0;
  }

  // setup server address struct
  struct hostent *server = gethostbyname(argv[1]);
  struct sockaddr_in server_address;
  bzero((char *)&server_address, sizeof(server_address));
  server_address.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
  server_address.sin_port = htons(port);

  // connect to server
  if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    printf("Port %d is closed on %s\n", port, argv[1]);
    return 0;
  }

  printf("Port %d is open on %s\n", port, argv[1]);

  // close socket
  close(sockfd);
  
  return 0;
}