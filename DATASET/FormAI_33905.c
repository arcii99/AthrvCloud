//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char **argv){
    int sockfd, newsockfd, portno, n, i, j;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    char buffer[BUFSIZE], url[BUFSIZE], method[BUFSIZE], path[BUFSIZE], http_version[BUFSIZE],
         header_name[BUFSIZE], header_value[BUFSIZE], new_header[BUFSIZE], host[BUFSIZE];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // set up server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 8888;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // bind socket to server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    // listen for connections
    listen(sockfd, 5);

    printf("Waiting for connection...\n");

    while (1)
    {
        // accept a connection
        socklen_t clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            error("ERROR on accept");

        // read request from client
        bzero(buffer, BUFSIZE);
        n = read(newsockfd, buffer, BUFSIZE);
        if (n < 0)
            error("ERROR reading from socket");
        
        printf("Received request from client:\n%s\n", buffer);

        sscanf(buffer, "%s %s %s", method, url, http_version);

        // parse url to get host and path
        if (strstr(url, "http://") != NULL) {
            strcpy(url, url+strlen("http://"));
        }
        sscanf(url, "%[^/]/%s", host, path);

        // remove port number from host, if present
        char *str_port = strstr(host, ":");
        if (str_port != NULL) {
            *str_port = '\0';
        }

        // get IP address of host
        server = gethostbyname(host);
        if (server == NULL) {
            fprintf(stderr,"ERROR, no such host\n");
            exit(0);
        }

        // connect to server
        int remote_sockfd;
        struct sockaddr_in remote_serv_addr;
        bzero((char *) &remote_serv_addr, sizeof(remote_serv_addr));
        remote_serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr,
             (char *)&remote_serv_addr.sin_addr.s_addr, server->h_length);
        remote_serv_addr.sin_port = htons(80);
        remote_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (remote_sockfd < 0)
            error("ERROR opening socket");
        if (connect(remote_sockfd,(struct sockaddr *) &remote_serv_addr,sizeof(remote_serv_addr)) < 0)
            error("ERROR connecting");

        // write request to server
        bzero(new_header, BUFSIZE);
        for (i = 0; i < strlen(buffer); i++) {
            if (buffer[i] == '\r' && buffer[i+1] == '\n') {
                // check if header is Host
                sscanf(header_name, "%[^:]: %s", header_name, header_value);
                if (strcasecmp(header_name, "Host") == 0) {
                    sprintf(new_header, "%sHost: %s\r\n", new_header, host);
                } else {
                    sprintf(new_header, "%s%s: %s\r\n", new_header, header_name, header_value);
                }
                i++; // skip '\n'
                bzero(header_name, BUFSIZE);
                bzero(header_value, BUFSIZE);
            } else if (buffer[i] == '\r' && buffer[i+1] == '\n' && buffer[i+2] == '\r' && buffer[i+3] == '\n') {
                break;
            } else if (buffer[i] == ':') {
                strcpy(header_name, buffer);
                header_name[i] = '\0'; // strip value from header name string
                strcpy(header_value, buffer+i+2); // strip header name and ': ' from header value string
                i++; // skip ' '
            } else {
                sprintf(header_name, "%s%c", header_name, buffer[i]);
            }
        }
        sprintf(new_header, "%s\r\n", new_header);
        sprintf(buffer, "%s %s %s\r\n%s", method, path, http_version, new_header);
        n = write(remote_sockfd, buffer, strlen(buffer));
        if (n < 0)
            error("ERROR writing to socket");

        // read response from server and forward to client
        bzero(buffer, BUFSIZE);
        while ((n = read(remote_sockfd, buffer, BUFSIZE)) > 0) {
            write(newsockfd, buffer, n);
            bzero(buffer, BUFSIZE);
        }
        if (n < 0)
            error("ERROR reading from socket");
            
        printf("Sent response to client:\n%s\n", buffer);
        
        close(newsockfd);
        close(remote_sockfd);
    }

    close(sockfd);
    return 0;
}