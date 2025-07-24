//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: grateful
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h> 

#define MAXLINE 1024 

int main(int argc, char **argv) 
{ 
    int sockfd, n; 
    char recvline[MAXLINE + 1]; 
    struct sockaddr_in servaddr; 
    
    if (argc != 2) 
    {
        perror("usage: ./smtpclient <IP address>"); 
        exit(1); 
    }
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    {
        perror("socket error"); 
        exit(2); 
    }
  
    bzero(&servaddr, sizeof servaddr); 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(25); 

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) 
    {
        perror("inet_pton error"); 
        exit(3); 
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof servaddr) < 0) 
    {
        perror("connect error"); 
        exit(4); 
    }
	
    printf("Connected!\n");

    char *helo = "HELO example.com\r\n";
    send(sockfd, helo, strlen(helo), 0);
    recv(sockfd, recvline, MAXLINE, 0);

    printf("%s\n", recvline);

    char *mail_from = "MAIL FROM: <test@example.com>\r\n";
    send(sockfd, mail_from, strlen(mail_from), 0);
    recv(sockfd, recvline, MAXLINE, 0);

    printf("%s\n", recvline);

    char *rcpt_to = "RCPT TO: <you@example.com>\r\n";
    send(sockfd, rcpt_to, strlen(rcpt_to), 0);
    recv(sockfd, recvline, MAXLINE, 0);

    printf("%s\n", recvline);

    char *data = "DATA\r\n";
    send(sockfd, data, strlen(data), 0);
    recv(sockfd, recvline, MAXLINE, 0);

    printf("%s\n", recvline);

    char *message = "Subject: Test\r\nThis is a test message\r\n.\r\n";
    send(sockfd, message, strlen(message), 0);
    recv(sockfd, recvline, MAXLINE, 0);

    printf("%s\n", recvline);

    char *quit = "QUIT\r\n";
    send(sockfd, quit, strlen(quit), 0);
    recv(sockfd, recvline, MAXLINE, 0);

    printf("%s\n", recvline);

    close(sockfd);

    return 0; 
}