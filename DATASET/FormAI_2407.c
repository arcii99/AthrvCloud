//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
 
int main(int argc, char *argv[]) {
    int socket_desc;
    struct sockaddr_in server;
    char *message, server_reply[2000];
     
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
        printf("Could not create socket");
         
    // Set up server connection details
    server.sin_addr.s_addr = inet_addr("your_SMTP_server_address");
    server.sin_family = AF_INET;
    server.sin_port = htons(25);
 
    // Connect to SMTP server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connect failed. Error");
        return 1;
    }
     
    // Receive server greeting
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
    }
    printf("%s\n", server_reply);
     
    // Send HELO command
    message = "HELO your_domain.com\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }
    printf("HELO command sent\n");
     
    // Receive response from server
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
    }
    printf("%s\n", server_reply);
 
    // Send MAIL FROM command
    message = "MAIL FROM:<your_email@domain.com>\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }
    printf("MAIL FROM command sent\n");
     
    // Receive response from server
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
    }
    printf("%s\n", server_reply);
 
    // Send RCPT TO command
    message = "RCPT TO:<recipient_email@domain.com>\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }
    printf("RCPT TO command sent\n");
     
    // Receive response from server
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
    }
    printf("%s\n", server_reply);
 
    // Send DATA command
    message = "DATA\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }
    printf("DATA command sent\n");
     
    // Receive response from server
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
    }
    printf("%s\n", server_reply);
 
    // Send email message
    message = "Subject: SMTP Test\r\nTest email message body\r\n.\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }
    printf("Email message sent\n");
     
    // Receive response from server
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
    }
    printf("%s\n", server_reply);
 
    // Send QUIT command
    message = "QUIT\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }
    printf("QUIT command sent\n");
     
    // Receive response from server
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
    }
    printf("%s\n", server_reply);
 
    // Close socket connection
    close(socket_desc);
    return 0;
}