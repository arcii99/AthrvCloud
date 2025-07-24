//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_BUF_SIZE 1024
#define MAX_CMD_SIZE 128
#define PORT 21

void *recv_resp(void *arg);
void *command_thread(void *arg);

int main(int argc, char *argv[]) {
    int sock_fd;
    struct sockaddr_in server_addr;
    char server_ip[MAX_BUF_SIZE], username[MAX_BUF_SIZE], password[MAX_BUF_SIZE];
    pthread_t tid;

    // Prompt for server IP, username and password
    printf("Enter server IP: ");
    scanf("%s", server_ip);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    
    // Create socket file descriptor
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address info
    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // Receive initial welcome message
    pthread_create(&tid, NULL, &recv_resp, (void *)&sock_fd);
    pthread_join(tid, NULL);

    // Login
    char login_cmd[MAX_CMD_SIZE];
    sprintf(login_cmd, "USER %s\r\n", username);
    send(sock_fd, login_cmd, strlen(login_cmd), 0);
    pthread_create(&tid, NULL, &recv_resp, (void *)&sock_fd);
    pthread_join(tid, NULL);
    sprintf(login_cmd, "PASS %s\r\n", password);
    send(sock_fd, login_cmd, strlen(login_cmd), 0);
    pthread_create(&tid, NULL, &recv_resp, (void *)&sock_fd);
    pthread_join(tid, NULL);

    // Set to binary mode
    char binary_cmd[] = "TYPE I\r\n";
    send(sock_fd, binary_cmd, strlen(binary_cmd), 0);
    pthread_create(&tid, NULL, &recv_resp, (void *)&sock_fd);
    pthread_join(tid, NULL);

    // Enter command loop
    pthread_create(&tid, NULL, &command_thread, (void *)&sock_fd);
    pthread_join(tid, NULL);

    return 0;
}

void *recv_resp(void *arg) {
    int sock_fd = *(int *)arg;
    char buf[MAX_BUF_SIZE];
    memset(buf, 0, MAX_BUF_SIZE);
    recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    printf("%s\n", buf);
    pthread_exit(NULL);
}

void *command_thread(void *arg) {
    int sock_fd = *(int *)arg;
    char cmd[MAX_CMD_SIZE], arg_buf[MAX_BUF_SIZE], buf[MAX_BUF_SIZE];
    char *token;

    // Loop for user input
    while (1) {
        printf("\nFTP> ");
        fgets(buf, MAX_BUF_SIZE, stdin);

        memset(cmd, 0, MAX_CMD_SIZE);
        memset(arg_buf, 0, MAX_BUF_SIZE);
        sscanf(buf, "%s %s", cmd, arg_buf);

        if (strlen(cmd) == 0) {
            continue;
        }

        // Send command to server
        char ftp_cmd[MAX_CMD_SIZE];
        sprintf(ftp_cmd, "%s %s\r\n", cmd, arg_buf);
        send(sock_fd, ftp_cmd, strlen(ftp_cmd), 0);

        // Handle response
        if (strcmp(cmd, "QUIT") == 0) {
            pthread_exit(NULL);
        } else if (strcmp(cmd, "RETR") == 0) {
            // Retrieve file
        } else if (strcmp(cmd, "STOR") == 0) {
            // Store file
        }
        // Wait for response
        pthread_t tid;
        pthread_create(&tid, NULL, &recv_resp, (void *)&sock_fd);
        pthread_join(tid, NULL);
    }
    pthread_exit(NULL);
}