//FormAI DATASET v1.0 Category: Port Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT_START 1
#define PORT_END 65535
#define BUFFER_SIZE 256

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {

  int sockfd, portno;
  struct sockaddr_in serv_addr;
  char buffer[BUFFER_SIZE];
  char ip_address[BUFFER_SIZE];
  int err;

  if (argc < 2) {
     fprintf(stderr,"Usage: %s hostname\n", argv[0]);
     exit(1);
  }

  printf("Welcome to Medieval Port Scanner!\n\n");
  printf("Enter the IP address you would like to scan: ");
  fgets(ip_address, BUFFER_SIZE, stdin);

  for(portno = PORT_START; portno <= PORT_END; portno++) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
      error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &serv_addr.sin_addr);
    serv_addr.sin_port = htons(portno);

    err = connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (err == 0) {
        printf("Port %d is open!\n", portno);
    }
    close(sockfd);
  }

  printf("\nAll done! May the sun shine upon your code.");

  return 0;
}