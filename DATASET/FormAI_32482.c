//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#define PORT 110

/* Function to establish a connection with the server */
int connect_to_server(char* server_ip)
{
    int sockfd;
    struct sockaddr_in server;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        printf("Socket creation error!\n");
        exit(1);
    }
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_ip);
    server.sin_port = htons(PORT);
    if(connect(sockfd, (struct sockaddr*)&server, sizeof(server)) != 0)
    {
        printf("Connection error!\n");
        exit(1);
    }
    char recv_msg[1024];
    memset(recv_msg, 0, sizeof(recv_msg));
    recv(sockfd, recv_msg, sizeof(recv_msg), 0);
    printf("%s", recv_msg);
    return sockfd;
}

/* Function to receive response from the server */
void receive_response(int sockfd)
{
    char recv_msg[1024];
    memset(recv_msg, 0, sizeof(recv_msg));
    recv(sockfd, recv_msg, sizeof(recv_msg), 0);
    printf("%s", recv_msg);
}

/* Function to send request to the server */
void send_request(int sockfd, char* message)
{
    char send_msg[1024];
    memset(send_msg, 0, sizeof(send_msg));
    snprintf(send_msg, sizeof(send_msg), message);
    send(sockfd, send_msg, strlen(send_msg), 0);
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s <server_ip>\n", argv[0]);
        exit(1);
    }
    int sockfd = connect_to_server(argv[1]);
    /* Login Request */
    send_request(sockfd, "USER username\n");
    receive_response(sockfd);
    send_request(sockfd, "PASS password\n");
    receive_response(sockfd);
    /* STAT Request */
    send_request(sockfd, "STAT\n");
    receive_response(sockfd);
    /* LIST Request */
    send_request(sockfd, "LIST\n");
    receive_response(sockfd);
    /* RETR Request */
    send_request(sockfd, "RETR 1\n");
    receive_response(sockfd);
    /* DELE Request */
    send_request(sockfd, "DELE 1\n");
    receive_response(sockfd);
    /* QUIT Request */
    send_request(sockfd, "QUIT\n");
    receive_response(sockfd);
    close(sockfd);
    return 0;
}