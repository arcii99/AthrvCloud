//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  if (sockfd < 0) {
    printf("Oh no! Socket creation failed.\n");
    exit(1);
  }
  
  printf("Wow! Socket successfully created.\n");
  
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_port = htons(8080);
  
  int con = connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
  
  if (con < 0) {
    printf("Oh no! Connection failed.\n");
    exit(1);
  }
  
  printf("Yay! Connection established.\n");
  
  char msg[100];
  printf("Enter a message to send: ");
  fgets(msg, sizeof(msg), stdin);
  
  int send_msg = send(sockfd, msg, strlen(msg), 0);
  
  if (send_msg < 0) {
    printf("Oh no! Message sending failed.\n");
    exit(1);
  }
  
  printf("Awesome! Message sent successfully.\n");
  
  char recv_msg[100];
  memset(recv_msg, 0, sizeof(recv_msg));
  
  int recv_result = recv(sockfd, recv_msg, sizeof(recv_msg), 0);
  
  if (recv_result < 0) {
    printf("Oh no! Message receiving failed.\n");
    exit(1);
  }
  
  printf("Woo hoo! Message received from server: %s\n", recv_msg);
  
  close(sockfd);
  printf("So long and thanks for all the fish. :)\n");
  
  return 0;
}