//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: thoughtful
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define MAX_SIZE 1024

int main(int argc, char *argv[]) { 
    int socket_desc; 
    struct sockaddr_in server; 
    char *message, server_reply[MAX_SIZE]; 

    // Create a socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
     
    // Set server details
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP
    server.sin_family = AF_INET;
    server.sin_port = htons(25); // SMTP port
     
    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("Connect error");
        return 1;
    }
     
    puts("Connected\n");

    // Receive server response
    if (recv(socket_desc, server_reply, MAX_SIZE, 0) < 0) {
        puts("Receive error");
    }
    puts(server_reply);

    // Send HELO command
    message = "HELO example.com\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send error");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, server_reply, MAX_SIZE, 0) < 0) {
        puts("Receive error");
    }
    puts(server_reply);

    // Send MAIL FROM command
    message = "MAIL FROM:<john.doe@example.com>\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send error");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, server_reply, MAX_SIZE, 0) < 0) {
        puts("Receive error");
    }
    puts(server_reply);

    // Send RCPT TO command
    message = "RCPT TO:<jane.doe@example.com>\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send error");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, server_reply, MAX_SIZE, 0) < 0) {
        puts("Receive error");
    }
    puts(server_reply);

    // Send DATA command
    message = "DATA\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send error");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, server_reply, MAX_SIZE, 0) < 0) {
        puts("Receive error");
    }
    puts(server_reply);

    // Send email body
    message = "Subject: Hello from SMTP Client!\r\nThis is a test email.\r\n.\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send error");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, server_reply, MAX_SIZE, 0) < 0) {
        puts("Receive error");
    }
    puts(server_reply);

    // Send QUIT command
    message = "QUIT\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send error");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, server_reply, MAX_SIZE, 0) < 0) {
        puts("Receive error");
    }
    puts(server_reply);

    close(socket_desc);
    return 0;
}