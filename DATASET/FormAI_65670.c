//FormAI DATASET v1.0 Category: Client Server Application ; Style: sophisticated
//This is a client-server application using C language
//The client sends a message to the server which calculates its length and sends it back to the client
//The communication between client and server is done using sockets

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *msg = "Hello Server!";
    char buffer[1024] = {0};
    int msg_len = strlen(msg);
     
    //Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    //Set server address details
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    //Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
   
    //Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    printf("Message sent to server: %s\n", msg);

    //Send message to server
    send(sock , msg , strlen(msg) , 0 );

    //Receive message from server
    valread = read( sock , buffer, 1024);
    printf("Message received from server: %s\n",buffer );

    printf("Length of message received from server: %d\n", valread);

    return 0;
}