//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF 1024

/* Function declarations */
void error(const char *msg);
void send_command(int sockfd, char *cmd);
void receive_response(int sockfd);
void send_data(int sockfd, char *data);
void send_email(int sockfd, char *from, char *to, char *subject, char *message);

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUF];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(0);
    }

    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr,
          (char*)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server");
    }

    receive_response(sockfd); // Receive server greetings

    char from[MAX_BUF], to[MAX_BUF], subject[MAX_BUF], message[MAX_BUF];

    printf("Enter your email address: ");
    fgets(from, MAX_BUF-1, stdin);
    from[strcspn(from, "\n")] = 0;

    printf("Enter recipient email address: ");
    fgets(to, MAX_BUF-1, stdin);
    to[strcspn(to, "\n")] = 0;

    printf("Enter email subject: ");
    fgets(subject, MAX_BUF-1, stdin);
    subject[strcspn(subject, "\n")] = 0;

    printf("Enter email message: ");
    fgets(message, MAX_BUF-1, stdin);
    message[strcspn(message, "\n")] = 0;

    send_email(sockfd, from, to, subject, message);

    close(sockfd); // Close connection

    return 0;
}

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) == -1) {
        error("Error sending command to server");
    }
}

void receive_response(int sockfd) {
    char buffer[MAX_BUF];
    int n = recv(sockfd, buffer, MAX_BUF-1, 0);
    if (n == -1) {
        error("Error receiving response from server");
    }
    buffer[n] = '\0';
    printf("%s", buffer);
}

void send_data(int sockfd, char *data) {
    if (send(sockfd, data, strlen(data), 0) == -1) {
        error("Error sending data to server");
    }
}

void send_email(int sockfd, char *from, char *to, char *subject, char *message) {
    // Send HELO command
    char helo[MAX_BUF];
    sprintf(helo, "HELO %s\r\n", from);
    send_command(sockfd, helo);
    receive_response(sockfd);

    // Send MAIL FROM command
    char mail_from[MAX_BUF];
    sprintf(mail_from, "MAIL FROM: <%s>\r\n", from);
    send_command(sockfd, mail_from);
    receive_response(sockfd);

    // Send RCPT TO command
    char rcpt_to[MAX_BUF];
    sprintf(rcpt_to, "RCPT TO: <%s>\r\n", to);
    send_command(sockfd, rcpt_to);
    receive_response(sockfd);

    // Send DATA command
    send_command(sockfd, "DATA\r\n");
    receive_response(sockfd);

    // Send email header and message
    char buffer[MAX_BUF];
    sprintf(buffer, "From: %s\r\n"
                    "To: %s\r\n"
                    "Subject: %s\r\n\r\n"
                    "%s\r\n.\r\n", from, to, subject, message);
    send_data(sockfd, buffer);
    receive_response(sockfd);

    // Send QUIT command
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);
}