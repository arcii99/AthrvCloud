//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: %s [server address] [username]\n", argv[0]);
        exit(1);
    }
    
    // Create a socket for the client
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket error");
        exit(1);
    }

    // Set up the server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(POP3_PORT);

    // Connect to the server
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect error");
        exit(1);
    }

    // Read the server response
    char buf[MAX_BUF_SIZE];
    memset(buf, 0, MAX_BUF_SIZE);
    if (recv(sock, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv error");
        exit(1);
    }
    printf("%s\n", buf);

    // Send the username to the server
    char user[MAX_BUF_SIZE];
    sprintf(user, "USER %s\r\n", argv[2]);
    if (send(sock, user, strlen(user), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // Read the server response
    memset(buf, 0, MAX_BUF_SIZE);
    if (recv(sock, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv error");
        exit(1);
    }
    printf("%s\n", buf);

    // Get the password from the user
    char pass[MAX_BUF_SIZE];
    printf("Enter password: ");
    scanf("%s", pass);

    // Send the password to the server
    char *cmd = "PASS ";
    size_t len = strlen(cmd) + strlen(pass) + 2; // 2 is for \r\n
    char auth[len];
    snprintf(auth, sizeof(auth), "%s%s\r\n", cmd, pass);
    if (send(sock, auth, strlen(auth), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // Read the server response
    memset(buf, 0, MAX_BUF_SIZE);
    if (recv(sock, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv error");
        exit(1);
    }
    printf("%s\n", buf);

    // List all messages
    char *list = "LIST\r\n";
    if (send(sock, list, strlen(list), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // Read the server response
    memset(buf, 0, MAX_BUF_SIZE);
    if (recv(sock, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv error");
        exit(1);
    }
    printf("%s", buf);

    // Get the message number to read
    int num;
    printf("Enter message number to read: ");
    scanf("%d", &num);

    // Retrieve the message
    char retr[MAX_BUF_SIZE];
    sprintf(retr, "RETR %d\r\n", num);
    if (send(sock, retr, strlen(retr), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // Read the server response
    memset(buf, 0, MAX_BUF_SIZE);
    if (recv(sock, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv error");
        exit(1);
    }
    printf("%s", buf);

    // Print the message
    while (1) {
        memset(buf, 0, MAX_BUF_SIZE);
        if (recv(sock, buf, MAX_BUF_SIZE, 0) < 0) {
            perror("recv error");
            exit(1);
        }

        if (buf[0] == '.' && buf[1] == '\r' && buf[2] == '\n') {
            break;
        }

        printf("%s", buf);
    }

    // Close the connection
    close(sock);

    return 0;
}