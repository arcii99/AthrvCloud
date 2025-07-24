//FormAI DATASET v1.0 Category: Networking ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(){
    int clientSocket, valread;
    struct sockaddr_in serverAddr;
    char buffer[1024];

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSocket < 0){
        printf("\n Error : Could not create socket \n");
        return 1;
    }

    memset(&serverAddr, '0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);

    if(inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr)<=0){
        printf("\n Error : Invalid address/ Address not supported \n");
        return 1;
    }

    if(connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0){
        printf("\n Error : Connection Failed \n");
        return 1;
    }

    printf("Connected to server!\n");

    while(1){
        printf("Enter message to send to server : ");
        scanf("%s", buffer);

        send(clientSocket, buffer, strlen(buffer), 0);
        printf("Message sent!\n");

        valread = read(clientSocket, buffer, 1024);
        printf("Server replied with message : %s\n", buffer);
    }

    return 0;
}