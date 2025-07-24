//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

#define MAXLINE 1024 // Maximum size of the data that can be exchanged between client and server

int main(){

    int sockfd; // Socket file descriptor
    struct sockaddr_in servaddr; // Struct variable to store server address
    char buffer[MAXLINE]; // Buffer to store the messages exchanged between client and server

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0){
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr)); // Sets all bytes of servaddr to 0

    // Assigning IP address and port number of the server
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(993);
    servaddr.sin_addr.s_addr = inet_addr("imap.gmail.com"); // IMAP server address

    // Establishing connection with the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        printf("\n Connection Failed \n");
        return -1;
    }

    // Sending message to the server
    char const *login_username = "client_email@gmail.com";
    char const *login_password = "client_password";
    sprintf(buffer, "LOGIN \"%s\" \"%s\"\n", login_username, login_password);

    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, MAXLINE); // Clears the buffer

    // Receiving response from the server
    recv(sockfd, buffer, MAXLINE, 0);
    printf("%s", buffer); // Prints the response received from the server

    close(sockfd); // Closing the socket

    return 0;
}