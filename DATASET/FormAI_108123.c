//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char filename[BUFFER_SIZE];
    bool is_connected = false;

    // check if user has provided server address
    if (argc < 2) {
        printf("Please provide server IP address\n");
        exit(EXIT_FAILURE);
    }

    // create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket.");
        exit(EXIT_FAILURE);
    }

    // set server address family, IP address, and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(21);

    // connect to server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server.");
        exit(EXIT_FAILURE);
    }

    printf("====Welcome to FTP client====\n\n");
    is_connected = true;

    while (is_connected) {
        printf("Enter FTP command: ");
        fgets(command, BUFFER_SIZE, stdin);

        // check for exit command
        if (strcmp(command, "exit\n") == 0) {
            is_connected = false;
            printf("Disconnecting from server...\n");
            continue;
        }

        // send command to server
        send(sock_fd, command, strlen(command), 0);

        // receive data from server
        memset(buffer, 0, BUFFER_SIZE);
        recv(sock_fd, buffer, BUFFER_SIZE, 0);
        printf("%s", buffer);

        // check for get command
        if (strncmp(command, "get", 3) == 0) {
            // extract filename from command
            strncpy(filename, command + 4, strlen(command) - 5);

            // open file for writing
            FILE *fp = fopen(filename, "wb");
            if (fp == NULL) {
                printf("Error opening file %s\n", filename);
                continue;
            }

            // receive file data from server
            int bytes_received = 0;
            while ((bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0)) > 0) {
                fwrite(buffer, sizeof(char), bytes_received, fp);
            }
            fclose(fp);
            printf("File %s downloaded successfully\n", filename);
        }
    }

    // close socket
    close(sock_fd);
    printf("Socket closed\n");

    return 0;
}