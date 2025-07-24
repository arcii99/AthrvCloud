//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFF_SIZE 1024
#define FTP_PORT 21

char username[BUFF_SIZE];
char password[BUFF_SIZE];
char filename[BUFF_SIZE];

void error_handling(char *msg) {
    fprintf(stderr, "[ERROR] %s\n", msg);
    exit(1);
}

void login(int sockfd) {
    char buffer[BUFF_SIZE];

    printf("Username: ");
    scanf("%s", username);
    sprintf(buffer, "USER %s\r\n", username);
    write(sockfd, buffer, strlen(buffer));
    memset(buffer, 0, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    if (strncmp(buffer, "331", 3) != 0) {
        error_handling("Incorrect username.");
    }

    printf("Password: ");
    scanf("%s", password);
    sprintf(buffer, "PASS %s\r\n", password);
    write(sockfd, buffer, strlen(buffer));
    memset(buffer, 0, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    if (strncmp(buffer, "230", 3) != 0) {
        error_handling("Incorrect password.");
    }

    printf("Login successful.\n");
}

void upload(int sockfd) {
    char buffer[BUFF_SIZE];
    FILE *fp;
    int len, total_len = 0;
    ssize_t read_len;

    printf("File name: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (!fp) {
        error_handling("Cannot open file.");
    }

    sprintf(buffer, "STOR %s\r\n", filename);
    write(sockfd, buffer, strlen(buffer));
    memset(buffer, 0, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    if (strncmp(buffer, "150", 3) != 0) {
        error_handling("Cannot upload file.");
    }

    while (1) {
        read_len = fread(buffer, 1, BUFF_SIZE, fp);
        if (read_len < 0) {
            error_handling("Cannot read file.");
        } else if (read_len == 0) {
            break;
        }
        len = write(sockfd, buffer, read_len);
        total_len += len;
        if (len < 0) {
            error_handling("Cannot write to socket.");
        }
    }

    fclose(fp);
    printf("Upload successful, %d bytes sent.\n", total_len);
}

int main(int argc, char *argv[]) {
    int sockfd;
    char buffer[BUFF_SIZE];

    if (argc != 2) {
        error_handling("Usage: ftpclient <ip address>");
    }

    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("Cannot create socket.");
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(FTP_PORT);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("Cannot connect to server.");
    }

    read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    login(sockfd);
    upload(sockfd);

    close(sockfd);
    return 0;
}