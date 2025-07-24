//FormAI DATASET v1.0 Category: Firewall ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 65536

int main()
{
    int sock, bytes;
    struct sockaddr_in server, client;
    socklen_t client_len;
    char buffer[BUFFER_SIZE];

    //create socket
    sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock < 0)
    {
        perror("socket failed");
        return 1;
    }

    //set server details
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(8888);

    //bind socket to server
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("bind failed");
        return 1;
    }

    //listen for incoming connections
    if (listen(sock, 5) < 0)
    {
        perror("listen failed");
        return 1;
    }

    while (true)
    {
        //accept incoming connection
        client_len = sizeof(client);
        int client_sock = accept(sock, (struct sockaddr *)&client, &client_len);
        if (client_sock < 0)
        {
            perror("accept failed");
            return 1;
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        //read incoming packet
        memset(buffer, 0, BUFFER_SIZE);
        bytes = recvfrom(client_sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client, &client_len);
        if (bytes < 0)
        {
            perror("recvfrom failed");
            return 1;
        }

        //check if packet contains HTTP request
        if (strstr(buffer, "HTTP"))
        {
            printf("Blocked HTTP request from %s\n", inet_ntoa(client.sin_addr));
            close(client_sock);
            continue;
        }

        //send packet to destination
        if (sendto(sock, buffer, bytes, 0, (struct sockaddr *)&client, client_len) < 0)
        {
            perror("sendto failed");
            return 1;
        }

        printf("Forwarded packet to %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        //close client socket
        close(client_sock);
    }

    //close main socket
    close(sock);

    return 0;
}