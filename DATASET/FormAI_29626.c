//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 4096

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){

    int sockfd, newsockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    char buffer[BUFSIZE];
    FILE* fp;
    int fd;
    int proxy_recv;
    int client_send;

    if(argc < 3){
        fprintf(stderr, "Usage: %s <port> \n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        error("ERROR opening socket");
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if(bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0){
        error("ERROR on binding");
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    printf("HTTP Proxy running on port %d...\n", portno);

    while(1){

        newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);
        if(newsockfd < 0){
            error("ERROR on accept");
        }

        bzero(buffer, BUFSIZE);
        n = read(newsockfd, buffer, BUFSIZE);    //waiting for request
        if(n < 0){
            error("ERROR reading from socket");
        }

        printf("Received request from %s:%d\n%s\n",
                inet_ntoa(cli_addr.sin_addr),
                ntohs(cli_addr.sin_port), buffer);

        char* desired_host = strtok(buffer," ");
        desired_host = strtok(NULL," ");
        desired_host = strtok(desired_host,"/");
        desired_host = strtok(NULL,"/");
        printf("Desired host: %s\n", desired_host);

        struct hostent* server = gethostbyname(desired_host);  //get destination address

        if(server == NULL){
            fprintf(stderr, "ERROR, no such host\n");
            exit(0);
        }

        struct sockaddr_in dest_addr;
        bzero((char*) &dest_addr, sizeof(dest_addr));
        dest_addr.sin_family = AF_INET;
        bcopy((char*) server->h_addr, (char*) &dest_addr.sin_addr.s_addr, server->h_length);
        dest_addr.sin_port = htons(80);

        int dest_sockfd = socket(AF_INET, SOCK_STREAM, 0); //connect to destination
        if(dest_sockfd < 0){
            error("ERROR opening socket");
        }

        if(connect(dest_sockfd, (struct sockaddr*) &dest_addr, sizeof(dest_addr)) < 0){
            error("ERROR connecting");
        }

        fp = fopen("log.txt", "a");   //open log file
        fprintf(fp, "Requested URL: %s\nDestination IP: %s\n\n",
                desired_host, inet_ntoa(dest_addr.sin_addr));
        fflush(fp);
        fclose(fp);

        char* response = "HTTP/1.0 200 OK\n"
                "Server: ProxyServer/1.0\n"
                "\n";
        n = write(newsockfd, response, strlen(response)); //send response header

        if(n < 0){
            error("ERROR writing to socket");
        }

        memset(&buffer, 0, sizeof(buffer));

        fd = newsockfd;
        client_send = fd;
        proxy_recv = dest_sockfd;

        while (1) {

            fd_set fdset;

            FD_ZERO(&fdset);
            FD_SET(client_send, &fdset);
            FD_SET(proxy_recv, &fdset);

            int maxfd = (client_send > proxy_recv) ? client_send : proxy_recv;
            int readyfd = select(maxfd+1, &fdset, NULL, NULL, NULL); //select for available file descriptors

            if(readyfd < 0){
                perror("select");
                exit(1);
            }

            if(FD_ISSET(client_send, &fdset)){ //data available on socket
                n = read(client_send, buffer, BUFSIZE);
                if(n < 0){
                    perror("read");
                    exit(1);
                }

                if(n == 0){
                    break;
                }

                write(proxy_recv, buffer, n); //send to destination
                memset(&buffer, 0, sizeof(buffer));
            }

            if(FD_ISSET(proxy_recv, &fdset)){ //data available on socket
                n = read(proxy_recv, buffer, BUFSIZE);
                if(n < 0){
                    perror("recv");
                    exit(1);
                }

                if(n == 0){
                    break;
                }

                write(client_send, buffer, n); //send to client
                memset(&buffer, 0, sizeof(buffer));
            }
        }

        printf("Closed connection with %s:%d\n",
                inet_ntoa(cli_addr.sin_addr),
                ntohs(cli_addr.sin_port));

        close(newsockfd); //close client socket
        close(dest_sockfd); //close destination socket

    }

    close(sockfd); //close main socket
    return 0;
}