//FormAI DATASET v1.0 Category: Socket programming ; Style: all-encompassing
// Simple TCP/IP Server Program in C using Sockets
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int serverSocket, clientSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addr_size;

    // Create the socket
    serverSocket = socket(PF_INET, SOCK_STREAM, 0);

    // Configure settings of the server address struct
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    // Bind the socket to the address and port
    bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    // Listen on the socket, with 40 max connection requests queued
    if(listen(serverSocket,40)==0)
        printf("Listening\n");
    else
        printf("Error\n");

    // Accept call creates a new socket for the incoming connection
    addr_size = sizeof clientAddr;
    clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddr, &addr_size);
    if(clientSocket<0){
        printf("Error on Accept\n");
        exit(1);
    }

    while(1){
        recv(clientSocket, buffer, 1024, 0);
        if(buffer[0]=='e' && buffer[1]=='x' && buffer[2]=='i' && buffer[3]=='t')
            break;
        else
            printf("Client: %s\n",buffer);
        printf("Server: ");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,strlen(buffer),0);
        bzero(buffer, sizeof(buffer));
    }
    return 0;
}