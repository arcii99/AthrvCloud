//FormAI DATASET v1.0 Category: Email Client ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket");
        return 1;
    }

    // set server details
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("SMTP_SERVER_IP_ADDRESS");
    server.sin_family = AF_INET;
    server.sin_port = htons(25);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error connecting to server");
        return 1;
    }

    // receive server response
    char server_response[2000];
    if (recv(sock, server_response, 2000, 0) < 0) {
        printf("Error receiving server response");
        return 1;
    }
    printf("%s", server_response);

    // send HELO command
    char helo_message[100] = "HELO example.com\r\n";
    if (send(sock, helo_message, strlen(helo_message), 0) < 0) {
        printf("Error sending HELO command");
        return 1;
    }

    // receive server response
    if (recv(sock, server_response, 2000, 0) < 0) {
        printf("Error receiving server response");
        return 1;
    }
    printf("%s", server_response);

    // send MAIL FROM command
    char mail_from_message[100] = "MAIL FROM: <sender@example.com>\r\n";
    if (send(sock, mail_from_message, strlen(mail_from_message), 0) < 0) {
        printf("Error sending MAIL FROM command");
        return 1;
    }

    // receive server response
    if (recv(sock, server_response, 2000, 0) < 0) {
        printf("Error receiving server response");
        return 1;
    }
    printf("%s", server_response);

    // send RCPT TO command
    char rcpt_to_message[100] = "RCPT TO: <recipient@example.com>\r\n";
    if (send(sock, rcpt_to_message, strlen(rcpt_to_message), 0) < 0) {
        printf("Error sending RCPT TO command");
        return 1;
    }

    // receive server response
    if (recv(sock, server_response, 2000, 0) < 0) {
        printf("Error receiving server response");
        return 1;
    }
    printf("%s", server_response);

    // send DATA command
    char data_message[100] = "DATA\r\n";
    if (send(sock, data_message, strlen(data_message), 0) < 0) {
        printf("Error sending DATA command");
        return 1;
    }

    // receive server response
    if (recv(sock, server_response, 2000, 0) < 0) {
        printf("Error receiving server response");
        return 1;
    }
    printf("%s", server_response);

    // send email content
    char email_content[1000];
    printf("Enter email content:\n");
    fgets(email_content, 1000, stdin);
    if (send(sock, email_content, strlen(email_content), 0) < 0) {
        printf("Error sending email content");
        return 1;
    }

    // send QUIT command
    char quit_message[100] = "QUIT\r\n";
    if (send(sock, quit_message, strlen(quit_message), 0) < 0) {
        printf("Error sending QUIT command");
        return 1;
    }

    // receive server response
    if (recv(sock, server_response, 2000, 0) < 0) {
        printf("Error receiving server response");
        return 1;
    }
    printf("%s", server_response);

    // close socket
    close(sock);

    return 0;
}