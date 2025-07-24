//FormAI DATASET v1.0 Category: Networking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main(){
    struct sockaddr_in addr;
    int sock_desc, addrlen = sizeof(addr), connfd;
    char buffer[1024] = {0};
    char *hello = "Hello from server";    
    
    // Creating socket
    if((sock_desc = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }
    
    // Configuring socket
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    // Binding socket
    if(bind(sock_desc, (struct sockaddr *)&addr, sizeof(addr))<0){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if(listen(sock_desc, 3) < 0){
        perror("Listen error");
        exit(EXIT_FAILURE);
    }
    printf("Listening for incoming connections on port %d\n", PORT);

    // Accepting incoming connection
    if((connfd = accept(sock_desc, (struct sockaddr *)&addr, (socklen_t*)&addrlen)) < 0){
        perror("Accept error");
        exit(EXIT_FAILURE);
    }

    // Receiving message from client
    read(connfd, buffer, 1024);
    printf("Message received from client: %s\n", buffer);

    // Sending message to client
    send(connfd, hello, strlen(hello), 0);
    printf("Hello message sent to client\n");

    // Closing connection
    close(connfd);
    printf("Connection closed\n");

    return 0;
}