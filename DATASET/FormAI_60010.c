//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <ctype.h>

#define BUF_SIZE 1000
#define END_OF_LINE '\n'
#define END_OF_FILE '\4'

void check(int exp, const char *msg) {
    if (exp == -1) {
        perror(msg);
        exit(1);
    }
}

void clean(char *buff, int n) {
    for (int i = 0; i < n; i++) {
        buff[i] = 0;
    }
}

void printReply(int sockfd) {
    char buffer[BUF_SIZE];
    ssize_t numRead = recv(sockfd, buffer, BUF_SIZE - 1, 0);
    check(numRead, "recv");
    buffer[numRead] = '\0';
    printf("%s", buffer);
}

void sendCommand(int sockfd, char* command) {
    ssize_t numWritten = send(sockfd, command, strlen(command), 0);
    check(numWritten, "send");
}

void handleFileDownload(int sockfd, char *filename) {
    char buffer[BUF_SIZE], command[BUF_SIZE];
    FILE *fp = fopen(filename, "w");

    sprintf(command, "RETR %s\n", filename);
    sendCommand(sockfd, command);
    printReply(sockfd);

    ssize_t numRead = recv(sockfd, buffer, BUF_SIZE, 0);
    check(numRead, "recv");

    while (numRead > 0) {
        fwrite(buffer, sizeof(char), numRead, fp);
        numRead = recv(sockfd, buffer, BUF_SIZE, 0);
        check(numRead, "recv");
    }

    fclose(fp);

    printReply(sockfd);
}

int main(int argc, char* argv[]) {
    int sockfd;
    struct sockaddr_in serverAddr;
    struct hostent *host;
    char buffer[BUF_SIZE], command[BUF_SIZE], response[BUF_SIZE];

    check(argc == 3, "usage: ftpclient server-ip-address or hostname port-number");
    host = gethostbyname(argv[1]);
    check((host != NULL), "failed to resolve hostname");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    check(sockfd != -1, "socket creation");

    bzero((char *)&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = ((struct in_addr *)(host->h_addr))->s_addr;
    serverAddr.sin_port = htons(atoi(argv[2])) ;

    int conn = connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    check(conn != -1, "connection to server");

    printReply(sockfd);

    while (1) {
        printf("Enter command: ");
        fflush(stdout);

        clean(command, BUF_SIZE);
        clean(buffer, BUF_SIZE);

        fgets(command, BUF_SIZE - 1, stdin);
        command[strlen(command) - 1] = END_OF_LINE;

        if (strcmp(command,"QUIT") == 0) {
            sendCommand(sockfd, "QUIT\n");
            printReply(sockfd);
            break;
        }

        if (strcmp(command, "LIST") == 0) {
            sendCommand(sockfd, "PASV\n");
            printReply(sockfd);

            clean(response, BUF_SIZE);
            ssize_t numRead = recv(sockfd, response, BUF_SIZE, 0);
            check(numRead, "recv");
            response[numRead] = '\0';

            char *tok = strtok(response, "(,");
            int PORT = 0;
            int count = 1;
            while (tok != NULL) {
                if (count == 5) {
                    int i1 = atoi(tok);
                    tok = strtok(NULL, ",");
                    int i2 = atoi(tok);
                    PORT = i1 * 256 + i2;
                    break;
                } else {
                    tok = strtok(NULL, "(,");
                    count++;
                }
            }

            char dataBuffer[BUF_SIZE];
            struct sockaddr_in dataSockAddr;
            size_t dataSize = sizeof(dataSockAddr);

            int dataSockfd = socket(AF_INET, SOCK_STREAM, 0);
            check(dataSockfd != -1, "socket creation");

            bzero((char *)&dataSockAddr, sizeof(dataSockAddr));
            dataSockAddr.sin_family = AF_INET;
            dataSockAddr.sin_port = htons(PORT);

            int conn = connect(dataSockfd, (struct sockaddr *)&dataSockAddr, dataSize);
            check(conn != -1, "data connection to server");

            sendCommand(sockfd, "NLST\n");
            printReply(sockfd);

            numRead = recv(dataSockfd, dataBuffer, BUF_SIZE, 0);
            dataBuffer[numRead] = '\0';
            printf("%s", dataBuffer);

            close(dataSockfd);
            printReply(sockfd);
        } else if (strncmp(command, "RETR ", 5) == 0) {
            char *filename = strtok(command + 5, "\r\n");
            handleFileDownload(sockfd, filename);
        } else {
            sendCommand(sockfd, command);
            printReply(sockfd);
        }
    }

    close(sockfd);
    return 0;
}