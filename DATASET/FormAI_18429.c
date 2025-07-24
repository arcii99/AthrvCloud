//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: intelligent
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#define SERVER_ADDRESS "smtp.gmail.com"
#define SERVER_PORT 587

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error in socket creation");
        exit(1);
    }
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    if(connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address))) {
        perror("Error in connect");
        exit(1);
    }
    char buffer[1024];
    int numbytes;
    numbytes = recv(sockfd, buffer, 1024, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    char helo[100] = "HELO smtp.gmail.com\r\n";
    if(send(sockfd, helo, strlen(helo), 0) < 0) {
        perror("Error in sending HELO");
        exit(1);
    }
    numbytes = recv(sockfd, buffer, 1024, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    char auth[100] = "AUTH LOGIN\r\n";
    if(send(sockfd, auth, strlen(auth), 0) < 0) {
        perror("Error in sending AUTH");
        exit(1);
    }
    numbytes = recv(sockfd, buffer, 1024, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    char email[100] = "example@gmail.com";
    char password[100] = "password";
    char encoded_email[100], encoded_password[100];
    base64_encode(email, strlen(email), encoded_email, 100);
    base64_encode(password, strlen(password), encoded_password, 100);
    if(send(sockfd, encoded_email, strlen(encoded_email), 0) < 0) {
        perror("Error in sending encoded email");
        exit(1);
    }
    if(send(sockfd, "\r\n", 2, 0) < 0) {
        perror("Error in sending newline after email");
        exit(1);
    }
    numbytes = recv(sockfd, buffer, 1024, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    if(send(sockfd, encoded_password, strlen(encoded_password), 0) < 0) {
        perror("Error in sending encoded password");
        exit(1);
    }
    if(send(sockfd, "\r\n", 2, 0) < 0) {
        perror("Error in sending newline after password");
        exit(1);
    }
    numbytes = recv(sockfd, buffer, 1024, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    char mail_from[100] = "MAIL FROM:<example@gmail.com>\r\n";
    if(send(sockfd, mail_from, strlen(mail_from), 0) < 0) {
        perror("Error in sending MAIL FROM");
        exit(1);
    }
    numbytes = recv(sockfd, buffer, 1024, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    char rcpt_to[100] = "RCPT TO:<hello@gmail.com>\r\n";
    if(send(sockfd, rcpt_to, strlen(rcpt_to), 0) < 0) {
        perror("Error in sending RCPT TO");
        exit(1);
    }
    numbytes = recv(sockfd, buffer, 1024, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    char data[100] = "DATA\r\n";
    if(send(sockfd, data, strlen(data), 0) < 0) {
        perror("Error in sending DATA");
        exit(1);
    }
    numbytes = recv(sockfd, buffer, 1024, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    char subject[100] = "Subject: Email From SMTP Client Example\r\n";
    if(send(sockfd, subject, strlen(subject), 0) < 0) {
        perror("Error in sending Subject");
        exit(1);
    }
    char content[100] = "Hello there! This is an email sent from SMTP client example program.";
    if(send(sockfd, content, strlen(content), 0) < 0) {
        perror("Error in sending email content");
        exit(1);
    }
    char email_end[100] = "\r\n.\r\n";
    if(send(sockfd, email_end, strlen(email_end), 0) < 0) {
        perror("Error in sending email end");
        exit(1);
    }
    numbytes = recv(sockfd, buffer, 1024, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    char quit[100] = "QUIT\r\n";
    if(send(sockfd, quit, strlen(quit), 0) < 0) {
        perror("Error in sending QUIT");
        exit(1);
    }
    numbytes = recv(sockfd, buffer, 1024, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    close(sockfd);
    return 0;
}

void base64_encode(const char* data, const int data_len, char* encoded_data, const int encoded_data_len) {
    char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int padding = (3 - data_len % 3) % 3;
    int len = (data_len + padding) * 4 / 3;
    if(len >= encoded_data_len) {
        fprintf(stderr, "Output buffer too small\n");
        exit(1);
    }
    int i = 0, j = 0, a, b, c;
    for(; i < data_len; i+=3, j+=4) {
        a = data[i];
        b = i + 1 < data_len ? data[i + 1] : 0;
        c = i + 2 < data_len ? data[i + 2] : 0;
        encoded_data[j] = base64[a >> 2];
        encoded_data[j + 1] = base64[((a & 3) << 4) | (b >> 4)];
        encoded_data[j + 2] = base64[((b & 15) << 2) | (c >> 6)];
        encoded_data[j + 3] = base64[c & 63];
    }
    if(padding >= 1) {
        encoded_data[j - 1] = '=';
    }
    if(padding >= 2) {
        encoded_data[j - 2] = '=';
    }
    encoded_data[j] = '\0';
}