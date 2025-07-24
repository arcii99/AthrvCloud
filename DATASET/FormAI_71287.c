//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 10240

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, client_sockfd, portno;
    struct sockaddr_in server_address, client_address;
    char buffer[MAX_BUFFER_SIZE];
    fd_set allset, rset;
    FD_ZERO(&allset);
    FD_SET(sockfd, &allset);
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Error opening socket");
    
    bzero(&server_address, sizeof(server_address));
    portno = atoi(argv[1]);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &server_address,sizeof(server_address)) < 0) error("Error on binding");

    if (listen(sockfd, 5)) error("Error on listening");

    printf("Proxy server is running on port %d\n", portno);

    int client_len = sizeof(client_address);

    while (1) {
        rset = allset;
        int nready = select(FD_SETSIZE, &rset, NULL, NULL, NULL);
        if (nready < 0) { error("Error in select"); }
        if (FD_ISSET(sockfd, &rset)) {
            client_sockfd = accept(sockfd, (struct sockaddr *) &client_address, &client_len);
            printf("Accepted conneciton from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
            FD_SET(client_sockfd, &allset);
        }

        for (int fd = sockfd + 1; fd < FD_SETSIZE; fd++) {
            if (FD_ISSET(fd, &rset)) {
                bzero(buffer, MAX_BUFFER_SIZE);
                int bytes_received = recv(fd, buffer, MAX_BUFFER_SIZE, 0);
                if (bytes_received < 0) {
                    error("Error in receiving data");
                } else if (bytes_received == 0) {
                    printf("Connection closed by client\n");
                    close(fd);
                    FD_CLR(fd, &allset);
                } else {
                    printf("Data Received from client [%d]: %s\n", fd, buffer);
                    char method[100], host[100], path[100], protocol[100];
                    sscanf(buffer, "%s %s %s %s", method, path, protocol, host);
                    printf("%s %s %s %s\n", method, path, protocol, host);

                    struct sockaddr_in web_server_address;
                    int web_server_sockfd;
                    bzero((char *) &web_server_address, sizeof(web_server_address));
                    web_server_address.sin_family = AF_INET;
                    web_server_address.sin_addr.s_addr = inet_addr("216.58.194.174");
                    web_server_address.sin_port = htons(80);

                    web_server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
                    if (web_server_sockfd < 0) error("Error opening socket");

                    if (connect(web_server_sockfd, (struct sockaddr *) &web_server_address, sizeof(web_server_address)) < 0) error("Error on connecting");

                    int bytes_sent = send(web_server_sockfd, buffer, bytes_received, 0);
                    if (bytes_sent < 0) error("Error sending data to server");

                    bzero(buffer, MAX_BUFFER_SIZE);
                    int bytes_received_from_server = recv(web_server_sockfd, buffer, MAX_BUFFER_SIZE, 0);
                    if (bytes_received_from_server < 0) error("Error receiving data from server");
                    printf("Data Received from server: %s\n", buffer);

                    bytes_sent = send(fd, buffer, bytes_received_from_server, 0);
                    if (bytes_sent < 0) error("Error sending data to client");
                }
            }
        }
    }
    return 0;
}