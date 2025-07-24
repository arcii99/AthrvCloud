//FormAI DATASET v1.0 Category: Simple Web Server ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#define MAXLEN 1024 // Max length of server response
void error(const char *msg){
    perror(msg);
    exit(1);
}
int main(int argc, char *argv[]){
    int sockfd, newsockfd, portno, n;
    char buffer[MAXLEN];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Error opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 8080;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
/* Bind the socket to the IP address and port no */
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("Binding failed");
    listen(sockfd,1);
    printf("Server is running at port %d\n",portno);
    clilen = sizeof(cli_addr);
    while (1){
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            error("Error on accepting");
        bzero(buffer, MAXLEN);
        n = read(newsockfd, buffer, MAXLEN-1);
        if (n < 0)
            error("Error reading from socket");
            printf("\nClient Request: %s",buffer);
        const char *success_header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
        const char *not_found_header = "HTTP/1.1 404 NOT FOUND\r\nContent-Type: text/html\r\n\r\n";
        char *response;
        int file_fd, len;
        strtok(buffer, " ");
        char *file_name = strtok(NULL, " ");
        if (file_name!= NULL){
            printf("\nFile Name: %s\n",file_name);
            if (strncmp(file_name,"/helloc",strlen("/helloc")) == 0){
                response = "<html><body><h1>Hello World!</h1></body></html>";
                len = strlen(response);
            }
            else{
                file_fd = open(&file_name[1], O_RDONLY);
                if (file_fd == -1)
                {
                    response = "<html><body><h1>404 Not Found!</h1></body></html>";
                    len = strlen(response);
                    write(newsockfd, not_found_header, strlen(not_found_header));
                }
                else{
                    response = (char *) malloc(sizeof(char)*MAXLEN);
                    len = read(file_fd,response,MAXLEN);
                    write(newsockfd, success_header, strlen(success_header));
                    close(file_fd);
                }
            }
            write(newsockfd, response, len);
        }
        close(newsockfd);
    }
    close(sockfd);
    return 0;
}