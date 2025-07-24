//FormAI DATASET v1.0 Category: Port Scanner ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int sock, i;
    struct sockaddr_in server;
    char target_ip[20];
    int start_port, end_port;

    if(argc < 4)
    {
        printf("Usage: %s <IP> <start_port> <end_port>\n", argv[0]);
        exit(0);
    }

    strcpy(target_ip, argv[1]);
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(target_ip);

    for(i = start_port; i <= end_port; i++)
    {
        server.sin_port = htons(i);
        if(connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0)
            printf("Port %d is open.\n", i);
    }
    close(sock);
    return 0;
}