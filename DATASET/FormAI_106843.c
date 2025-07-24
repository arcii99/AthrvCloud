//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/stat.h>

#define MAX_MSG_SIZE 1024
#define MAX_FILENAME_SIZE 256
#define SERVER_PORT 21

int main(int argc, char *argv[]) {

    struct sockaddr_in server_address;
    char message[MAX_MSG_SIZE], response[MAX_MSG_SIZE];
    int socket_fd, conn_fd, len, code;
    char username[20], password[20];

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("\n[-] Error in creating socket...");
        exit(1);
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(SERVER_PORT);

    // Connect to server
    conn_fd = connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));
    if (conn_fd == -1) {
        perror("\n[-] Error in connecting...");
        exit(1);
    }

    // Receive server response
    len = recv(socket_fd, response, MAX_MSG_SIZE, 0);
    response[len] = '\0';
    printf("\n%s", response);

    // Enter username
    printf("\nEnter username: ");
    scanf("%s", username);

    // Send username to server
    sprintf(message, "USER %s\r\n", username);
    send(socket_fd, message, strlen(message), 0);
    len = recv(socket_fd, response, MAX_MSG_SIZE, 0);
    response[len] = '\0';
    sscanf(response, "%d", &code);
    printf("%s", response);

    // Check if username is accepted
    if (code == 331) {
        // Enter password
        printf("\nEnter password: ");
        scanf("%s", password);

        // Send password to server
        sprintf(message, "PASS %s\r\n", password);
        send(socket_fd, message, strlen(message), 0);
        len = recv(socket_fd, response, MAX_MSG_SIZE, 0);
        response[len] = '\0';
        sscanf(response, "%d", &code);
        printf("%s", response);

        // Check if login is successful
        if (code == 230) {
            printf("\nLogin successful!\n");

            // Enter file name
            char filename[MAX_FILENAME_SIZE];
            printf("\nEnter file name: ");
            scanf("%s", filename);

            // Send RETR command to server
            sprintf(message, "RETR %s\r\n", filename);
            send(socket_fd, message, strlen(message), 0);
            len = recv(socket_fd, response, MAX_MSG_SIZE, 0);
            response[len] = '\0';
            sscanf(response, "%d", &code);
            printf("%s", response);

            // Check if file exists
            if (code == 550) {
                printf("\nFile not found!\n");
                exit(1);
            }

            // Open file for writing
            FILE *file = fopen(filename, "wb");
            if (file == NULL) {
                perror("\n[-] Error in opening file...");
                exit(1);
            }

            // Receive file data from server
            while ((len = recv(socket_fd, response, MAX_MSG_SIZE, 0)) > 0) {
                response[len] = '\0';
                fwrite(response, sizeof(char), len, file);
            }
            fclose(file);
            printf("\nFile received successfully!\n");
        }
        else {
            printf("\nLogin failed!");
        }
    }

    // Quit connection
    sprintf(message, "QUIT\r\n");
    send(socket_fd, message, strlen(message), 0);
    len = recv(socket_fd, response, MAX_MSG_SIZE, 0);
    response[len] = '\0';
    sscanf(response, "%d", &code);
    printf("%s", response);
    close(socket_fd);

    return 0;
}