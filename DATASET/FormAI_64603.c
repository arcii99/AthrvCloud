//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER "imap.server.com"
#define PORT 993

//Function to establish SSL connection
SSL* SSLConnect(int sockfd) {
    SSL_library_init();
    SSL_CTX *ssl_ctx = SSL_CTX_new(SSLv23_client_method());
    if(ssl_ctx == NULL) {
        printf("Error creating SSL_CTX new\n");
        return NULL;
    }
    SSL *ssl = SSL_new(ssl_ctx);
    SSL_set_fd(ssl, sockfd);
    int err = SSL_connect(ssl);
    if(err == -1) {
        printf("Error in SSL connection\n");
        SSL_free(ssl);
        return NULL;
    }
    return ssl;
}

int main() {
    //Creating socket and establishing connection
    int sockFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sockFd == -1) {
        printf("Error creating socket\n");
        return -1;
    }
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(SERVER);
    serverAddr.sin_port = htons(PORT);
    if(connect(sockFd, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) == -1) {
        printf("Error connecting to IMAP server\n");
        return -1;
    }
    //Establishing SSL connection
    SSL* ssl = SSLConnect(sockFd);
    if(ssl == NULL) {
        printf("Error establishing SSL connection\n");
        return -1;
    }
    //Sending login request to server
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "login username password\n");
    int bytes = SSL_write(ssl, buffer, strlen(buffer));
    if(bytes == -1) {
        printf("Error sending login request\n");
        SSL_free(ssl);
        return -1;
    }
    printf("Logged in successfully\n");
    //Creating and sending IMAP command to get inbox messages
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "1 SELECT \"INBOX\"\n");
    bytes = SSL_write(ssl, buffer, strlen(buffer));
    if(bytes == -1) {
        printf("Error sending SELECT command\n");
        SSL_free(ssl);
        return -1;
    }
    printf("Listing messages in INBOX:\n");
    //Receiving response from server and printing inbox messages
    memset(buffer, 0, sizeof(buffer));
    bytes = SSL_read(ssl, buffer, sizeof(buffer)-1);
    if(bytes == -1) {
        printf("Error receiving response\n");
        SSL_free(ssl);
        return -1;
    }
    char *token = strtok(buffer, "\r\n");
    while(token != NULL) {
        if(strncmp(token, "* ", 2) == 0) {
            printf("%s\n", token+2);
        }
        token = strtok(NULL, "\r\n");
    }
    //Closing SSL connection and socket
    SSL_free(ssl);
    close(sockFd);
    printf("Connection closed\n");
    return 0;
}