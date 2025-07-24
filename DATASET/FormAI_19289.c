//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAXSIZE 1024  // maximum buffer size
#define PORT 8080     // default port number

// function to handle error messages
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char const *argv[])
{
    int local, remote, clientlen, sockfd, portno;
    char buffer[MAXSIZE];
    char *host;
    struct sockaddr_in serv_addr, client_addr;
    struct hostent *remote_addr;

    // check for command line arguments, usage: ./proxy <hostname>
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    // set up local socket
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);
    clientlen = sizeof(client_addr);

    // loop to accept incoming connections
    while (1) {
        local = accept(sockfd, (struct sockaddr *) &client_addr, &clientlen);
        if (local < 0)
            error("ERROR on accept");

        memset(buffer, 0, MAXSIZE);
        if (read(local, buffer, MAXSIZE) < 0)
            error("ERROR reading from socket");

        // extract host from request
        host = strtok(buffer, " ");
        host = strtok(NULL, " ");
        host = strtok(host, "/");

        // get remote server address
        remote_addr = gethostbyname(host);
        if (remote_addr == NULL)
            error("ERROR, no such host\n");

        // set up remote socket
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(80);
        memcpy(&serv_addr.sin_addr.s_addr, remote_addr->h_addr_list[0], remote_addr->h_length);

        remote = socket(AF_INET, SOCK_STREAM, 0);
        if (remote < 0)
            error("ERROR opening socket");

        if (connect(remote, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
            error("ERROR connecting");

        // forward request to remote server
        if (write(remote, buffer, strlen(buffer)) < 0)
            error("ERROR writing to socket");

        // receive and forward response to local client
        while (1) {
            memset(buffer, 0, MAXSIZE);
            int nbytes = recv(remote, buffer, MAXSIZE, 0);
            if (nbytes < 0)
                error("ERROR on receive");
            else if (nbytes == 0)
                break;
            if (send(local, buffer, nbytes, 0) < 0)
                error("ERROR on send");
        }

        close(local);
        close(remote);
    }

    close(sockfd);
    return 0;
}