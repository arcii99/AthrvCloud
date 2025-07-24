//FormAI DATASET v1.0 Category: Simple Web Server ; Style: satisfied
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 

#define PORT 8080 

void error(const char *msg) 
{ 
    perror(msg); 
    exit(1); 
} 

int main() 
{ 
    int sockfd, newsockfd; 
    socklen_t clilen; 
    char buffer[1024] = {0}; 
    struct sockaddr_in serv_addr, cli_addr; 
    int n; 
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html>\n<head>\n<title>My Simple Web Server</title>\n</head>\n<body>\n<h1>Welcome to My Simple Web Server!</h1>\n<p>This is a C language implementation of a basic web server.</p>\n</body>\n</html>\n";

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd < 0) 
        error("ERROR opening socket"); 
    memset(&serv_addr, 0, sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_addr.s_addr = INADDR_ANY; 
    serv_addr.sin_port = htons(PORT); 

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR on binding"); 

    listen(sockfd, 5); 
    clilen = sizeof(cli_addr); 

    while (1) 
    { 
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen); 
        if (newsockfd < 0) 
            error("ERROR on accept"); 

        n = read(newsockfd, buffer, 1024); 
        if (n < 0) 
            error("ERROR reading from socket"); 
        printf("Request: %s\n", buffer); 

        n = write(newsockfd, response, strlen(response)); 
        if (n < 0) 
            error("ERROR writing to socket"); 

        close(newsockfd); 
    } 

    close(sockfd); 
    return 0; 
}