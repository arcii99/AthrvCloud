//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define FTP_PORT 21
#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUFFER_SIZE];

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(FTP_PORT);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("Error opening socket");

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) 
        error("Error connecting to server");

    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) 
        error("Error reading from server");

    printf("Server: %s", buffer);

    // Login to the server
    char user[100], pass[100];
    printf("Username: ");
    scanf("%s", user);
    sprintf(buffer, "USER %s\r\n", user);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
        error("Error writing to server");

    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0)
        error("Error reading from server");

    printf("Server: %s", buffer);

    printf("Password: ");
    scanf("%s", pass);
    sprintf(buffer, "PASS %s\r\n", pass);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
        error("Error writing to server");

    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0)
        error("Error reading from server");

    printf("Server: %s", buffer);

    // Retrieve file from server
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);
    sprintf(buffer, "RETR %s\r\n", filename);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
        error("Error writing to server");

    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0)
        error("Error reading from server");

    if (strstr(buffer, "550") != NULL) {
        printf("Error: File not found.\n");
        exit(EXIT_FAILURE);
    }

    // Save file to local directory
    FILE* fp;
    fp = fopen(filename, "w");
    if (fp == NULL) 
        error("Error creating file");

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE - 1);
        if (n < 0) 
            error("Error reading from server");

        if (strstr(buffer, "226") != NULL || strstr(buffer, "250") != NULL)
            break;

        fprintf(fp, buffer, strlen(buffer));
    }

    fclose(fp);
    printf("File saved successfully!\n");

    close(sockfd);
    return 0;
}