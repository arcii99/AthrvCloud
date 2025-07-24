//FormAI DATASET v1.0 Category: Firewall ; Style: enthusiastic
#include<stdio.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if(sock_raw < 0) {
        perror("Socket error");
        return 1;
    }

    char buffer[65535];
    memset(buffer, 0, sizeof(buffer));

    struct sockaddr_in server_address, client_address;
    memset(&server_address, 0, sizeof(server_address));
    memset(&client_address, 0, sizeof(client_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8888);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sock_raw, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind error");
        return 1;
    }

    listen(sock_raw, 10);

    printf("Firewall is ready to do its magic!\n");

    while(1) {
        int client_address_size = sizeof(client_address);
        int client_socket = accept(sock_raw, (struct sockaddr *)&client_address, (socklen_t *)&client_address_size);
        if(client_socket < 0) {
            perror("Accepting client error");
            return 1;
        }

        struct sockaddr_in *s = (struct sockaddr_in *)&client_address;
        printf("Incoming connection from %s:%d\n", inet_ntoa(s->sin_addr), ntohs(s->sin_port));

        memset(buffer, 0, sizeof(buffer));
        int len = recv(client_socket, buffer, sizeof(buffer), 0);

        if(len < 0) {
            perror("Receiving data error");
            return 1;
        }

        struct iphdr *ipheader = (struct iphdr *)buffer;
        struct tcphdr *tcpheader = (struct tcphdr *)(buffer + sizeof(struct iphdr));

        if(tcpheader->syn && !tcpheader->ack) {
            printf("SYN packet detected. Blocking the connection.\n");
            close(client_socket);
            continue;
        }

        printf("Connection allowed.\n");
        send(client_socket, "Hello, welcome to the firewall protected server!\n", 50, 0);
        close(client_socket);
    }

    close(sock_raw);
    return 0;
}