//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char client_name[BUFFER_SIZE], server_name[BUFFER_SIZE];
    
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    
    // Fill in server address
    memset(&serv_addr, 0, sizeof(struct sockaddr_in));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0)
        error("ERROR invalid address");
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");
    
    // Receive greeting message from server
    if ((n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) < 0)
        error("ERROR receiving greeting message");
    buffer[n] = '\0';
    printf("%s", buffer);
    
    // Send HELO/EHLO
    sprintf(client_name, "HELO %s\r\n", argv[1]);
    if (send(sockfd, client_name, strlen(client_name), 0) < 0)
        error("ERROR sending HELO command");
    if ((n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) < 0)
        error("ERROR receiving server response");
    buffer[n] = '\0';
    printf("%s", buffer);
    
    // Send MAIL FROM
    printf("Enter the sender email address: ");
    fgets(buffer, BUFFER_SIZE - 1, stdin);
    sprintf(client_name, "MAIL FROM: <%s>\r\n", buffer);
    if (send(sockfd, client_name, strlen(client_name), 0) < 0)
        error("ERROR sending MAIL FROM command");
    if ((n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) < 0)
        error("ERROR receiving server response");
    buffer[n] = '\0';
    printf("%s", buffer);
    
    // Send RCPT TO
    printf("Enter the recipient email address: ");
    fgets(buffer, BUFFER_SIZE - 1, stdin);
    sprintf(client_name, "RCPT TO: <%s>\r\n", buffer);
    if (send(sockfd, client_name, strlen(client_name), 0) < 0)
        error("ERROR sending RCPT TO command");
    if ((n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) < 0)
        error("ERROR receiving server response");
    buffer[n] = '\0';
    printf("%s", buffer);
    
    // Send DATA
    if (send(sockfd, "DATA\r\n", 6, 0) < 0)
        error("ERROR sending DATA command");
    if ((n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) < 0)
        error("ERROR receiving server response");
    buffer[n] = '\0';
    printf("%s", buffer);
    
    // Send message body
    printf("Enter the message body (end with a single dot '.'): \n");
    while (fgets(buffer, BUFFER_SIZE - 1, stdin) != NULL) {
        if (strcmp(buffer, ".\n") == 0) break;
        if (send(sockfd, buffer, strlen(buffer), 0) < 0)
            error("ERROR sending message body");
    }
    if ((n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) < 0)
        error("ERROR receiving server response");
    buffer[n] = '\0';
    printf("%s", buffer);
    
    // Send QUIT
    if (send(sockfd, "QUIT\r\n", 6, 0) < 0)
        error("ERROR sending QUIT command");
    if ((n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) < 0)
        error("ERROR receiving server response");
    buffer[n] = '\0';
    printf("%s", buffer);
    
    // Close socket
    close(sockfd);
    
    return 0;
}