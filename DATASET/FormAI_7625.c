//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_address;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(25); // use port 25 for SMTP
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost IP address

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error connecting to SMTP server");
        exit(1);
    }

    // send email
    char *email_data = "To: example@example.com\nSubject: Test email\n\nThis is a test email";
    int sent = send(sockfd, email_data, strlen(email_data), 0);

    if (sent < 0) {
        printf("Error sending email");
        exit(1);
    }

    // receive response
    char response[256];
    int received = recv(sockfd, response, 255, 0);

    if (received < 0) {
        printf("Error receiving response from server");
        exit(1);
    }

    // close socket
    close(sockfd);

    return 0;
}