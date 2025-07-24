//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDRESS "127.0.0.1" // Replace with your SMTP server IP address
#define SERVER_PORT 25

int main(){
    int sock;
    struct sockaddr_in server;
    char message[2048], server_reply[2048];
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        printf("Could not create socket");
    }
    puts("Socket created");
    
    server.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
 
    // Connect to remote server
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0){
        perror("connect failed");
        return 1;
    }
    
    puts("Connected\n");
     
    // Receive server greeting
    if(recv(sock, server_reply, 2048, 0) < 0){
        perror("recv failed");
        return 1;
    }
    printf("%s\n", server_reply);
    
    // Send EHLO message to server
    sprintf(message, "EHLO example.com\r\n");
    if(send(sock, message, strlen(message), 0) < 0){
        puts("Send failed");
        return 1;
    }
    
    // Receive server response
    if(recv(sock, server_reply, 2048, 0) < 0){
        perror("recv failed");
        return 1;
    }
    printf("%s\n", server_reply);
    
    // Send MAIL FROM message
    sprintf(message, "MAIL FROM:<sender@example.com>\r\n");
    if(send(sock, message, strlen(message), 0) < 0){
        puts("Send failed");
        return 1;
    }
    
    // Receive server response
    if(recv(sock, server_reply, 2048, 0) < 0){
        perror("recv failed");
        return 1;
    }
    printf("%s\n", server_reply);
    
    // Send RCPT TO message
    sprintf(message, "RCPT TO:<recipient@example.com>\r\n");
    if(send(sock, message, strlen(message), 0) < 0){
        puts("Send failed");
        return 1;
    }
    
    // Receive server response
    if(recv(sock, server_reply, 2048, 0) < 0){
        perror("recv failed");
        return 1;
    }
    printf("%s\n", server_reply);
    
    // Send DATA message
    sprintf(message, "DATA\r\n");
    if(send(sock, message, strlen(message), 0) < 0){
        puts("Send failed");
        return 1;
    }
    
    // Receive server response
    if(recv(sock, server_reply, 2048, 0) < 0){
        perror("recv failed");
        return 1;
    }
    printf("%s\n", server_reply);
    
    // Send message body
    sprintf(message, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test message\r\n\r\nThis is a test message\r\n.\r\n");
    if(send(sock, message, strlen(message), 0) < 0){
        puts("Send failed");
        return 1;
    }
    
    // Receive server response
    if(recv(sock, server_reply, 2048, 0) < 0){
        perror("recv failed");
        return 1;
    }
    printf("%s\n", server_reply);
    
    // Send QUIT message
    sprintf(message, "QUIT\r\n");
    if(send(sock, message, strlen(message), 0) < 0){
        puts("Send failed");
        return 1;
    }
    
    // Receive server response
    if(recv(sock, server_reply, 2048, 0) < 0){
        perror("recv failed");
        return 1;
    }
    printf("%s\n", server_reply);
     
    close(sock);
    return 0;
}