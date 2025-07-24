//FormAI DATASET v1.0 Category: Client Server Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd, client_len;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    
    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");
    
    // set socket options
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        error("ERROR setting socket options");
    }
    
    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // bind socket
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("ERROR on binding");
    }
    
    // start listening
    if (listen(sockfd, 1) < 0) {
        error("ERROR on listening");
    }
    
    // accept client connection
    client_len = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
    if (newsockfd < 0) {
        error("ERROR on accepting");
    }
    
    // communicate with client
    while (1) {
        memset(buffer, 0, MAX_BUFFER_SIZE);
        int n = read(newsockfd, buffer, MAX_BUFFER_SIZE);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        if (n == 0) {
            printf("Client disconnected\n");
            break;
        }
        
        // make the message cryptic
        for (int i = 0; i < strlen(buffer); i++) {
            if (isalpha(buffer[i])) {
                buffer[i] = (char) ((int) buffer[i] + 10);
            } else if (isdigit(buffer[i])) {
                buffer[i] = (char) ((int) '0' + ((buffer[i] - '0' + 5) % 10));
            }
        }
        
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to socket");
        }
    }
    
    // close sockets
    close(newsockfd);
    close(sockfd);

    return 0; 
}