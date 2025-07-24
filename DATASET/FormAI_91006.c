//FormAI DATASET v1.0 Category: Network Ping Test ; Style: invasive
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/time.h>
#include<string.h>
#define PORT_NUM 80

int ping(char *ip_address){
    
    struct sockaddr_in server_sockaddr;
    int sockfd, result;
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    bzero(&server_sockaddr, sizeof(server_sockaddr));

    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(PORT_NUM);
    inet_pton(AF_INET, ip_address, &server_sockaddr.sin_addr);

    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 500000;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv); 
    
    result = connect(sockfd, (struct sockaddr *)&server_sockaddr, sizeof(server_sockaddr));
    close(sockfd);

    if(result == 0) { 
        printf("Ping result for %s: Success\n", ip_address);
        return 1;
    } else {
        printf("Ping result for %s: Failed\n", ip_address);
        return 0;
    }
}

int main(int argc, char **argv){
    if(argc < 2){ 
        printf("Incorrect usage. Use: %s [IP Address]\n", argv[0]);
        exit(1);
    }
    ping(argv[1]); 
    return 0;
}