//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define SA struct sockaddr

void monitor_network_qos(){
  //setup socket
  int sockfd, connfd;
  struct sockaddr_in servaddr, cli;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("socket creation failed...\n");
    exit(0);
  }
  else
    printf("Socket successfully created..\n");
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);

  //bind socket with ip address and port number
  if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
    printf("socket bind failed...\n");
    exit(0);
  }
  else
    printf("Socket successfully binded..\n");

  //listen for incoming connections
  if ((listen(sockfd, 5)) != 0) {
    printf("Listen failed...\n");
    exit(0);
  }
  else
    printf("Server listening..\n");
  socklen_t len = sizeof(cli);

  while(1){
    //accept connections
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
      printf("Server accept failed...\n");
      exit(0);
    }
    else
      printf("Server accept the client...\n");

    char buffer[256];
    int n;
    bzero(buffer, sizeof(buffer)); //clear buffer before read
    n = read(connfd, buffer, sizeof(buffer)); //read data from client
    int latency = rand() % 200;
    float bandwidth = (((float)rand()/(float)(RAND_MAX)) * 10); //random bandwidth between 0 and 10 mbps
    printf("Latency: %dms \tBandwidth: %f mbps\n", latency, bandwidth);

    //write network qos data back to client
    char qos[256];
    sprintf(qos, "Latency: %dms \tBandwidth: %f mbps\n", latency, bandwidth);
    write(connfd, qos, sizeof(qos));
    close(connfd); //close connection
  }
  close(sockfd); //close socket
}

int main(){
  monitor_network_qos();
  return 0;
}