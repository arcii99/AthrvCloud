//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define MAX 1024
#define PORT 110

typedef struct message {
    char *header;
    char *body;
    char *footer;
} Message;

void receiveMessage(int sock) {
    char buffer[MAX] = {0};
    read(sock, buffer, MAX);
    printf("%s\n", buffer);
}

void quit(int sock) {
    char buffer[MAX] = "QUIT\r\n";
    send(sock, buffer, strlen(buffer), 0);
    receiveMessage(sock);
}

void auth(int sock) {
    char username[MAX];
    char password[MAX];
    printf("Enter username:\n");
    fgets(username, MAX, stdin);
    printf("Enter password:\n");
    fgets(password, MAX, stdin);
    char buffer[MAX] = {0};
    snprintf(buffer, MAX, "USER %sPASS %s\r\n", username, password);
    send(sock, buffer, strlen(buffer), 0);
    receiveMessage(sock);
}

void retr(int sock, int msgNum) {
    char buffer[MAX] = {0};
    snprintf(buffer, MAX, "RETR %d\r\n", msgNum);
    send(sock, buffer, strlen(buffer), 0);
    receiveMessage(sock);
}

Message parseMessage(char *raw) {
    char *header;
    char *body;
    char *footer;
    int i;
    for(i = 0; i < strlen(raw); i++) {
        if(raw[i] == '\r' && raw[i+1] == '\n') {
            if(header == NULL) {
                header = strndup(raw, i+1);
                raw += i+2;
                i = 0;
                continue;
            }
            if(body == NULL) {
                body = strndup(raw, i+1);
                raw += i+2;
                i = 0;
                continue;
            }
            if(footer == NULL) {
                footer = strndup(raw, i+1);
                break;
            }
        }
    }
    Message msg = {header, body, footer};
    return msg;
}

int main() {
    int sock = 0;
    struct sockaddr_in serverAddr;

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }
    printf("Socket created successfully\n");

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0) {
        printf("Invalid address error\n");
        return -1;
    }
    printf("Address initialized successfully\n");

    if(connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("Connection error\n");
        return -1;
    }
    printf("Connected to server\n");

    receiveMessage(sock);

    auth(sock);

    char buffer[MAX] = "LIST\r\n";
    send(sock, buffer, strlen(buffer), 0);
    receiveMessage(sock);

    printf("Enter message number to view:\n");
    int msgNum;
    scanf("%d", &msgNum);
    retr(sock, msgNum);

    char resp[MAX] = {0};
    read(sock, resp, MAX);
    Message msg = parseMessage(resp);

    printf("Header:\n%s\n", msg.header);
    printf("Body:\n%s\n", msg.body);
    printf("Footer:\n%s\n", msg.footer);

    quit(sock);

    close(sock);
    return 0;
}