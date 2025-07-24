//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5555
#define MAX_DATA_SIZE 100

int main() {
    int sockfd, numbytes;
    char send_data[MAX_DATA_SIZE], recv_data[MAX_DATA_SIZE];
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    memset(serv_addr.sin_zero, '\0', sizeof(serv_addr.sin_zero));

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to server.\n");
    while(1) {
        printf("Enter data to send: ");
        fgets(send_data, MAX_DATA_SIZE, stdin);
        send(sockfd, send_data, strlen(send_data), 0);

        numbytes = recv(sockfd, recv_data, MAX_DATA_SIZE-1, 0);
        recv_data[numbytes] = '\0';

        printf("Received data from server: %s\n", recv_data);
    }

    close(sockfd);
    return 0;
}