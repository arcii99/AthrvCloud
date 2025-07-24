//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: active
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

#define MAX_LINE 4096

int main(int argc, char* argv[]){

    int sockfd, n;
    char recvline[MAX_LINE+1];
    struct sockaddr_in servaddr;

    if(argc != 2){
        printf("Usage: %s <server_address>\n", argv[0]);
        return 0;
    }
    
    //Creating an IPv4 socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Error creating socket.\n");
        return 0;
    }

    //Setting up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(25);
    if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0){
        printf("Invalid Server Address.\n");
        return 0;
    }

    //Connecting to the server
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        printf("Unable to connect to the server.\n");
        return 0;
    }

    //Receiving the welcome message from the SMTP Server
    n = read(sockfd, recvline, MAX_LINE);
    if(n < 0){
        printf("Error receiving message from server.\n");
        return 0;
    }
 
    recvline[n] = 0;
    printf("%s\n", recvline);

    //Sending the HELO command to the SMTP Server
    char helo[50] = "HELO example.com\r\n";
    if(send(sockfd, helo, strlen(helo), 0) < 0){
        printf("Error sending message to server.\n");
        return 0;
    }
    
    //Receiving the response from the SMTP Server
    n = read(sockfd, recvline, MAX_LINE);
    if(n < 0){
        printf("Error receiving message from server.\n");
        return 0;
    }
 
    recvline[n] = 0;
    printf("%s\n", recvline);

    //Sending the MAIL FROM command to the SMTP Server
    char mailfrom[50] = "MAIL FROM:<sender@example.com>\r\n";
    if(send(sockfd, mailfrom, strlen(mailfrom), 0) < 0){
        printf("Error sending message to server.\n");
        return 0;
    }
    
    //Receiving the response from the SMTP Server
    n = read(sockfd, recvline, MAX_LINE);
    if(n < 0){
        printf("Error receiving message from server.\n");
        return 0;
    }
 
    recvline[n] = 0;
    printf("%s\n", recvline);

    //Sending the RCPT TO command to the SMTP Server
    char rcptto[50] = "RCPT TO:<receiver@example.com>\r\n";
    if(send(sockfd, rcptto, strlen(rcptto), 0) < 0){
        printf("Error sending message to server.\n");
        return 0;
    }
    
    //Receiving the response from the SMTP Server
    n = read(sockfd, recvline, MAX_LINE);
    if(n < 0){
        printf("Error receiving message from server.\n");
        return 0;
    }
 
    recvline[n] = 0;
    printf("%s\n", recvline);

    //Sending the DATA command to the SMTP Server
    char data[50] = "DATA\r\n";
    if(send(sockfd, data, strlen(data), 0) < 0){
        printf("Error sending message to server.\n");
        return 0;
    }

    //Receiving the response from the SMTP Server
    n = read(sockfd, recvline, MAX_LINE);
    if(n < 0){
        printf("Error receiving message from server.\n");
        return 0;
    }
 
    recvline[n] = 0;
    printf("%s\n", recvline);

    //Sending the message body to the SMTP Server
    char message[100] = "Subject: SMTP Test\n\nHello, this is a test email.\n\nRegards,\nSender";
    if(send(sockfd, message, strlen(message), 0) < 0){
        printf("Error sending message to server.\n");
        return 0;
    }
    
    //Sending the QUIT command to the SMTP Server
    char quit[50] = "QUIT\r\n";
    if(send(sockfd, quit, strlen(quit), 0) < 0){
        printf("Error sending message to server.\n");
        return 0;
    }
    
    //Closing the socket
    close(sockfd);

    return 0;
}