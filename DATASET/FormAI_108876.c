//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <IP Address or Domain Name>\n", argv[0]);
        return 1;
    }

    char *target = argv[1]; // Setting target variable to be used later in program

    while(1)
    {
        int sock = socket(AF_INET, SOCK_STREAM, 0);

        if(sock < 0) // Error handling while creating socket
        {
            printf("Error while creating socket");
            return 1;
        }

        struct sockaddr_in server;
        server.sin_addr.s_addr = inet_addr(target);
        server.sin_family = AF_INET;
        server.sin_port = htons(80);

        if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) // Error handling while connecting to the server
        {
            printf("%s is Down!\n", target);
        }
        else
        {
            printf("%s is Up!\n", target);
        }

        close(sock);

        sleep(60); // Checking once every minute
    }

    return 0;
}