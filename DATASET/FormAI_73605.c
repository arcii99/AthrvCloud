//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: ultraprecise
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *message, response[BUFFER_SIZE];

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 80 );

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("Connect failed. Error");
        return 1;
    }

    puts("Connected\n");

    //Prepare the message to be sent
    message = "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n";

    //Send the message to the server
    if (send(sock , message , strlen(message) , 0) < 0) {
        puts("Send failed");
        return 1;
    }
    puts("Message sent\n");

    //Receive the response from the server
    if (recv(sock , response , BUFFER_SIZE , 0) < 0) {
        puts("Receive failed");
        return 1;
    }
    puts("Response received\n");

    //Print the response from the server
    printf("%s", response);

    //Close the socket
    close(sock);
    return 0;
}