//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFSIZE 4096

int main(int argc, char *argv[])
{
    int mysock, remote_sock, port, len, n, ret, yes=1;
    struct sockaddr_in myaddr, remote_addr;
    struct hostent *server;
    char buf[BUFSIZE];
    fd_set inputs, outputs;

    if (argc != 3)
    {
        fprintf(stderr,"Usage: %s <remote_host> <remote_port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[2]);

    // Create local socket
    if ((mysock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        fprintf(stderr, "socket error: %s\n", strerror(errno));
        exit(1);
    }

    // Allow for reuse of the local address
    if (setsockopt(mysock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
    {
        fprintf(stderr, "setsockopt error: %s\n", strerror(errno));
        exit(1);
    }

    bzero((char *) &myaddr, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(port);
    myaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind to local address
    if (bind(mysock, (struct sockaddr *) &myaddr, sizeof(myaddr)) == -1)
    {
        fprintf(stderr, "bind error: %s\n", strerror(errno));
        exit(1);
    }

    // Listen on local socket
    if (listen(mysock, 5) == -1)
    {
        fprintf(stderr, "listen error: %s\n", strerror(errno));
        exit(1);
    }

    len = sizeof(remote_addr);

    // Start listening for incoming connections
    while (1)
    {
        FD_ZERO(&inputs);
        FD_ZERO(&outputs);
        FD_SET(mysock, &inputs);

        // Wait for incoming connection or data on existing connections
        select(FD_SETSIZE, &inputs, &outputs, NULL, NULL);

        // Handle incoming connection
        if (FD_ISSET(mysock, &inputs))
        {
            // Accept incoming connection
            if ((remote_sock = accept(mysock, (struct sockaddr *)&remote_addr, &len)) == -1)
            {
                fprintf(stderr, "accept error: %s\n", strerror(errno));
                continue;
            }

            // Resolve remote host
            if ((server = gethostbyname(argv[1])) == NULL) {
                fprintf(stderr, "invalid hostname: %s\n", argv[1]);
                close(remote_sock);
                continue;
            }

            // Connect to remote host
            bzero((char *) &remote_addr, sizeof(remote_addr));
            remote_addr.sin_family = AF_INET;
            bcopy((char *)server->h_addr, (char *)&remote_addr.sin_addr.s_addr, server->h_length);
            remote_addr.sin_port = htons(port);

            if (connect(remote_sock, (struct sockaddr*)&remote_addr, sizeof(remote_addr)) == -1)
            {
                fprintf(stderr, "connect error: %s\n", strerror(errno));
                close(remote_sock);
                continue;
            }

            printf("Connected to remote host: %s\n", argv[1]);

            FD_SET(remote_sock, &inputs);
        }

        // Handle data on existing connections
        for (n = mysock+1; n <= FD_SETSIZE; ++n)
        {
            if (FD_ISSET(n, &inputs))
            {
                bzero(buf, BUFSIZE);
                ret = recv(n, buf, BUFSIZE, 0);

                if (ret == -1)
                {
                    fprintf(stderr, "recv error: %s\n", strerror(errno));
                    close(n);
                    FD_CLR(n, &inputs);
                    continue;
                }

                if (ret == 0)
                {
                    printf("Connection closed\n");
                    close(n);
                    FD_CLR(n, &inputs);
                    continue;
                }

                if (n == remote_sock)
                {
                    printf("Received response from remote host\n");
                    printf("%s\n",buf);

                    // Add response to output set
                    FD_SET(mysock, &outputs);
                }
                else
                {
                    printf("Received request from client\n");
                    printf("%s\n",buf);

                    // Forward request to remote host
                    if (send(remote_sock, buf, sizeof(buf), 0) == -1)
                    {
                        fprintf(stderr, "send error: %s\n", strerror(errno));
                        close(remote_sock);
                        FD_CLR(remote_sock, &inputs);
                        continue;
                    }

                    printf("Forwarded request to remote host\n");
                }

                // Handle output set
                if (FD_ISSET(mysock, &outputs))
                {
                    if (send(n, buf, sizeof(buf), 0) == -1)
                    {
                        fprintf(stderr, "send error: %s\n", strerror(errno));
                        close(n);
                        FD_CLR(n, &outputs);
                        continue;
                    }

                    printf("Forwarded response to client\n");
                    FD_CLR(mysock, &outputs);
                }
            }
        }
    }

    return 0;
}