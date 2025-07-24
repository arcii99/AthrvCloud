//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define MAX 1024
#define POP3_PORT 110

void error(char *msg) {
    printf("Error: %s\n", msg);
    exit(1);
}

int main(int argc, char* argv[]) {
    int sockfd, n_read, i, j, k;
    char recv_buffer[MAX], send_buffer[MAX], username[MAX], password[MAX], response[MAX], command[MAX];
    struct sockaddr_in server;

    if(argc < 2) {
        printf("Usage: %s <pop3_server_ip_address>\n", argv[0]);
        exit(1);
    }

    //create socket
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("socket failed");
    }

    //set sockaddr_in structure data
    server.sin_family = AF_INET;
    server.sin_port = htons(POP3_PORT);
    server.sin_addr.s_addr = inet_addr(argv[1]);

    //try to connect to pop3 server
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("connect failed");
    }

    //read greeting message from server
    if((n_read = read(sockfd, recv_buffer, MAX)) < 0) {
        error("read failed");
    }

    printf("%s", recv_buffer);

    //get username and password from user
    printf("Username: ");
    fgets(username, MAX, stdin);
    printf("Password: ");
    fgets(password, MAX, stdin);
    username[strcspn(username, "\n")] = 0;
    password[strcspn(password, "\n")] = 0;

    //send username to server
    snprintf(send_buffer, sizeof(send_buffer), "USER %s\r\n", username);
    if(send(sockfd, send_buffer, strlen(send_buffer), 0) < 0) {
        error("send failed");
    }

    //read response from server
    if((n_read = read(sockfd, response, MAX)) < 0) {
        error("read failed");
    }

    printf("%s", response);

    //send password to server
    snprintf(send_buffer, sizeof(send_buffer), "PASS %s\r\n", password);
    if(send(sockfd, send_buffer, strlen(send_buffer), 0) < 0) {
        error("send failed");
    }

    //read response from server
    if((n_read = read(sockfd, response, MAX)) < 0) {
        error("read failed");
    }

    printf("%s", response);

    //get number of messages
    snprintf(send_buffer, sizeof(send_buffer), "STAT\r\n");
    if(send(sockfd, send_buffer, strlen(send_buffer), 0) < 0) {
        error("send failed");
    }

    //read response from server
    if((n_read = read(sockfd, response, MAX)) <0) {
        error("read failed");
    }

    printf("%s", response);

    //get list of all messages
    snprintf(send_buffer, sizeof(send_buffer), "LIST\r\n");
    if(send(sockfd, send_buffer, strlen(send_buffer), 0) < 0) {
        error("send failed");
    }

    //read response from server
    if((n_read = read(sockfd, response, MAX)) <0) {
        error("read failed");
    }

    printf("%s", response);

    //get message headers
    for(i = 1; i < 4; i++) {
        snprintf(send_buffer, sizeof(send_buffer), "TOP %d 0\r\n", i);
        if(send(sockfd, send_buffer, strlen(send_buffer), 0) < 0) {
            error("send failed");
        }

        //read response from server
        if((n_read = read(sockfd, response, MAX)) <0) {
            error("read failed");
        }

        printf("%s", response);
    }

    //quit from server
    snprintf(send_buffer, sizeof(send_buffer), "QUIT\r\n");
    if(send(sockfd, send_buffer, strlen(send_buffer), 0) < 0) {
        error("send failed");
    }

    //read response from server
    if((n_read = read(sockfd, response, MAX)) < 0) {
        error("read failed");
    }

    printf("%s", response);

    //close socket
    close(sockfd);

    return 0;
}