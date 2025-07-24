//FormAI DATASET v1.0 Category: Networking ; Style: innovative
//Chatbot Networking Program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define DELIMITER "\n"

int main(int argc, char *argv[]){
    //Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        printf("Failed to create socket!");
        return 1;
    }
    
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
 
    //Bind
    if( bind(sock,(struct sockaddr *)&server , sizeof(server)) < 0){
        printf("Error: bind failed\n");
        return 1;
    }
    
    //Listen for incoming connections
    listen(sock , 3);
    
    printf("Listening for incoming connections...\n");
    int clientSock, c;
    struct sockaddr_in client;
    c = sizeof(struct sockaddr_in);
    
    //Accept incoming connection
    clientSock = accept(sock, (struct sockaddr *)&client, (socklen_t*)&c);
    if(clientSock < 0){
        printf("Error: connection failed\n");
        return 1;
    }else{
        printf("Connection established with %s:%d \n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
    }
    
    //Start Chatting
    char message[1000];
    while(1){
        printf("You: ");
        fgets(message, 1000, stdin);
        message[strcspn(message, DELIMITER)] = '\0'; //remove newline character
        send(clientSock, message , strlen(message), 0);
        
        if(recv(clientSock, message, 1000 , 0) < 0){
            printf("Error: receive failed\n");
            return 1;
        }
        printf("%s: %s\n", inet_ntoa(client.sin_addr), message);
    }
    
    close(sock);
    return 0;
}