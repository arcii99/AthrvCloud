//FormAI DATASET v1.0 Category: Client Server Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void retro_chat(int sock){

    char message[50];
    char server_response[50];
    printf("Welcome to Retro Chat!\n");
    printf("Please enter a message: ");
    fgets(message, 50, stdin);

    send(sock, message, strlen(message), 0);
    memset(server_response, 0, sizeof(server_response));
    read(sock, server_response, 50);
    printf("\nRetro Server response: %s\n", server_response);
}

int main(){

    int sock = 0;
    struct sockaddr_in serv_addr;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        printf("Couldn't create socket!\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        printf("Connection Failed!\n");
        return -1;
    }

    // Start Retro Chat
    retro_chat(sock);

    // Close the socket
    close(sock);

    return 0;
}