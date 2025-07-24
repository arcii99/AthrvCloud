//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int establish_connection(const char* hostname){
    struct hostent *he;
    struct sockaddr_in server_addr;
    int sockfd;
    he = gethostbyname(hostname);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("ERROR: Failed to create a socket.\n");
        exit(1);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(143);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        printf("ERROR: Failed to connect.\n");
        exit(1);
    }
    return sockfd;
}

void login(int sockfd, const char* username, const char* password){
    char buffer[BUFFER_SIZE];
    char auth_msg[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    sprintf(auth_msg, "a001 LOGIN %s %s\r\n", username, password);
    send(sockfd, auth_msg, strlen(auth_msg), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
}

int main(){
    int sockfd;
    sockfd = establish_connection("imap.example.com");
    login(sockfd, "myusername", "mypassword"); 
    close(sockfd);
    return 0;
}