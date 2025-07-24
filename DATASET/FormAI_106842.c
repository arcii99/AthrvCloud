//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#define PORT 80

int main(int argc, char *argv[]) {
    if(argc<2) {
        printf("Usage: ./scanner <IP Address>\n");
        exit(1);
    }
    printf("Scanning %s...\n", argv[1]);
    struct sockaddr_in server;
    int sock=socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=inet_addr(argv[1]);
    for(int port=1; port<=65535; port++) {
        server.sin_port=htons(port);
        if(connect(sock, (struct sockaddr*)&server, sizeof(server))==0) {
            printf("Port %d is open!\n", port);
            close(sock);
            sock=socket(AF_INET, SOCK_STREAM, 0);
            server.sin_family=AF_INET;
            server.sin_addr.s_addr=inet_addr(argv[1]);
        }
    }
    printf("Scanning finished!\n");
    close(sock);
    return 0;
}