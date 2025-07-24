//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv)
{
    if(argc != 4)
    {
        fprintf(stderr, "Usage: %s <smtp server> <from email> <to email>\n", argv[0]);
        return -1;
    }

    const char* server = argv[1];
    const char* from = argv[2];
    const char* to = argv[3];

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("socket");
        return -1;
    }

    // Get server information
    struct hostent* he = gethostbyname(server);
    if(!he)
    {
        fprintf(stderr, "Failed to get server information\n");
        return -1;
    }

    // Set server address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr = *((struct in_addr*) he->h_addr);
    addr.sin_port = htons(25);

    // Connect to server
    if(connect(sockfd, (struct sockaddr*) &addr, sizeof(addr)) < 0)
    {
        perror("connect");
        return -1;
    }

    // Receive server greeting
    char buf[1024];
    ssize_t n = recv(sockfd, buf, sizeof(buf), 0);
    if(n < 0)
    {
        perror("recv");
        return -1;
    }
    buf[n] = '\0';
    printf("Server greeting: %s", buf);

    // Send HELO
    char helo[1024];
    sprintf(helo, "HELO %s\r\n", server);
    n = send(sockfd, helo, strlen(helo), 0);
    if(n < 0)
    {
        perror("send");
        return -1;
    }
    printf("Sent: %s", helo);

    // Receive response
    n = recv(sockfd, buf, sizeof(buf), 0);
    if(n < 0)
    {
        perror("recv");
        return -1;
    }
    buf[n] = '\0';
    printf("Received: %s", buf);

    // Send MAIL FROM
    char mail_from[1024];
    sprintf(mail_from, "MAIL FROM:<%s>\r\n", from);
    n = send(sockfd, mail_from, strlen(mail_from), 0);
    if(n < 0)
    {
        perror("send");
        return -1;
    }
    printf("Sent: %s", mail_from);

    // Receive response
    n = recv(sockfd, buf, sizeof(buf), 0);
    if(n < 0)
    {
        perror("recv");
        return -1;
    }
    buf[n] = '\0';
    printf("Received: %s", buf);

    // Send RCPT TO
    char rcpt_to[1024];
    sprintf(rcpt_to, "RCPT TO:<%s>\r\n", to);
    n = send(sockfd, rcpt_to, strlen(rcpt_to), 0);
    if(n < 0)
    {
        perror("send");
        return -1;
    }
    printf("Sent: %s", rcpt_to);

    // Receive response
    n = recv(sockfd, buf, sizeof(buf), 0);
    if(n < 0)
    {
        perror("recv");
        return -1;
    }
    buf[n] = '\0';
    printf("Received: %s", buf);

    // Send DATA
    char data[1024];
    sprintf(data, "DATA\r\n");
    n = send(sockfd, data, strlen(data), 0);
    if(n < 0)
    {
        perror("send");
        return -1;
    }
    printf("Sent: %s", data);

    // Receive response
    n = recv(sockfd, buf, sizeof(buf), 0);
    if(n < 0)
    {
        perror("recv");
        return -1;
    }
    buf[n] = '\0';
    printf("Received: %s", buf);

    // Send message body
    char body[1024];
    sprintf(body, "From: %s\r\nTo: %s\r\nSubject: Test message\r\n\r\nHello, this is a test message sent from my SMTP client.\r\n.\r\n", from, to);
    n = send(sockfd, body, strlen(body), 0);
    if(n < 0)
    {
        perror("send");
        return -1;
    }
    printf("Sent: %s", body);

    // Receive response
    n = recv(sockfd, buf, sizeof(buf), 0);
    if(n < 0)
    {
        perror("recv");
        return -1;
    }
    buf[n] = '\0';
    printf("Received: %s", buf);

    // Send QUIT
    char quit[1024];
    sprintf(quit, "QUIT\r\n");
    n = send(sockfd, quit, strlen(quit), 0);
    if(n < 0)
    {
        perror("send");
        return -1;
    }
    printf("Sent: %s", quit);

    // Receive response
    n = recv(sockfd, buf, sizeof(buf), 0);
    if(n < 0)
    {
        perror("recv");
        return -1;
    }
    buf[n] = '\0';
    printf("Received: %s", buf);

    // Close socket
    close(sockfd);

    return 0;
}