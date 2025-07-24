//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    int sock;
    struct sockaddr_in server;
    char message[1024], response[1024];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Set server details
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(25);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed");
        return 1;
    }

    // Receive server response
    if(recv(sock, response, 1024, 0) < 0) {
        printf("Error receiving response from server");
    }
    printf("Server Response: %s\n", response);

    // Send HELO message to server
    strcpy(message, "HELO myclient.com\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Error sending message to server");
        return 1;
    }
    printf("Sent message to server: %s\n", message);

    // Receive server response
    if(recv(sock, response, 1024, 0) < 0) {
        printf("Error receiving response from server");
    }
    printf("Server Response: %s\n", response);

    // Send MAIL FROM message
    strcpy(message, "MAIL FROM:<sender@myclient.com>\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Error sending message to server");
        return 1;
    }
    printf("Sent message to server: %s\n", message);

    // Receive server response
    if(recv(sock, response, 1024, 0) < 0) {
        printf("Error receiving response from server");
    }
    printf("Server Response: %s\n", response);

    // Send RCPT TO message
    strcpy(message, "RCPT TO:<recipient@target.com>\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Error sending message to server");
        return 1;
    }
    printf("Sent message to server: %s\n", message);

    // Receive server response
    if(recv(sock, response, 1024, 0) < 0) {
        printf("Error receiving response from server");
    }
    printf("Server Response: %s\n", response);

    // Send DATA message
    strcpy(message, "DATA\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Error sending message to server");
        return 1;
    }
    printf("Sent message to server: %s\n", message);

    // Receive server response
    if(recv(sock, response, 1024, 0) < 0) {
        printf("Error receiving response from server");
    }
    printf("Server Response: %s\n", response);

    // Send email body
    strcpy(message, "From: sender@myclient.com\r\nTo: recipient@target.com\r\nSubject: Test Email\r\n\r\nThis is a test email.\r\n.\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Error sending message to server");
        return 1;
    }
    printf("Sent message to server: %s\n", message);

    // Receive server response
    if(recv(sock, response, 1024, 0) < 0) {
        printf("Error receiving response from server");
    }
    printf("Server Response: %s\n", response);

    // Send QUIT message
    strcpy(message, "QUIT\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Error sending message to server");
        return 1;
    }
    printf("Sent message to server: %s\n", message);

    // Receive server response
    if(recv(sock, response, 1024, 0) < 0) {
        printf("Error receiving response from server");
    }
    printf("Server Response: %s\n", response);

    // Close socket
    close(sock);

    return 0;
}