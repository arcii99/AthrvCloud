//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){

    if(argc != 4){
        printf("\nUsage: %s <smtp-server> <from-email> <to-email>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        perror("Error: Failed to create socket");
        return 1;
    }

    printf("\nSocket created successfully!");

    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);

    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("Error: Connection failed");
        return 1;
    }

    printf("\nConnected to %s successfully!", argv[1]);

    if(recv(sock, buffer, BUFFER_SIZE, 0) < 0){
        perror("Error: Response receiving failed");
        return 1;
    }

    printf("\nServer Response: %s", buffer);

    memset(buffer, '\0', BUFFER_SIZE);
    sprintf(buffer, "HELO %s\r\n", argv[1]);

    if(send(sock, buffer, strlen(buffer), 0) < 0){
        perror("Error: EHLO failed");
        return 1;
    }

    if(recv(sock, buffer, BUFFER_SIZE, 0) < 0){
        perror("Error: Response receiving failed");
        return 1;
    }

    printf("\nServer Response: %s", buffer);

    memset(buffer, '\0', BUFFER_SIZE);
    sprintf(buffer, "MAIL FROM:<%s>\r\n", argv[2]);

    if(send(sock, buffer, strlen(buffer), 0) < 0){
        perror("Error: MAIL FROM failed");
        return 1;
    }

    if(recv(sock, buffer, BUFFER_SIZE, 0) < 0){
        perror("Error: Response receiving failed");
        return 1;
    }

    printf("\nServer Response: %s", buffer);

    memset(buffer, '\0', BUFFER_SIZE);
    sprintf(buffer, "RCPT TO:<%s>\r\n", argv[3]);

    if(send(sock, buffer, strlen(buffer), 0) < 0){
        perror("Error: RCPT TO failed");
        return 1;
    }

    if(recv(sock, buffer, BUFFER_SIZE, 0) < 0){
        perror("Error: Response receiving failed");
        return 1;
    }

    printf("\nServer Response: %s", buffer);

    memset(buffer, '\0', BUFFER_SIZE);
    sprintf(buffer, "DATA\r\n");

    if(send(sock, buffer, strlen(buffer), 0) < 0){
        perror("Error: DATA failed");
        return 1;
    }

    if(recv(sock, buffer, BUFFER_SIZE, 0) < 0){
        perror("Error: Response receiving failed");
        return 1;
    }

    printf("\nServer Response: %s", buffer);

    memset(buffer, '\0', BUFFER_SIZE);
    sprintf(buffer, "From: %s\r\n", argv[2]);
    sprintf(buffer+strlen(buffer), "To: %s\r\n", argv[3]);
    sprintf(buffer+strlen(buffer), "Subject: SMTP Client Example\r\n");
    sprintf(buffer+strlen(buffer), "\r\n");
    sprintf(buffer+strlen(buffer), "Welcome to SMTP Client Example!!");

    if(send(sock, buffer, strlen(buffer), 0) < 0){
        perror("Error: Sending data failed");
        return 1;
    }

    memset(buffer, '\0', BUFFER_SIZE);
    sprintf(buffer, "\r\n.\r\n");

    if(send(sock, buffer, strlen(buffer), 0) < 0){
        perror("Error: End of data failed");
        return 1;
    }

    if(recv(sock, buffer, BUFFER_SIZE, 0) < 0){
        perror("Error: Response receiving failed");
        return 1;
    }

    printf("\nServer Response: %s", buffer);

    memset(buffer, '\0', BUFFER_SIZE);
    sprintf(buffer, "QUIT\r\n");

    if(send(sock, buffer, strlen(buffer), 0) < 0){
        perror("Error: Quit failed");
        return 1;
    }

    if(recv(sock, buffer, BUFFER_SIZE, 0) < 0){
        perror("Error: Response receiving failed");
        return 1;
    }

    printf("\nServer Response: %s\n", buffer);

    return 0;
}