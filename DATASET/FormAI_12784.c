//FormAI DATASET v1.0 Category: Simple Web Server ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define PORT 8080 

int main(int argc, char const *argv[]) 
{ 
    int sockfd, newsockfd, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 

    char buffer[1024] = {0}; 
    char *html_response = "HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=UTF-8\r\n\r\n"
                          "<!DOCTYPE html><html><head><title>Simple Web Server</title></head><body>"
                          "<h1>Welcome to my Simple Web Server!</h1><p>This is an artistic style example program.</p></body></html>";
    
    // Creating socket file descriptor 
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("Socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Setting socket options 
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("Setsockopt failed"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
    
    // Binding the socket 
    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("Bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Listening for incoming connections 
    if (listen(sockfd, 3) < 0) 
    { 
        perror("Listen failed"); 
        exit(EXIT_FAILURE); 
    } 

    printf("Simple Web Server is running on http://127.0.0.1:%d\n", PORT);

    // Accepting incoming connections 
    while (1) 
    { 
        if ((newsockfd = accept(sockfd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
        { 
            perror("Accept failed"); 
            exit(EXIT_FAILURE); 
        } 

        // Receiving the request from the client
        valread = read(newsockfd, buffer, 1024);

        // Sending the HTTP response to the client
        send(newsockfd, html_response, strlen(html_response), 0);

        // Closing the connection
        close(newsockfd); 
    } 
    
    return 0; 
}