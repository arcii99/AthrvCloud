//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 4096
#define SERVER_PORT 143

void read_response(int sock) {
    char recvline[MAX_LINE + 1];
    ssize_t n;
    while((n = read(sock, recvline, MAX_LINE)) > 0) {
        recvline[n] = '\0';
        printf("%s", recvline);
        if(strstr(recvline, " OK ") != NULL) break;
    }
}

void get_mailboxes(int sock) {
    send(sock, "1 LIST \"\" *\r\n", 13, 0);
    read_response(sock);
}

void select_mailbox(int sock, char *mailbox) {
    char command[MAX_LINE];
    sprintf(command, "2 SELECT \"%s\"\r\n", mailbox);
    send(sock, command, strlen(command), 0);
    read_response(sock);
}

int main(int argc, char **argv) {
    if(argc != 4) {
        printf("Usage: ./imap_client <ip> <username> <password>\n");
        return -1;
    }

    char *ip = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(SERVER_PORT);

    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return -1;
    }

    read_response(sock);

    char login_command[MAX_LINE];
    sprintf(login_command, "1 LOGIN %s %s\r\n", username, password);
    send(sock, login_command, strlen(login_command), 0);
    read_response(sock);

    get_mailboxes(sock);
    select_mailbox(sock, "INBOX");

    return 0;
}