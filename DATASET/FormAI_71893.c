//FormAI DATASET v1.0 Category: Networking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv) {
    // declare variables
    int socket_desc, nBytes;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE], message[BUFFER_SIZE];
    
    // create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }
    
    // set server address and port
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    
    // connect to server
    if (connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Could not connect");
        return 1;
    }
    
    // receive message from server
    while ((nBytes = recv(socket_desc, buffer, BUFFER_SIZE, 0)) > 0) {
        // print message from server
        printf("%s", buffer);
        
        // clear buffer and get user input
        memset(buffer, '\0', BUFFER_SIZE);
        fgets(message, BUFFER_SIZE, stdin);
        
        // send message to server
        send(socket_desc, message, strlen(message), 0);
        
        // clear message
        memset(message, '\0', BUFFER_SIZE);
    }
    
    if (nBytes == 0) {
        printf("Server disconnected");
    } else {
        printf("Error receiving data");
    }
    
    return 0;
}