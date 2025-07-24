//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    // Check for correct usage
    if(argc != 3) {
        fprintf(stderr, "Usage: %s hostname username\n", argv[0]);
        return 1;
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    if(inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to server
    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Read server response
    char buf[BUF_SIZE];
    if(read(sock, buf, BUF_SIZE) < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Send username
    char user_cmd[BUF_SIZE];
    sprintf(user_cmd, "USER %s\r\n", argv[2]);
    if(write(sock, user_cmd, strlen(user_cmd)) < 0) {
        perror("write");
        return 1;
    }

    // Read server response
    if(read(sock, buf, BUF_SIZE) < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Prompt for password
    char password[BUF_SIZE];
    printf("Password: ");
    fgets(password, BUF_SIZE, stdin);

    // Send password
    char pass_cmd[BUF_SIZE];
    sprintf(pass_cmd, "PASS %s\r\n", password);
    if(write(sock, pass_cmd, strlen(pass_cmd)) < 0) {
        perror("write");
        return 1;
    }

    // Read server response
    if(read(sock, buf, BUF_SIZE) < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Check for successful login
    if(strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid username or password\n");
        return 1;
    }

    // Send LIST command
    if(write(sock, "LIST\r\n", 6) < 0) {
        perror("write");
        return 1;
    }

    // Read server response
    if(read(sock, buf, BUF_SIZE) < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Parse message list
    char *cur = buf + 4;
    int count = 0;
    while(*cur != '\0') {
        if(*cur == '\n') count++;
        cur++;
    }

    // Prompt for message number to retrieve
    int msg_num;
    do {
        printf("Message number to retrieve (1-%d): ", count);
        scanf("%d", &msg_num);
        getchar();
    } while(msg_num < 1 || msg_num > count);

    // Send RETR command
    char retr_cmd[BUF_SIZE];
    sprintf(retr_cmd, "RETR %d\r\n", msg_num);
    if(write(sock, retr_cmd, strlen(retr_cmd)) < 0) {
        perror("write");
        return 1;
    }

    // Read server response
    if(read(sock, buf, BUF_SIZE) < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Print message contents
    cur = buf;
    while(*cur != '\r') cur++;
    cur++;
    printf("%s", cur);

    // Send QUIT command
    if(write(sock, "QUIT\r\n", 6) < 0) {
        perror("write");
        return 1;
    }

    // Read server response
    if(read(sock, buf, BUF_SIZE) < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Close socket and return success
    close(sock);
    return 0;
}