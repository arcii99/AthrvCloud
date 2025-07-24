//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <fcntl.h>

#define BUFSIZE 8192
#define SERVER_PORT 8080

int main(int argc, char *argv[])
{
    int server_fd, client_fd, maxfd, connfd;
    char buf[BUFSIZE];

    struct sockaddr_in server_addr, client_addr;

    socklen_t client_len;
   
    fd_set rset, rset_copy;

    // Create the socket
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Can't create the socket\n");
        return -1;
    }

    // Set the server address
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind the socket to the server address
    if(bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1)
    {
        perror("Can't bind socket to the port\n");
        return -1;
    }

    // Listen for connections
    if(listen(server_fd, 10) == -1)
    {
        perror("Can't listen on the socket\n");
        return -1;
    }

    // Initialize the file descriptor sets
    FD_ZERO(&rset);
    FD_ZERO(&rset_copy);

    // Add the server file descriptor to the read set
    FD_SET(server_fd, &rset);
    maxfd = server_fd;

    while(true)
    {
        // Make a copy of the read set
        rset_copy = rset;

        // Multiplex I/O, waiting for events
        select(maxfd+1, &rset_copy, NULL, NULL, NULL);

        // Check if a client has connected
        if(FD_ISSET(server_fd, &rset_copy))
        {
            client_len = sizeof(client_addr);

            connfd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);

            // Add the client file descriptor to the read set
            FD_SET(connfd, &rset);
            maxfd = maxfd > connfd ? maxfd : connfd;
        }

        // Check if any client has data to read
        for(int i=server_fd+1; i<=maxfd; i++)
        {
            if(FD_ISSET(i, &rset_copy))
            {
                bzero(buf, BUFSIZE);

                if(read(i, buf, BUFSIZE) == -1)
                {
                    perror("Read error\n");

                    // Remove the client file descriptor from the read set
                    close(i);
                    FD_CLR(i, &rset);
                }

                // Send the request to the server and receive the response
                int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
                if(server_socket_fd < 0)
                {
                    perror("Can't create server socket\n");
                    continue;
                }

                struct sockaddr_in server_address;
                server_address.sin_family = AF_INET;
                server_address.sin_port = htons(80);
                inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

                if(connect(server_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
                {
                    perror("Can't connect to server\n");
                    close(server_socket_fd);
                    continue;
                }

                if(write(server_socket_fd, buf, strlen(buf)) == -1)
                {
                    perror("Write error\n");
                    close(server_socket_fd);
                    continue;
                }

                bzero(buf, BUFSIZE);
                while((read(server_socket_fd, buf, BUFSIZE)) > 0)
                {
                    if(write(i, buf, strlen(buf)) == -1)
                    {
                        perror("Write error\n");

                        // Remove the client file descriptor from the read set
                        close(i);
                        FD_CLR(i, &rset);
                        break;
                    }

                    bzero(buf, BUFSIZE);
                }

                // Close the server socket
                close(server_socket_fd);
            }
        }
    }

    // Close the server socket
    close(server_fd);

    return 0;
}