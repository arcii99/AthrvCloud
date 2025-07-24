//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

#define PORT 8080
#define BUFF_SIZE 1024

int main(int argc, char *argv[])
{
    int sock = 0, conn = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFF_SIZE] = {0};

    // Create socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0){
        perror("Invalid address or Address not supported");
        return -1;
    }

    // Connect to server
    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        perror("Connection error");
        return -1;
    }

    while(1){
        struct timeval start, end;
        gettimeofday(&start, NULL);
        send(sock , buffer , strlen(buffer) , 0 );
        read( sock , buffer, BUFF_SIZE);
        gettimeofday(&end, NULL);
        printf("Time taken: %ld microseconds\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
        usleep(500000);
    }

    close(sock);
    return 0;
}