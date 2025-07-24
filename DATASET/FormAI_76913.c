//FormAI DATASET v1.0 Category: Chat server ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080
int main()
{
    int fd, clientfd, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Welcome to the Chat server!";
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt)))
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT); 
    if (bind(fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(fd, 3) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    if ((clientfd = accept(fd, (struct sockaddr *)&address,(socklen_t*)&addrlen))<0)
    {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    send(clientfd , hello , strlen(hello) , 0 );
    printf("Welcome message sent\n");
    valread = read( clientfd , buffer, 1024);
    printf("%s\n",buffer );
    return 0;
}