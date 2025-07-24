//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

/* This function establishes a connection to the IMAP server */
int connect_to_imap(const char* server, int port, int *sockfd) {
    int connfd;
    struct sockaddr_in servaddr;
   
    connfd = socket(AF_INET, SOCK_STREAM, 0); // create socket
    
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_port = htons(port); // port number
    
    if (inet_pton(AF_INET, server, &servaddr.sin_addr) <= 0) {
        perror("inet_pton failed");
        return -1;
    }
    
    if (connect(connfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Connect failed");
        return -1;
    }

    *sockfd = connfd;
    return 0;
}

/* This function sends a command to the IMAP server */
int send_imap_cmd(int sockfd, const char *cmd) {
    char buf[BUF_SIZE];
    ssize_t n = snprintf(buf, BUF_SIZE, "%s\r\n", cmd);
    
    write(sockfd, buf, n);
   
    return 0;
}

/* This function reads server response */
int read_imap_resp(int sockfd, char *buf, size_t buf_size) {
    ssize_t n = read(sockfd, buf, buf_size-1);
    buf[n] = '\0';  // append null terminator
    return 0;
}

int main() {
    int sockfd;
    char buf[BUF_SIZE];
    const char* server = "imap.gmail.com";
    const int port = 993;
  
    if (connect_to_imap(server, port, &sockfd) != 0) {
        printf("Failed to connect to IMAP server\n");
        return -1;
    }

    read_imap_resp(sockfd, buf, BUF_SIZE);
    printf("Server response: %s\n", buf);  // expect "* OK Gimap ready for requests"

    // send login command
    send_imap_cmd(sockfd, "LOGIN username password");

    read_imap_resp(sockfd, buf, BUF_SIZE);
    printf("Server response: %s\n", buf);  // expect "LOGIN completed"

    // send select command
    send_imap_cmd(sockfd, "SELECT INBOX");

    read_imap_resp(sockfd, buf, BUF_SIZE);
    printf("Server response: %s\n", buf);  // expect "SELECT completed"

    // send fetch command
    send_imap_cmd(sockfd, "FETCH 1 BODY[TEXT]");

    read_imap_resp(sockfd, buf, BUF_SIZE);
    printf("Server response: %s\n", buf);  // expect "FETCH completed"

    // send logout command
    send_imap_cmd(sockfd, "LOGOUT");

    read_imap_resp(sockfd, buf, BUF_SIZE);
    printf("Server response: %s\n", buf);  // expect "LOGOUT completed"

    close(sockfd);  // close connection

    return 0;
}