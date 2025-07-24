//FormAI DATASET v1.0 Category: Socket programming ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define PORT 8080

int main(int argc, char const *argv[]){

    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *msg = "Hello from the client side!";
    char buffer[1024] = {0};

    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("Socket creation error\n");
        return -1; 
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){ 
        printf("Invalid address/ Address not supported\n"); 
        return -1; 
    }
   
    //Connecting
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){ 
        printf("Connection Failed\n"); 
        return -1; 
    }

    // Sending message to server
    send(sock, msg, strlen(msg), 0 );
    printf("Message sent to server\n");
    // Reading message from server
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
    return 0;
}