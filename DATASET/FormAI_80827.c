//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
/*
 * C Program to build an FTP client using raw sockets
 * as inspired by Claude Shannon.
 */

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

int main(int argc, char *argv[]) {
    // create a socket for connecting to the FTP server
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(21);

    // connect to the FTP server
    if (connect(socket_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection error");
        return 1;
    }

    // send a greeting message to the server
    char greeting[100];
    read(socket_fd, greeting, sizeof(greeting));
    printf("%s", greeting);

    // authenticate the user on the FTP server
    char user_command[MAX_COMMAND_LENGTH];
    char password_command[MAX_COMMAND_LENGTH];
    char buffer[100];

    printf("Username: ");
    scanf("%s", user_command);
    write(socket_fd, user_command, strlen(user_command));
    read(socket_fd, buffer, sizeof(buffer));
    printf("%s", buffer);

    printf("Password: ");
    scanf("%s", password_command);
    write(socket_fd, password_command, strlen(password_command));
    read(socket_fd, buffer, sizeof(buffer));
    printf("%s", buffer);

    // now that we're authenticated, let's issue some commands!
    while (1) {
        char command[MAX_COMMAND_LENGTH];
        printf("Command: ");
        scanf("%s", command);

        if (strcmp(command, "QUIT") == 0) {
            // disconnect from the FTP server
            write(socket_fd, "QUIT\r\n", strlen("QUIT\r\n"));
            read(socket_fd, buffer, sizeof(buffer));
            printf("%s", buffer);
            break;
        } else {
            // send the command to the server and print the response
            write(socket_fd, command, strlen(command));
            write(socket_fd, "\r\n", strlen("\r\n"));
            read(socket_fd, buffer, sizeof(buffer));
            printf("%s", buffer);
        }
    }

    // close the socket and exit
    close(socket_fd);
    return 0;
}