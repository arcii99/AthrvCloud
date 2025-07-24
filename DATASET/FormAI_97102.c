//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#define PORT 8888

int main()
{
    int sockfd, new_socket, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == 0)
    {
        printf("\nSocket creation error");
        return -1;
    }
    else
    {
        printf("\nSocket created successfully.\n");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("\nBind failed");
        return -1;
    }

    printf("\nBinding successfull");

    if (listen(sockfd, 1) < 0)
    {
        perror("\nListen failed");
        return -1;
    }

    printf("\nWaiting for connection requests");

    new_socket = accept(sockfd, (struct sockaddr *)&serv_addr, (socklen_t*)&serv_addr);

    if (new_socket < 0)
    {
        perror("\nAccept failed");
        return -1;
    }

    printf("\nConnection established");

    while(1)
    {
        valread = read(new_socket, buffer, 1024);
        printf("\nReceived : ");
        printf("%s", buffer);

        if(strcmp(buffer , "bye") == 0)
        {
            printf("\nDisconnecting socket");
            close(sockfd);
            return 0;
        }

        memset(buffer, 0, sizeof(buffer));
        printf("\nEnter message to send: ");
        fgets(buffer, 1024, stdin);
        send(new_socket, buffer, strlen(buffer), 0);
    }
    return 0;
}