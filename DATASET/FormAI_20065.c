//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT 25
#define MESSAGE_SIZE 1024

int main(int argc, char *argv[]) {

    printf("Hello! Let's build a SMTP client!\n");

    int server_socket, sent_size, received_size;
    struct sockaddr_in server_address;
    char message[MESSAGE_SIZE] = {0};
    char server_reply[MESSAGE_SIZE] = {0};

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Oops! Socket creation failed.\n");
        return 1;
    }

    // Set server address
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Connect to server
    if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Oops! Connection failed.\n");
        return 1;
    }

    // Receive server banner
    received_size = recv(server_socket, server_reply, MESSAGE_SIZE, 0);
    if (received_size == -1) {
        printf("Oops! Receive failed.\n");
        return 1;
    }
    printf("%s\n", server_reply);

    // Send HELO/EHLO message
    sprintf(message, "EHLO localhost\r\n");
    sent_size = send(server_socket, message, strlen(message), 0);
    if (sent_size == -1) {
        printf("Oops! Send failed.\n");
        return 1;
    }
    memset(message, 0, MESSAGE_SIZE);
    sleep(1);

    // Receive server response
    received_size = recv(server_socket, server_reply, MESSAGE_SIZE, 0);
    if (received_size == -1) {
        printf("Oops! Receive failed.\n");
        return 1;
    }
    printf("%s\n", server_reply);
    memset(server_reply, 0, MESSAGE_SIZE);

    // Send MAIL FROM message
    sprintf(message, "MAIL FROM: <test@test.com>\r\n");
    sent_size = send(server_socket, message, strlen(message), 0);
    if (sent_size == -1) {
        printf("Oops! Send failed.\n");
        return 1;
    }
    memset(message, 0, MESSAGE_SIZE);
    sleep(1);

    // Receive server response
    received_size = recv(server_socket, server_reply, MESSAGE_SIZE, 0);
    if (received_size == -1) {
        printf("Oops! Receive failed.\n");
        return 1;
    }
    printf("%s\n", server_reply);
    memset(server_reply, 0, MESSAGE_SIZE);

    // Send RCPT TO message
    sprintf(message, "RCPT TO: <dest@test.com>\r\n");
    sent_size = send(server_socket, message, strlen(message), 0);
    if (sent_size == -1) {
        printf("Oops! Send failed.\n");
        return 1;
    }
    memset(message, 0, MESSAGE_SIZE);
    sleep(1);

    // Receive server response
    received_size = recv(server_socket, server_reply, MESSAGE_SIZE, 0);
    if (received_size == -1) {
        printf("Oops! Receive failed.\n");
        return 1;
    }
    printf("%s\n", server_reply);
    memset(server_reply, 0, MESSAGE_SIZE);

    // Send DATA message
    sprintf(message, "DATA\r\n");
    sent_size = send(server_socket, message, strlen(message), 0);
    if (sent_size == -1) {
        printf("Oops! Send failed.\n");
        return 1;
    }
    memset(message, 0, MESSAGE_SIZE);
    sleep(1);

    // Receive server response
    received_size = recv(server_socket, server_reply, MESSAGE_SIZE, 0);
    if (received_size == -1) {
        printf("Oops! Receive failed.\n");
        return 1;
    }
    printf("%s\n", server_reply);
    memset(server_reply, 0, MESSAGE_SIZE);

    // Send message body
    sprintf(message, "Subject: Hello From SMTP Client\n\nHello, this is a test message from the SMTP client!\r\n.\r\n");
    sent_size = send(server_socket, message, strlen(message), 0);
    if (sent_size == -1) {
        printf("Oops! Send failed.\n");
        return 1;
    }
    memset(message, 0, MESSAGE_SIZE);
    sleep(1);

    // Receive server response
    received_size = recv(server_socket, server_reply, MESSAGE_SIZE, 0);
    if (received_size == -1) {
        printf("Oops! Receive failed.\n");
        return 1;
    }
    printf("%s\n", server_reply);
    memset(server_reply, 0, MESSAGE_SIZE);

    // Send QUIT message
    sprintf(message, "QUIT\r\n");
    sent_size = send(server_socket, message, strlen(message), 0);
    if (sent_size == -1) {
        printf("Oops! Send failed.\n");
        return 1;
    }
    memset(message, 0, MESSAGE_SIZE);
    sleep(1);

    // Receive server response
    received_size = recv(server_socket, server_reply, MESSAGE_SIZE, 0);
    if (received_size == -1) {
        printf("Oops! Receive failed.\n");
        return 1;
    }
    printf("%s\n", server_reply);
    memset(server_reply, 0, MESSAGE_SIZE);

    printf("Message sent successfully! Have a nice day!\n");

    close(server_socket);

    return 0;
}