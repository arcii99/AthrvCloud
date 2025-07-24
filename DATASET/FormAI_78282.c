//FormAI DATASET v1.0 Category: Firewall ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>

int main() {
    int sockfd, connfd, len, n;
    struct sockaddr_in servaddr, cliaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        printf("Socket creation failed.\n");
        exit(0);
    }
    else {
        printf("Socket created successfully.\n");
    }
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8080);
    if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Socket bind failed.\n");
        exit(0);
    }
    else {
        printf("Socket bind successful.\n");
    }
    if(listen(sockfd, 5) != 0) {
        printf("Listen failed.\n");
        exit(0);
    }
    else {
        printf("Server listening on port 8080.\n");
    }
    for(;;) {
        len = sizeof(cliaddr);
        connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
        if(connfd < 0) {
            printf("Server accept failed.\n");
            exit(0);
        }
        else {
            printf("Server accepted the client.\n");
        }
        struct iphdr iph;
        struct tcphdr tcph;
        char buffer[1024] = {0};
        n = read(connfd, buffer, sizeof(buffer));
        memcpy((void *)&iph, (void *)buffer, sizeof(struct iphdr));
        memcpy((void *)&tcph, (void *)(buffer + sizeof(struct iphdr)), sizeof(struct tcphdr));
        if(tcph.syn == 1 && tcph.ack == 0) {
            printf("Syn packet received.\n");
            printf("Dropping the packet.\n");
            close(connfd);
        }
        else {
            printf("Forwarding the packet.\n");
            write(connfd, "HTTP/1.1 200 OK\n", 16);
            close(connfd);
        }
    }
    return 0;
}