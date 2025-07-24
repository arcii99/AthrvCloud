//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdbool.h>

#define MAX_PACKET_SIZE 1024
#define SERVER_PORT 8888

int sockfd;
struct sockaddr_in servaddr;


void initSock(){
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(SERVER_PORT);

    bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
}

void check_qos(int ip){
    int send = ip;
    sendto(sockfd, &send, sizeof(send), 0, (struct sockaddr*) &servaddr, sizeof(servaddr));

    int recv;
    recvfrom(sockfd, &recv, sizeof(recv), 0, NULL, NULL);

    if (recv != 0){
        printf("The QoS is low!\n");
    } else {
        printf("The QoS is good!\n");
    }
}

int main(){
    initSock();

    printf("Enter the IP address to check QoS: ");
    char ip_addr[100];
    fgets(ip_addr, 100, stdin);
    int ip = atoi(ip_addr);

    check_qos(ip);

    return 0;
}