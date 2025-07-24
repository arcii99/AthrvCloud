//FormAI DATASET v1.0 Category: File Synchronizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <WinSock2.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#endif

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
#ifdef _WIN32
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }
#endif

    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    int n;
    
    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    
    // set server address
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

#ifdef _WIN32
    serv_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
#else
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
#endif
    
    // bind socket
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }
    
    // listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        error("ERROR on listen");
    }
    
    printf("Waiting for incoming connections...\n");

    while (1) {
        int newsockfd;
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        
        // accept incoming connection
        newsockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);
        if (newsockfd < 0) {
            error("ERROR on accept");
        }
        
        // read incoming data
        memset(buffer, 0, BUFFER_SIZE);
        n = read(newsockfd, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        
        // print incoming data
        printf("Received data: %s", buffer);
        
        // send response
        n = write(newsockfd, "OK", 2);
        if (n < 0) {
            error("ERROR writing to socket");
        }
        
        // close connection
        close(newsockfd);
    }
    
    close(sockfd);

#ifdef _WIN32
    WSACleanup();
#endif
    
    return 0;
}