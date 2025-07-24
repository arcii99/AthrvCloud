//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void sendCommand(int socket, char command[BUFFER_SIZE]) {
    char response[BUFFER_SIZE];
    int responseCode;
    bzero(response, BUFFER_SIZE);
    send(socket, command, strlen(command), 0);
    recv(socket, response, BUFFER_SIZE, 0);
    sscanf(response, "%d", &responseCode);
    printf("%s", response + 4);
}

void getFile(int socket, char command[BUFFER_SIZE]) {
    int received, fd, filesize;
    char *filename = strtok(command, " ");
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    recv(socket, buffer, BUFFER_SIZE, 0);
    sscanf(buffer, "%d", &filesize);

    if (filesize == -1) {
        printf("Error: File does not exist on server.\n");
        return;
    }

    fd = open(filename, O_CREAT | O_EXCL | O_WRONLY, 0666);
    received = 0;

    while (received < filesize) {
        int len = recv(socket, buffer, BUFFER_SIZE, 0);
        received += len;
        write(fd, buffer, len);
        printf("Downloaded %d/%d bytes...\n", received, filesize);
    }
    close(fd);
}

void putFile(int socket, char command[BUFFER_SIZE]) {
    char *filename = strtok(command, " ");
    int size;
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        printf("Error: Unable to open file.\n");
        return;
    }

    sendCommand(socket, "TYPE I\r\n");

    char response[BUFFER_SIZE];
    bzero(response, BUFFER_SIZE);
    sprintf(response, "SIZE %s\r\n", filename);
    sendCommand(socket, response);

    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    recv(socket, buffer, BUFFER_SIZE, 0);
    sscanf(buffer, "%d", &size);
    printf("%s", buffer + 4);

    sprintf(response, "STOR %s\r\n", filename);
    sendCommand(socket, response);

    int sent = 0;
    while (sent < size) {
        int len = read(fd, buffer, BUFFER_SIZE);
        send(socket, buffer, len, 0);
        sent += len;
        printf("Uploaded %d/%d bytes...\n", sent, size);
    }
    close(fd);
}

int main(int argc, char *argv[]) {
    int controlSocket, serverResponse, dataSocket, port;
    struct sockaddr_in serverAddress;
    char username[BUFFER_SIZE], password[BUFFER_SIZE], command[BUFFER_SIZE], parameter[BUFFER_SIZE], buffer[BUFFER_SIZE];
    char *hostname;

    if (argc != 2) {
        fprintf(stderr, "Usage: ./client hostname\n");
        exit(1);
    }

    hostname = argv[1];
    port = 21;

    controlSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &(serverAddress.sin_addr.s_addr));

    if (connect(controlSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        printf("\n Error : Connect Failed \n");
        return 1;
    }

    while (1) {
        printf("Enter username: ");
        fgets(username, BUFFER_SIZE, stdin);

        printf("Enter password: ");
        fgets(password, BUFFER_SIZE, stdin);

        sendCommand(controlSocket, "USER anonymous\r\n");

        if (strstr(password, "\n") != NULL) {
            password[strlen(password) - 1] = '\0';
        }

        sprintf(command, "PASS %s\r\n", password);
        sendCommand(controlSocket, command);

        serverResponse = recv(controlSocket, buffer, BUFFER_SIZE, 0);
        if (serverResponse == 0) {
            printf("Disconnected from server.");
            break;
        }

        printf("Welcome to the FTP client.\n");
        printf("> ");

        while (1) {
            bzero(command, BUFFER_SIZE);
            bzero(parameter, BUFFER_SIZE);

            fgets(command, BUFFER_SIZE, stdin);
            sscanf(command, "%s %[^\n]", command, parameter);

            if (strcasecmp(command, "QUIT") == 0 || strcasecmp(command, "EXIT") == 0) {
                sendCommand(controlSocket, "QUIT\r\n");
                break;
            }

            if (strcasecmp(command, "LIST") == 0) {
                sendCommand(controlSocket, "PASV\r\n");

                serverResponse = recv(controlSocket, buffer, BUFFER_SIZE, 0);
                if (serverResponse == 0) {
                    printf("Disconnected from server.");
                    break;
                }

                int h1, h2, h3, h4, p1, p2;
                sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &h1, &h2, &h3, &h4, &p1, &p2);

                dataSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                serverAddress.sin_addr.s_addr = htonl((h1 << 24) | (h2 << 16) | (h3 << 8) | h4);
                serverAddress.sin_port = htons((p1 << 8) | p2);

                if (connect(dataSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
                    sendCommand(controlSocket, "ABOR\r\n");
                    printf("Could not establish data connection with server.\n");
                    break;
                }

                sendCommand(controlSocket, "LIST\r\n");

                serverResponse = recv(controlSocket, buffer, BUFFER_SIZE, 0);
                if (serverResponse == 0) {
                    printf("Disconnected from server.");
                    break;
                }

                char *fileList = (char *)malloc(BUFFER_SIZE);
                bzero(fileList, BUFFER_SIZE);

                while ((serverResponse = recv(dataSocket, buffer, BUFFER_SIZE, 0)) > 0) {
                    strcat(fileList, buffer);
                }

                if (serverResponse == 0) {
                    printf("Disconnected from server.");
                    break;
                }

                printf("%s", fileList);
                free(fileList);
                close(dataSocket);

                serverResponse = recv(controlSocket, buffer, BUFFER_SIZE, 0);
                if (serverResponse == 0) {
                    printf("Disconnected from server.");
                    break;
                }

                printf("> ");
                continue;
            }

            if (strcasecmp(command, "GET") == 0) {
                char *filename = strtok(parameter, " ");

                sprintf(command, "SIZE %s\r\n", filename);
                sendCommand(controlSocket, command);

                serverResponse = recv(controlSocket, buffer, BUFFER_SIZE, 0);
                int fileSize = -1;

                sscanf(buffer, "%d", &fileSize);

                if (fileSize == -1) {
                    printf("Error: File does not exist on server.\n");
                    printf("> ");
                    continue;
                }

                sprintf(command, "TYPE I\r\n");
                sendCommand(controlSocket, command);

                sprintf(command, "RETR %s\r\n", filename);
                sendCommand(controlSocket, command);

                serverResponse = recv(controlSocket, buffer, BUFFER_SIZE, 0);

                if (serverResponse == 0) {
                    printf("Disconnected from server.\n");
                    break;
                }

                printf("Downloading file %s...\n", filename);

                getFile(controlSocket, command);

                serverResponse = recv(controlSocket, buffer, BUFFER_SIZE, 0);
                if (serverResponse == 0) {
                    printf("Disconnected from server.");
                    break;
                }

                printf("> ");
                continue;
            }

            if (strcasecmp(command, "PUT") == 0) {
                char *filename = strtok(parameter, " ");

                sprintf(command, "TYPE I\r\n");
                sendCommand(controlSocket, command);

                sprintf(command, "STOR %s\r\n", filename);
                sendCommand(controlSocket, command);

                printf("Uploading file %s...\n", filename);

                putFile(controlSocket, command);

                serverResponse = recv(controlSocket, buffer, BUFFER_SIZE, 0);
                if (serverResponse == 0) {
                    printf("Disconnected from server.");
                    break;
                }

                printf("Upload complete.\n");
                printf("> ");
                continue;
            }

            sendCommand(controlSocket, command);
            serverResponse = recv(controlSocket, buffer, BUFFER_SIZE, 0);

            if (serverResponse == 0) {
                printf("Disconnected from server.");
                break;
            }

            printf("%s", buffer);
            printf("> ");
        }
    }

    return 0;
}