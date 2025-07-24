//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

/* Function to handle FTP client operations */
void ftpClient(int sockfd)
{
    char buffer[BUF_SIZE];
    char command[BUF_SIZE];
    char filename[BUF_SIZE];
    char filepath[BUF_SIZE];
    int bytesCount;

    /* Loop until user quits */
    while (1) {
        printf("Enter a command (get/put/quit): ");
        fflush(stdout);
        fgets(command, sizeof(command), stdin);

        /* Removing newline character from input */
        if ((strlen(command) > 0) && (command[strlen(command) - 1] == '\n')) {
            command[strlen(command) - 1] = '\0';
        }

        /* Handle GET command */
        if (strcmp(command, "get") == 0) {
            printf("Enter filename to download: ");
            fflush(stdout);
            fgets(filename, sizeof(filename), stdin);

            /* Removing newline character from input */
            if ((strlen(filename) > 0) && (filename[strlen(filename) - 1] == '\n')) {
                filename[strlen(filename) - 1] = '\0';
            }

            /* Sending GET command to server */
            sprintf(buffer, "GET %s", filename);
            send(sockfd, buffer, strlen(buffer), 0);
            bytesCount = recv(sockfd, buffer, BUF_SIZE, 0);

            /* Checking if file exists on server */
            if (bytesCount == 0) {
                printf("File %s not found on server.\n", filename);
            } else {
                /* Saving file to client system */
                FILE *filePtr = fopen(filename, "wb");
                fwrite(buffer, bytesCount, 1, filePtr);

                /* Receiving file contents from server */
                while ((bytesCount = recv(sockfd, buffer, BUF_SIZE, 0)) > 0) {
                    fwrite(buffer, bytesCount, 1, filePtr);
                }
                fclose(filePtr);
                printf("File %s downloaded successfully.\n", filename);
            }
        }

        /* Handle PUT command */
        else if (strcmp(command, "put") == 0) {
            printf("Enter filename to upload: ");
            fflush(stdout);
            fgets(filename, sizeof(filename), stdin);

            /* Removing newline character from input */
            if ((strlen(filename) > 0) && (filename[strlen(filename) - 1] == '\n')) {
                filename[strlen(filename) - 1] = '\0';
            }

            /* Checking if file exists on client system */
            FILE *filePtr = fopen(filename, "rb");
            if (filePtr == NULL) {
                printf("File %s not found on client system.\n", filename);
                continue;
            }

            /* Sending PUT command to server */
            sprintf(buffer, "PUT %s", filename);
            send(sockfd, buffer, strlen(buffer), 0);

            /* Sending file contents to server */
            while ((bytesCount = fread(buffer, 1, BUF_SIZE, filePtr)) > 0) {
                send(sockfd, buffer, bytesCount, 0);
            }

            fclose(filePtr);
            printf("File %s uploaded successfully.\n", filename);
        }

        /* Handle QUIT command */
        else if (strcmp(command, "quit") == 0) {
            send(sockfd, command, strlen(command), 0);
            break;
        }
    }
    return;
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;

    /* Creating socket file descriptor */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Socket creation failed.\n");
        exit(0);
    } else {
        printf("Socket created successfully.\n");
    }

    /* Setting server details */
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(21);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    /* Connecting to server */
    if (connect(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Connection to server failed.\n");
        exit(0);
    } else {
        printf("Connected to server successfully.\n");
    }

    /* Handling client operations */
    ftpClient(sockfd);

    /* Closing socket connection */
    close(sockfd);

    return 0;
}