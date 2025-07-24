//FormAI DATASET v1.0 Category: Networking ; Style: paranoid
/*
 * A paranoid networking example program
 * that forces users to authenticate themselves 
 * before sending or receiving data over a connection. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define AUTH_TOKEN "SECRET_AUTH_TOKEN"

void handle_error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, connfd, authed = 0;
    struct sockaddr_in servaddr, cli;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        handle_error("Socket creation failed");
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(8080);

    // bind socket 
    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
        handle_error("Socket bind failed");
    }

    // listen
    if ((listen(sockfd, 5)) != 0) {
        handle_error("Listen failed");
    }

    // accept connection
    int len = sizeof(cli);
    connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
    if (connfd < 0) {
        handle_error("Accept failed");
    }

    // send auth token challenge
    char challenge[128];
    snprintf(challenge, sizeof(challenge), "Please authenticate with token: %s", AUTH_TOKEN);
    send(connfd, challenge, strlen(challenge), 0);

    // receive response
    char response[128];
    memset(response, 0, sizeof(response));
    recv(connfd, response, sizeof(response), 0);

    // verify response
    if (strcmp(response, AUTH_TOKEN) != 0) {
        printf("Authentication failed. Closing connection...\n");
        close(connfd);
        exit(0);
    }

    // authentication successful
    printf("Authentication successful. Sending and receiving data...\n\n");
    authed = 1;

    while (authed) {
        // send message
        char msg[128], send_buf[256];
        printf("Enter message to send: ");
        scanf("%[^\n]%*c", msg);

        snprintf(send_buf, sizeof(send_buf), "[%s]: %s", AUTH_TOKEN, msg);
        send(connfd, send_buf, strlen(send_buf), 0);

        if (strcmp(msg, "exit") == 0) {
            printf("Closing connection...\n");
            authed = 0;
            close(connfd);
            break;
        }

        // receive message
        char recv_buf[256];
        memset(recv_buf, 0, sizeof(recv_buf));
        recv(connfd, recv_buf, sizeof(recv_buf), 0);
        
        // verify auth token in received message
        if (strstr(recv_buf, AUTH_TOKEN) == NULL) {
            printf("Received message is not from an authenticated source.\n");
        } else {
            printf("%s\n", recv_buf);
        }    
    }

    close(sockfd);
    return 0;
}