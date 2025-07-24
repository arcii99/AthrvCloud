//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "smtp.server.com" // Change this to the SMTP server you are using
#define PORT 25 // SMTP port number

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int bytes_read;
    
    // Create socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        error("Error creating socket.");
    
    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER);
    
    // Connect to server
    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        error("Error connecting to server.");
    
    // Read server response
    bytes_read = read(sock, buffer, sizeof(buffer));
    buffer[bytes_read] = '\0';
    printf("%s", buffer);
    
    // Send HELO command
    sprintf(buffer, "HELO %s\r\n", SERVER);
    if(send(sock, buffer, strlen(buffer), 0) == -1)
        error("Error sending HELO command.");
    
    // Read server response
    bytes_read = read(sock, buffer, sizeof(buffer));
    buffer[bytes_read] = '\0';
    printf("%s", buffer);
    
    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<sender@domain.com>\r\n");
    if(send(sock, buffer, strlen(buffer), 0) == -1)
        error("Error sending MAIL FROM command.");
    
    // Read server response
    bytes_read = read(sock, buffer, sizeof(buffer));
    buffer[bytes_read] = '\0';
    printf("%s", buffer);
    
    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<recipient@domain.com>\r\n");
    if(send(sock, buffer, strlen(buffer), 0) == -1)
        error("Error sending RCPT TO command.");
    
    // Read server response
    bytes_read = read(sock, buffer, sizeof(buffer));
    buffer[bytes_read] = '\0';
    printf("%s", buffer);
    
    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    if(send(sock, buffer, strlen(buffer), 0) == -1)
        error("Error sending DATA command.");
    
    // Read server response
    bytes_read = read(sock, buffer, sizeof(buffer));
    buffer[bytes_read] = '\0';
    printf("%s", buffer);
    
    // Send message body
    sprintf(buffer, "From: sender@domain.com\r\nTo: recipient@domain.com\r\nSubject: Test Email\r\n\r\nThis is a test email.\r\n");
    if(send(sock, buffer, strlen(buffer), 0) == -1)
        error("Error sending message body.");
    
    // Send period to indicate end of message
    sprintf(buffer, ".\r\n");
    if(send(sock, buffer, strlen(buffer), 0) == -1)
        error("Error sending period to indicate end of message.");
    
    // Read server response
    bytes_read = read(sock, buffer, sizeof(buffer));
    buffer[bytes_read] = '\0';
    printf("%s", buffer);
    
    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    if(send(sock, buffer, strlen(buffer), 0) == -1)
        error("Error sending QUIT command.");
    
    // Read server response
    bytes_read = read(sock, buffer, sizeof(buffer));
    buffer[bytes_read] = '\0';
    printf("%s", buffer);
    
    // Close socket
    close(sock);
    
    return 0;
}