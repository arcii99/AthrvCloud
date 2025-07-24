//FormAI DATASET v1.0 Category: Chat server ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

void clientHandler(int clientSocket){
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    int retval = read(clientSocket, buf, 1024);
    if(retval < 0){
        perror("Some error occurred while reading from the client");
        return;
    }else if (retval == 0){
        printf("Connection closed!\n");
        return;
    }

    printf("Received message: %s", buf);
    write(clientSocket, "Message received", strlen("Message received"));
    clientHandler(clientSocket);
}

void server(int port){
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket < 0){
        perror("Socket initialization failed");
        return;
    }
    if(bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0){
        perror("Unable to bind socket to the port number");
        return;
    }
    if(listen(serverSocket, 5) < 0){
        perror("Listening failed");
        return;
    }

    socklen_t clientAddrLen = sizeof(clientAddr);
    while(1){
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if(clientSocket < 0){
            perror("Acceptance of client failed");
            continue;
        }
        printf("New connection accepted!\n");
        clientHandler(clientSocket);
    }
}

int main(){
    server(8000);
    return 0;
}