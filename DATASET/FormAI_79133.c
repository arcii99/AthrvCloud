//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define BUFFER_SIZE 1024

void error_handler(const char* message) {
    perror(message);
    exit(1);
}

int main() {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0); // creating a socket with IPv4, TCP protocol
    if(sock_fd < 0) {
        error_handler("Socket creation error");
    }

    // configuring server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr)); // initializing the memory to zero
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(587); // SMTP port number
    server_addr.sin_addr.s_addr = inet_addr("10.0.2.15"); // server IP address

    // connecting to server
    if(connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error_handler("Connection error");
    }

    // server response buffer
    char buffer[BUFFER_SIZE] = {0};

    // read welcome message from server
    if(recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        error_handler("Receive error");
    }
    printf("%s", buffer);

    // sending HELO command
    char helo_message[BUFFER_SIZE] = "HELO me\r\n"; // introducing ourselves to the server
    if(send(sock_fd, helo_message, strlen(helo_message), 0) < 0) {
        error_handler("Send error");
    }
    if(recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        error_handler("Receive error");
    }
    printf("%s", buffer);

    // sending MAIL FROM command
    char mail_from[BUFFER_SIZE] = "MAIL FROM:<sender@example.com>\r\n"; // sender email address
    if(send(sock_fd, mail_from, strlen(mail_from), 0) < 0) {
        error_handler("Send error");
    }
    if(recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        error_handler("Receive error");
    }
    printf("%s", buffer);

    // sending RCPT TO command
    char rcpt_to[BUFFER_SIZE] = "RCPT TO:<recipient@example.com>\r\n"; // recipient email address
    if(send(sock_fd, rcpt_to, strlen(rcpt_to), 0) < 0) {
        error_handler("Send error");
    }
    if(recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        error_handler("Receive error");
    }
    printf("%s", buffer);

    // sending DATA command
    char data[BUFFER_SIZE] = "DATA\r\n";
    if(send(sock_fd, data, strlen(data), 0) < 0) {
        error_handler("Send error");
    }
    if(recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        error_handler("Receive error");
    }
    printf("%s", buffer);

    // sending email message
    char message[] = "From: sender@example.com\r\n"
                     "To: recipient@example.com\r\n"
                     "Subject: Testing SMTP Client\r\n"
                     "\r\n"
                     "Hello,\r\n"
                     "This is a test email message sent from SMTP client.\r\n"
                     "Regards,\r\n"
                     "Sender\r\n"
                     ".\r\n"; // "." denotes end of message
    if(send(sock_fd, message, strlen(message), 0) < 0) {
        error_handler("Send error");
    }
    if(recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        error_handler("Receive error");
    }
    printf("%s", buffer);

    // sending QUIT command
    char quit[BUFFER_SIZE] = "QUIT\r\n";
    if(send(sock_fd, quit, strlen(quit), 0) < 0) {
        error_handler("Send error");
    }
    if(recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        error_handler("Receive error");
    }
    printf("%s", buffer);

    // closing socket
    close(sock_fd);

    return 0;
}