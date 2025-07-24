//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: scientific
/* SMTP Client Example Program in C*/
/* Written by [Your Name and/or Username] */
/* Date: [Date of Development] */
/* Description: This program is a simple SMTP client that sends an email message to a specified email address using a mail server.*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_MSG_LEN 1024
#define SMTP_PORT 25

/* Function to read input from user */
void read_input(char *input) {
    printf("Enter message:\n");
    fgets(input, MAX_MSG_LEN, stdin);
}

/* Function to send mail */
void send_mail(char *server_address, char *to_address, char *from_address, char *subject, char *body) {
    int sock;
    struct sockaddr_in mail_server;
    char message[MAX_MSG_LEN];
    char server_response[MAX_MSG_LEN];

    /* Create socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation error");
        return;
    }

    /* Configure mail server address and port */
    mail_server.sin_addr.s_addr = inet_addr(server_address);
    mail_server.sin_family = AF_INET;
    mail_server.sin_port = htons(SMTP_PORT);

    /* Connect to mail server */
    if (connect(sock, (struct sockaddr *)&mail_server, sizeof(mail_server)) < 0) {
        perror("Connection error");
        close(sock);
        return;
    }

    /* Receive greeting message */
    recv(sock, server_response, MAX_MSG_LEN, 0);

    /* Send HELO command */
    sprintf(message, "HELO %s\r\n", server_address);
    send(sock, message, strlen(message), 0);
    recv(sock, server_response, MAX_MSG_LEN, 0);

    /* Send MAIL FROM command */
    sprintf(message, "MAIL FROM: <%s>\r\n", from_address);
    send(sock, message, strlen(message), 0);
    recv(sock, server_response, MAX_MSG_LEN, 0);

    /* Send RCPT TO command */
    sprintf(message, "RCPT TO: <%s>\r\n", to_address);
    send(sock, message, strlen(message), 0);
    recv(sock, server_response, MAX_MSG_LEN, 0);

    /* Send DATA command */
    sprintf(message, "DATA\r\n");
    send(sock, message, strlen(message), 0);
    recv(sock, server_response, MAX_MSG_LEN, 0);

    /* Send mail message */
    sprintf(message, "To: <%s>\r\nFrom: <%s>\r\nSubject: %s\r\n%s\r\n.\r\n", to_address, from_address, subject, body);
    send(sock, message, strlen(message), 0);
    recv(sock, server_response, MAX_MSG_LEN, 0);

    /* Send QUIT command */
    sprintf(message, "QUIT\r\n");
    send(sock, message, strlen(message), 0);
    recv(sock, server_response, MAX_MSG_LEN, 0);

    /* Close socket */
    close(sock);
}

/* Main function */
int main(int argc, char *argv[]) {
    char input[MAX_MSG_LEN];
    char *server_address, *to_address, *from_address, *subject, *body;

    if (argc < 5) {
        fprintf(stderr, "Usage: %s <server_address> <to_address> <from_address> <subject>\n", argv[0]);
        return 1;
    }

    server_address = argv[1];
    to_address = argv[2];
    from_address = argv[3];
    subject = argv[4];

    /* Read message body from user */
    read_input(input);
    body = input;

    /* Send mail */
    send_mail(server_address, to_address, from_address, subject, body);

    return 0;
}