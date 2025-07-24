//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define BUFFSIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_address;
    char message[BUFFSIZE] , server_reply[BUFFSIZE];
    
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        perror("Could not create socket");
    }

    puts("Socket created");

    server_address.sin_addr.s_addr = inet_addr("<YOUR_SERVER_IP>");
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons( 80 );

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server_address , sizeof(server_address)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected\n");

    // Send some data
    sprintf(message, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", "<YOUR_SERVER_IP>");
    if (send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    puts("Data Sent\n");

    //Receive a reply from the server
    while (recv(sock , server_reply , BUFFSIZE , 0) > 0) {
        puts(server_reply);
        memset(server_reply, 0, BUFFSIZE);
    }

    puts("Reply received\n");

    close(sock);
    return 0;
}