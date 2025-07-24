//FormAI DATASET v1.0 Category: Networking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define DEFAULT_PORT 8888
#define BUFFER_SIZE 1024

void error(char *message){
    perror(message);
    exit(EXIT_FAILURE);
}

int main(){
    int socketFileDescriptor, newSocketFileDescriptor, clientLength, readResult;
    struct sockaddr_in serverAddress, clientAddress;
    char buffer[BUFFER_SIZE];
    char *welcomeMessage = "Welcome to the server\n"; 
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family=AF_INET;
    serverAddress.sin_addr.s_addr=INADDR_ANY;
    serverAddress.sin_port=htons(DEFAULT_PORT);
    if((socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        error("Socket creation failed");
    }
    if(bind(socketFileDescriptor, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) <0 ){
        error("Bind failed");
    }
    if(listen(socketFileDescriptor, 1) < 0){
        error("Listen failed");
    }
    printf("Server started on port %d\n", DEFAULT_PORT);
    clientLength = sizeof(clientAddress);
    while(1){
        if((newSocketFileDescriptor = accept(socketFileDescriptor, 
            (struct sockaddr *)&clientAddress, (socklen_t*) &clientLength)) < 0){
            error("Accept failed");
        }
        printf("Incoming connection from %s:%d\n", 
            inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));
        send(newSocketFileDescriptor, welcomeMessage, strlen(welcomeMessage), 0);
        while((readResult = read(newSocketFileDescriptor, buffer, BUFFER_SIZE)) > 0){
            buffer[readResult] = '\0';
            printf("Received message from %s:%d: %s", 
                inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port), buffer);
            send(newSocketFileDescriptor, buffer, strlen(buffer), 0);
            if(strcmp(buffer, "exit") == 0){
                printf("Closing connection from %s:%d\n", 
                    inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));
                close(newSocketFileDescriptor);
                break;
            }
            memset(buffer, 0, sizeof(buffer));
        }
    }
    close(socketFileDescriptor);
    return 0;
}