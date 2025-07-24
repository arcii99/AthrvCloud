//FormAI DATASET v1.0 Category: Email Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


char* receive_mail(int sock_fd){
    char buffer[1024] = {0};
    char* mail = malloc(sizeof(char)*1024);

    recv(sock_fd, buffer, 1024, 0);
    strcpy(mail, buffer);

    while (recv(sock_fd, buffer, 1024, 0) > 0){
        strcat(mail, buffer);
    }

    return mail;
}

void send_mail(int sock_fd, const char* mail){
    send(sock_fd, mail, strlen(mail), 0);
    printf("Mail sent to server\n");
}

int main(int argc, char const *argv[])
{
    int sock_fd;
    struct sockaddr_in server_addr;

    char mail_server_IP[20] = "192.168.0.1";
    int mail_server_port = 8080;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0){
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(mail_server_port);
    inet_pton(AF_INET, mail_server_IP, &server_addr.sin_addr);

    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        perror("connection to mail server failed");
        exit(EXIT_FAILURE);
    }
    printf("Connection to mail server established\n");

    char* mail = "From: me@myemail.com\nTo: you@youremail.com\nSubject: Hello!\n\nHey, how are you doing?\n";
    send_mail(sock_fd, mail);
    printf("Waiting for server to receive mail...\n");

    char* received_mail = receive_mail(sock_fd);
    printf("Server response:\n%s", received_mail);

    close(sock_fd);
    return 0;
}