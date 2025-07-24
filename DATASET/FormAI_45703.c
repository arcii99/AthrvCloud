//FormAI DATASET v1.0 Category: Simple Web Server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[1024];
    char filename[100];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int));
    if (sockfd < 0) perror("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 8888;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        perror("ERROR on binding");
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) perror("ERROR on accept");
        bzero(buffer, 1024);
        n = read(newsockfd, buffer, 1024);
        if (n < 0) perror("ERROR reading from socket");
        printf("%s\n", buffer);
        sscanf(buffer, "GET /%s HTTP/1.1", filename);
        if (strcmp(filename, "") == 0) strcpy(filename, "index.html");
        int fd = open(filename, O_RDONLY);
        if (fd < 0) {
            memset(buffer, '\0', sizeof(buffer));
            sprintf(buffer, "HTTP/1.1 404 Not Found\r\nContent-Length: %d\r\n\r\n", 9);
            strcat(buffer, "Not Found");
            send(newsockfd, buffer, strlen(buffer), 0);
        }
        else {
            memset(buffer, '\0', sizeof(buffer));
            sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n", lseek(fd, 0, SEEK_END));
            send(newsockfd, buffer, strlen(buffer), 0);
            lseek(fd, 0, SEEK_SET);
            while ( (n = read(fd, buffer, 1024)) != 0 ) {
                send(newsockfd, buffer, n, 0);
            }
        }
        close(newsockfd);
    }
    close(sockfd);
    return 0;
}