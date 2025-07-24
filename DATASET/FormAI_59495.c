//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: complex
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>

int main(int argc, char *argv[]) {
    int socket_desc = 0;
    struct sockaddr_in server_addr;
    char *message, server_reply[1024];
    memset(server_reply, '\0', sizeof(server_reply)); //Initialize server_reply array with NULL

    // Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    server_addr.sin_addr.s_addr = inet_addr("216.58.194.174"); // IP address of google.com
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons( 80 );

    //Connect to remote server
    if (connect(socket_desc , (struct sockaddr *)&server_addr , sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    puts("Connected");

    //Send HTTP request to the server
    message = "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0) {
        puts("Send failed");
        return 1;
    }

    puts("Data Sent\n");

    //Receive a reply from the server
    if(recv(socket_desc, server_reply , 1024 , 0) < 0) {
        puts("Error receiving data");
    } else {
        puts("Reply received\n");
    }

    printf("Server replied: %s\n\n",server_reply);

    return 0;
}