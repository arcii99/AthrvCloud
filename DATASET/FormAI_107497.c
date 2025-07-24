//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char message[2000], server_reply[2000];

    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 25 );

    //Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Connect error");
        return 1;
    }

    printf("Connected\n");

    //Receive greeting message from server
    if(recv(sock, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    //Send EHLO command to server
    strcpy(message, "EHLO example.com\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }

    //Receive response from server
    if(recv(sock, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    //Send MAIL FROM command to server
    strcpy(message, "MAIL FROM:<example@example.com>\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }

    //Receive response from server
    if(recv(sock, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    //Send RCPT TO command to server
    strcpy(message, "RCPT TO:<recipient@example.com>\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }

    //Receive response from server
    if(recv(sock, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    //Send DATA command to server
    strcpy(message, "DATA\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }

    //Receive response from server
    if(recv(sock, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    //Send message content to server
    strcpy(message, "From: example@example.com\r\nTo: recipient@example.com\r\nSubject: Test\r\n\r\nThis is a test message.\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }

    //Send end of message indicator to server
    strcpy(message, "\r\n.\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }

    //Receive response from server
    if(recv(sock, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    //Send QUIT command to server
    strcpy(message, "QUIT\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }

    //Receive response from server
    if(recv(sock, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    //Close socket
    close(sock);
    return 0;
}