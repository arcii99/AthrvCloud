//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define FTP_PORT 21

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set server address details
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(FTP_PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Read welcome message from server
    read(sockfd, buffer, 1024);
    printf("%s\n", buffer);

    // Login to server
    char username[] = "user anonymous\r\n";
    char password[] = "pass empty_password\r\n";
    write(sockfd, username, strlen(username));
    read(sockfd, buffer, 1024);
    printf("%s\n", buffer);
    write(sockfd, password, strlen(password));
    read(sockfd, buffer, 1024);
    printf("%s\n", buffer);

    // Navigate to directory
    char cwd[] = "cwd /home/user/uploads/\r\n";
    write(sockfd, cwd, strlen(cwd));
    read(sockfd, buffer, 1024);
    printf("%s\n", buffer);

    // List files in directory
    char list[] = "list\r\n";
    write(sockfd, list, strlen(list));
    read(sockfd, buffer, 1024);
    printf("%s\n", buffer);

    // Download a file
    char pasv[] = "pasv\r\n";
    write(sockfd, pasv, strlen(pasv));
    read(sockfd, buffer, 1024);
    printf("%s\n", buffer);

    // Extract IP address and port from PASV response
    char* tok = strtok(buffer, "(,");
    int port = atoi(tok);
    int i = 0;
    while (tok != NULL) {
        tok = strtok(NULL, "(,");
        i++;
        if (i == 5) {
            int a = atoi(tok);
            tok = strtok(NULL, "(,");
            int b = atoi(tok);
            tok = strtok(NULL, "(,");
            int c = atoi(tok);
            tok = strtok(NULL, "(,");
            int d = atoi(tok);
            char ip_addr[16];
            snprintf(ip_addr, 16, "%d.%d.%d.%d", a, b, c, d);

            // Connect to data port
            struct sockaddr_in data_addr;
            int data_sockfd;
            memset(&data_addr, 0, sizeof(data_addr));
            data_addr.sin_family = AF_INET;
            data_addr.sin_addr.s_addr = inet_addr(ip_addr);
            data_addr.sin_port = htons(port);

            if ((data_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                perror("Socket creation error");
                exit(EXIT_FAILURE);
            }

            if (connect(data_sockfd, (struct sockaddr*)&data_addr, sizeof(data_addr)) < 0) {
                perror("Connection failed");
                exit(EXIT_FAILURE);
            }

            char file[] = "retr file.txt\r\n";
            write(sockfd, file, strlen(file));
            read(sockfd, buffer, 1024);
            printf("%s\n", buffer);

            // Download file to local disk
            FILE *fp = fopen("file.txt", "wb");
            if (fp == NULL) {
                perror("Error creating file");
                exit(EXIT_FAILURE);
            }

            while (read(data_sockfd, buffer, 1024) > 0) {
                fwrite(buffer, 1, strlen(buffer), fp);
            }

            fclose(fp);
            close(data_sockfd);
            break;
        }
    }

    close(sockfd);
    return 0;
}