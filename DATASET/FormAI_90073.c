//FormAI DATASET v1.0 Category: Firewall ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>

int main(){
    int sockfd, new_sockfd, retval;
    struct sockaddr_in host_addr, client_addr;
    socklen_t sin_size;
    char buffer[2048];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        perror("Error in creating socket");
        exit(EXIT_FAILURE);
    }
    memset(&host_addr, 0, sizeof(struct sockaddr_in));
    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(8000);
    host_addr.sin_addr.s_addr = INADDR_ANY;
    retval = bind(sockfd, (struct sockaddr*)&host_addr, sizeof(struct sockaddr));
    if(retval == -1){
        perror("Error in binding socket");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    retval = listen(sockfd, 5);
    if(retval == -1){
        perror("Error in listening socket");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("Listening on port: %d\n", 8000);
    while(1){
        sin_size = sizeof(struct sockaddr_in);
        new_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &sin_size);
        if(new_sockfd == -1){
            perror("Error in accepting incoming connection");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
        recv(new_sockfd, buffer, 2048, 0);
        struct iphdr *ip = (struct iphdr*)buffer;
        if(ip->protocol == IPPROTO_TCP) {
            struct tcphdr *tcp = (struct tcphdr*)(buffer + sizeof(struct iphdr));
            if(tcp->dest == htons(22)) {
                printf("Client with IP %s is trying to access SSH port\n", inet_ntoa(client_addr.sin_addr));
                continue;
            }
        }
        printf("Data received from Client with IP: %s\n", inet_ntoa(client_addr.sin_addr));
        printf("Data: %s\n", buffer);
        close(new_sockfd);
    }
    close(sockfd);
    return 0;
}