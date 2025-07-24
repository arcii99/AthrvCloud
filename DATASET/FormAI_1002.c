//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 21
#define MAX_COMMAND_SIZE 1024
#define MAX_RESPONSE_SIZE 4096
#define MAX_BUFFER_SIZE 64

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char command[MAX_COMMAND_SIZE];
    char response[MAX_RESPONSE_SIZE];
    char buffer[MAX_BUFFER_SIZE];
    char filename[MAX_BUFFER_SIZE];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    server_addr.sin_port = htons(SERVER_PORT);

    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("FTP Client Connected...\n");
    printf("Enter 'quit' to close the connection.\n");

    while(1) {
        printf("ftp> ");
        fgets(command, MAX_COMMAND_SIZE, stdin);
        command[strcspn(command, "\r\n")] = 0;

        if(strlen(command) == 0)
            continue;
        else if(strcmp(command, "quit") == 0)
            break;
        else if(strncmp(command, "get ", 4) == 0) {
            int n;
            FILE *file;
            char *p = strchr(command, ' ') + 1;
            strcpy(filename, p);

            write(sockfd, command, strlen(command));
            read(sockfd, response, MAX_RESPONSE_SIZE);

            if(strncmp(response, "550", 3) == 0)
                printf("File %s not found\n", filename);
            else {
                printf("Downloading %s ", filename);
                fflush(stdout);

                file = fopen(filename, "wb");
                while(n = read(sockfd, buffer, MAX_BUFFER_SIZE)) {
                    fwrite(buffer, n, 1, file);
                }
                fclose(file);

                printf("Done!\n");
            }
        }
        else {
            write(sockfd, command, strlen(command));
            read(sockfd, response, MAX_RESPONSE_SIZE);
            printf("%s", response);
        }
    }

    close(sockfd);
    printf("Connection Closed\n");

    return 0;
}