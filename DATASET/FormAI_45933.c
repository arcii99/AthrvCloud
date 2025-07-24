//FormAI DATASET v1.0 Category: Email Client ; Style: asynchronous
//Asynchronous Email Client program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <pthread.h>

#define MAXLINE 1024
#define MAX_INPUT 255
#define MAX_DATA 65535

// Global Variables
int sockfd = 0, n = 0;
char recvBuff[MAXLINE];
char sendBuff[MAX_INPUT];
char dataBuff[MAX_DATA];

// Function Declarations
void initializeClient();
void sendMessageToServer();
void receiveMessageFromServer(int socketFD, char *buffer);
void sendEmail();
void handleResponse(char *server_message);

int main(int argc, char **argv) {
    initializeClient();

    while (1) {
        printf("Enter email address (or 'quit' to quit): ");
        fgets(sendBuff, MAX_INPUT, stdin);

        if (strstr(sendBuff, "quit")) {
            printf("Exiting...\n");
            exit(0);
        }

        printf("Enter the email body: ");
        fgets(dataBuff, MAX_DATA, stdin);

        sendEmail();
    }

    return 0;
}

void initializeClient() {
    // Initialize the client socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    printf("Client socket created successfully\n");

    // Define the server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(25); // SMTP port
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }
    printf("Connected to the server successfully\n");

    // Handshake with the server
    char buffer[MAXLINE];
    bzero(buffer,MAXLINE);
    receiveMessageFromServer(sockfd,buffer);
    handleResponse(buffer);
}

void sendMessageToServer() {
    if (write(sockfd, sendBuff, strlen(sendBuff)) < 0) {
        perror("Error: Failed to send message to server");
        exit(EXIT_FAILURE);
    }
}

void receiveMessageFromServer(int socketFD, char *buffer) {
    int n = 0;
    while (n == 0) {
        n = read(socketFD, buffer, MAXLINE-1);
    }
}

void sendEmail() {
    // Set up the email header and body
    sprintf(sendBuff, "MAIL FROM:<youremail@gmail.com>\r\n");
    sendMessageToServer();

    char buffer[MAXLINE];
    bzero(buffer,MAXLINE);
    receiveMessageFromServer(sockfd, buffer);
    handleResponse(buffer);

    sprintf(sendBuff, "RCPT TO:<%s>\r\n", strtok(sendBuff, "\n"));
    sendMessageToServer();

    bzero(buffer,MAXLINE);
    receiveMessageFromServer(sockfd, buffer);
    handleResponse(buffer);

    sprintf(sendBuff, "DATA\r\n");
    sendMessageToServer();

    bzero(buffer,MAXLINE);
    receiveMessageFromServer(sockfd, buffer);
    handleResponse(buffer);

    sprintf(sendBuff, "%s\r\n.\r\n", dataBuff);
    sendMessageToServer();

    bzero(buffer,MAXLINE);
    receiveMessageFromServer(sockfd, buffer);
    handleResponse(buffer);
}

void handleResponse(char *server_message) {
    printf("%s", server_message);
    if (server_message[0] == '5') {
        perror("Error: Server error");
        exit(EXIT_FAILURE);
    }
}