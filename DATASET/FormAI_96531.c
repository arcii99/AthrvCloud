//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>

#define BUFSIZE 1024

void printErrorMsg(char *msg)
{
    fprintf(stderr, "Error: %s\n", msg);
}

int main(int argc, char **argv)
{
    int sock_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFSIZE];
    fd_set rfds;
    struct timeval tv;
    int retval, i;
    int port = 8080;
    int num_connections = 0;
    int max_clients = 10;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1)
    {
        printErrorMsg("Could not create socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if(bind(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0)
    {
        printErrorMsg("Could not bind socket to port");
        return 1;
    }

    if(listen(sock_fd, max_clients) != 0)
    {
        printErrorMsg("Could not listen for connections");
        return 1;
    }

    printf("\nServer Started listening on port %d", port);

    while(1)
    {
        FD_ZERO(&rfds);
        FD_SET(sock_fd, &rfds);

        tv.tv_sec = 5;
        tv.tv_usec = 0;

        for(i = 0; i < num_connections; i++)
        {
            FD_SET(client_fd, &rfds);
        }

        retval = select(FD_SETSIZE, &rfds, NULL, NULL, &tv);

        if (retval == -1)
        {
            printErrorMsg("select()");
            return 1;
        }
        else if (retval == 0)
        {
            printf("\nNo data received from clients");
        }
        else
        {
            if(FD_ISSET(sock_fd, &rfds))
            {
                int addr_len = sizeof(client_addr);
                client_fd = accept(sock_fd, (struct sockaddr*)&client_addr, (socklen_t*)&addr_len);

                if(num_connections < max_clients)
                {
                    num_connections++;
                    printf("\nNew client connected from %s:%d, number of connections: %d", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), num_connections);
                }
                else
                {
                    printf("\nConnection rejected due to maximum number of clients limit");
                    close(client_fd);
                }
            }
            else
            {
                for(i = 0; i < num_connections; i++)
                {
                    if(FD_ISSET(client_fd, &rfds))
                    {
                        int numBytesRecvd = recv(client_fd, buffer, BUFSIZE-1, 0);
                        if(numBytesRecvd <= 0)
                        {
                            close(client_fd);
                            FD_CLR(client_fd, &rfds);
                            num_connections--;
                            printf("\nClient disconnected, number of connections: %d", num_connections);
                        }
                        else
                        {
                            buffer[numBytesRecvd] = '\0';
                            printf("\nMessage received from %s:%d: %s", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);
                        }
                    }
                }
            }
        }
    }

    return 0;
}