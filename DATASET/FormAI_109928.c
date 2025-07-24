//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: thoughtful
/* C Simple HTTP Proxy */

/* This is a simple demonstration of a HTTP proxy. It listens for incoming
 * requests on a port, then sends those requests to the designated server,
 * receives the response, then sends that response back to the client.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* The port number to listen on */
#define LISTEN_PORT 8080

/* The maximum size of a request or response */
#define BUFFER_SIZE 16384 

/* The server to forward requests to */
#define SERVER_ADDR "192.168.0.1"
#define SERVER_PORT 80

/* handle a client connection */
void handle_client(int client_fd)
{
    char buffer[BUFFER_SIZE];
    int server_fd, len;

    /* open a connection to the server */
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    server_addr.sin_port = htons(SERVER_PORT);
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket() failed");
        close(client_fd);
        return;
    }
    if(connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect() failed");
        close(client_fd);
        return;
    }

    /* forward the client's request to the server */
    do
    {
        bzero(buffer, sizeof(buffer));
        if((len = read(client_fd, buffer, sizeof(buffer))) < 0)
        {
            perror("read() failed");
            close(client_fd);
            close(server_fd);
            return;
        }
        if(len > 0)
        {
            /* uncomment the following to print out the request for debugging purposes */
            /* fprintf(stdout, "REQUEST:\n%s\n", buffer); */
            if(write(server_fd, buffer, len) != len)
            {
                perror("write() failed");
                close(client_fd);
                close(server_fd);
                return;
            }
        }
    }
    while(len > 0);

    /* receive the server's response and send it back to the client */
    do
    {
        bzero(buffer, sizeof(buffer));
        if((len = read(server_fd, buffer, sizeof(buffer))) < 0)
        {
            perror("read() failed");
            close(client_fd);
            close(server_fd);
            return;
        }
        if(len > 0)
        {
            /* uncomment the following to print out the response for debugging purposes */
            /* fprintf(stdout, "RESPONSE:\n%s\n", buffer); */
            if(write(client_fd, buffer, len) != len)
            {
                perror("write() failed");
                close(client_fd);
                close(server_fd);
                return;
            }
        }
    }
    while(len > 0);

    /* close the connections */
    close(client_fd);
    close(server_fd);
}

int main()
{
    int listen_fd, client_fd;
    struct sockaddr_in listen_addr, client_addr;
    socklen_t client_len;

    /* open the listening socket */
    if((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket() failed");
        exit(1);
    }
    bzero(&listen_addr, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    listen_addr.sin_port = htons(LISTEN_PORT);
    if(bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0)
    {
        perror("bind() failed");
        exit(1);
    }
    if(listen(listen_fd, 5) < 0)
    {
        perror("listen() failed");
        exit(1);
    }

    printf("listening on port %d...\n", LISTEN_PORT);

    /* accept client connections */
    while(1)
    {
        client_len = sizeof(client_addr);
        if((client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_len)) < 0)
        {
            perror("accept() failed");
            exit(1);
        }
        printf("accepted connection from %s\n", inet_ntoa(client_addr.sin_addr));
        handle_client(client_fd);
    }

    return 0;
}