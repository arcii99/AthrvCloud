//FormAI DATASET v1.0 Category: Simple Web Server ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<unistd.h>
int main()
{
    int iServerfd;
    int iClientfd;
    int iReadSize;
    struct sockaddr_in ServerAddr;
    struct sockaddr_in ClientAddr;
    socklen_t clilen;
    char cBuf[1025];
    int iRetValue;
    int iOptionValue = 1 ;
    iServerfd = socket (AF_INET, SOCK_STREAM, 0);
    if(iServerfd < 0)
    {
        perror("Cannot Create Socket\n");
        return -1;
    }
    if(setsockopt(iServerfd, SOL_SOCKET, SO_REUSEADDR, 
                  (char*)&iOptionValue,
                  sizeof(int)) < 0)
    {
        printf("Failed to set socket\n");
        return -1;
    }
    ServerAddr.sin_family = AF_INET;
    // Use Any available IP address.
    // Give preference to eth0 IP if both are there.
    ServerAddr.sin_addr.s_addr = INADDR_ANY;
    ServerAddr.sin_port = htons(4000);

    iRetValue = bind(iServerfd, (struct sockaddr *)&ServerAddr,
                      sizeof(ServerAddr));
    if(iRetValue < 0)
    {
        perror("Failed to Bind\n");
        return -1;
    }
    listen(iServerfd, 5);
    while(1)
    {
        clilen = sizeof(ClientAddr);
        printf("Waiting for incoming connections...\n");
        iClientfd = accept(iServerfd, (struct sockaddr *)&ClientAddr,
                            &clilen);
        printf("Connection accepted from %s:%d\n",
                inet_ntoa(ClientAddr.sin_addr), 
                ntohs(ClientAddr.sin_port));
        iReadSize = read(iClientfd, cBuf, 1024);
        cBuf[iReadSize] = '\0';
        printf("Request:%s\n",cBuf);
        if(iReadSize<0)
        {
            perror("Failed to Receive Data from Client\n");
        }
        else if(iReadSize == 0)
        {
            printf("Client Disconnected\n");
            close(iClientfd);
        }
        if(strncmp(cBuf, "GET",3) == 0)
        {
            printf("Successful return\n");
            write(iClientfd, "\nSuccessful return\n",19);
        }
        else
        {
            write(iClientfd, "\nERROR: Invalid Request\n",26);
        }
        close(iClientfd);
    }
    close(iServerfd);
    return 0;
}