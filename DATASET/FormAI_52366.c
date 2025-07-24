//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 1024

void sendCommand(int sock, char* command) {
    char buffer[MAX_SIZE];
    int received, sent;
    sent = send(sock, command, strlen(command), 0);
    if (sent < 0) {
        perror("Failed to send command");
        exit(1);
    }
    received = recv(sock, buffer, MAX_SIZE, 0);
    if (received < 0) {
        perror("Failed to receive response");
        exit(1);
    }
    printf("%s", buffer);
}

int main(int argc, char* argv[]) {
    int sock;
    struct sockaddr_in server;
    char message[MAX_SIZE];
    
    // create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }
    
    // set connection details
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(25); // SMTP port
    
    // connect to server
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Failed to connect");
        exit(1);
    }
    
    printf("Connected to SMTP server\n");
    
    // receive server greeting
    if (recv(sock, message, MAX_SIZE, 0) < 0) {
        perror("Failed to receive server greeting");
        exit(1);
    }
    
    printf("Server says: %s\n", message);
    
    // send HELO command
    sendCommand(sock, "HELO\r\n");
    
    // send MAIL FROM command
    sendCommand(sock, "MAIL FROM:<sender@example.com>\r\n");
    
    // send RCPT TO command
    sendCommand(sock, "RCPT TO:<recipient@example.com>\r\n");
    
    // send DATA command
    sendCommand(sock, "DATA\r\n");
    
    // send email message
    sprintf(message, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Example Subject\r\n\r\nThis is the email message.\r\n");
    send(sock, message, strlen(message), 0);
    
    // send QUIT command
    sendCommand(sock, "QUIT\r\n");
    
    // close socket
    close(sock);
    
    printf("Email sent successfully\n");
    
    return 0;
}