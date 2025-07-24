//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define HOST "www.example.com"
#define PORT 80

int main(){
    printf("Hello there! Let's build a HTTP Client.\n");

    //Create socket
    int socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1){
        printf("Could not create socket");
        return 1;
    }
    printf("Socket created successfully.\n");

    //Prepare the sockaddr_in structure
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(HOST);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    //Connect to remote server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0){
        printf("Connection error\n");
        return 1;
    }
    printf("Connected to server.\n");

    //Send some data
    char message[1000];
    sprintf(message, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", HOST);
    if(send(socket_desc, message, strlen(message), 0) < 0){
        printf("Send failed\n");
        return 1;
    }
    printf("Data sent successfully.\n");

    //Receive some data
    char server_reply[2000];
    if(recv(socket_desc, server_reply, 2000, 0) < 0){
        printf("Receive failed\n");
        return 1;
    }
    printf("Reply received:\n%s\n", server_reply);

    //Close the socket
    close(socket_desc);
    printf("Socket closed.\n");

    return 0;
}