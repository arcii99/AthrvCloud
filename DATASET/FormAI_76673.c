//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 25
#define SERVER_ADDR "smtp.example.com"

void send_mail(int sock, char* to, char* from, char* subject, char* body)
{
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    
    sprintf(buffer, "HELO %s\r\n", SERVER_ADDR);
    send(sock, buffer, strlen(buffer), 0);
    
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "MAIL FROM: <%s>\r\n", from);
    send(sock, buffer, strlen(buffer), 0);
    
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "RCPT TO: <%s>\r\n", to);
    send(sock, buffer, strlen(buffer), 0);
    
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);
    
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "To: %s\r\nFrom: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", to, from, subject, body);
    send(sock, buffer, strlen(buffer), 0);
}

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char *to = "recipient@example.com";
    char *from = "sender@example.com";
    char *subject = "Test Email";
    char *body = "This is a test email.";
    
    // Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }

    server.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);

    // Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("Failed to connect");
        return 1;
    }
    
    // Send email
    send_mail(sock, to, from, subject, body);

    // Close socket
    close(sock);
    return 0;
}