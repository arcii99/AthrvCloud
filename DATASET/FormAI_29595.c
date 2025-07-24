//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define LOGIN_MSG "Login successful...\n"
#define WELCOME_MSG "Welcome to the cyberFTP server!\n"
#define ERROR_MSG "Error: "

void login(int sockfd) {
    char username[BUFFER_SIZE], password[BUFFER_SIZE];
    int res;
    printf("Enter username: ");
    fflush(stdout);
    scanf("%s", username);
    send(sockfd, username, strlen(username) + 1, 0);
    printf("Enter password: ");
    fflush(stdout);
    scanf("%s", password);
    send(sockfd, password, strlen(password) + 1, 0);
    recv(sockfd, &res, sizeof(res), 0);
    if (res != 0) {
        printf(ERROR_MSG "Login failed\n");
        exit(1);
    }
    printf(LOGIN_MSG);
}

void receive_file(int sockfd, char* filename) {
    char buffer[BUFFER_SIZE];
    int recvfd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    while (1) {
        int bytesReceived = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytesReceived == 0) break;
        write(recvfd, buffer, bytesReceived);
    }
    close(recvfd);
}

void send_file(int sockfd, char* filename) {
    char buffer[BUFFER_SIZE];
    int sendfd = open(filename, O_RDONLY);
    while (1) {
        int bytesRead = read(sendfd, buffer, BUFFER_SIZE);
        if (bytesRead == 0) break;
        send(sockfd, buffer, bytesRead, 0);
    }
    close(sendfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf(ERROR_MSG "Usage: %s [server IP] [username] [password]\n", argv[0]);
        exit(1);
    }

    struct sockaddr_in serv_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf(ERROR_MSG "Error opening socket.\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(21);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf(ERROR_MSG "Error connecting to server.\n");
        exit(1);
    }

    char msg[BUFFER_SIZE];
    recv(sockfd, msg, BUFFER_SIZE, 0);

    if (strcmp(msg, WELCOME_MSG) != 0) {
        printf(ERROR_MSG "Error receiving welcome message from server.\n");
        exit(1);
    }

    printf("Connected to cyberFTP server!\n");

    login(sockfd);

    char cmd[BUFFER_SIZE];
    char arg[BUFFER_SIZE];

    while (1) {
        printf("cyberFTP> ");
        fflush(stdout);

        scanf("%s", cmd);

        if (strcasecmp(cmd, "get") == 0) {
            scanf("%s", arg);
            send(sockfd, cmd, strlen(cmd) + 1, 0);
            send(sockfd, arg, strlen(arg) + 1, 0);

            int res;
            recv(sockfd, &res, sizeof(res), 0);
            if (res != 0) {
                printf(ERROR_MSG "Error receiving file from server.\n");
            }
            else {
                receive_file(sockfd, arg);
                printf("File %s received successfully.\n", arg);
            }
        }
        else if (strcasecmp(cmd, "put") == 0) {
            scanf("%s", arg);
            send(sockfd, cmd, strlen(cmd) + 1, 0);
            send(sockfd, arg, strlen(arg) + 1, 0);

            int res;
            recv(sockfd, &res, sizeof(res), 0);
            if (res != 0) {
                printf(ERROR_MSG "Error sending file to server.\n");
            }
            else {
                send_file(sockfd, arg);
                printf("File %s sent successfully.\n", arg);
            }
        }
        else if (strcasecmp(cmd, "quit") == 0) {
            send(sockfd, cmd, strlen(cmd) + 1, 0);
            break;
        }
        else {
            printf(ERROR_MSG "Invalid command.\n");
        }
    }

    close(sockfd);

    return 0;
}