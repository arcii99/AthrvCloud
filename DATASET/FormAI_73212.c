//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: dynamic
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("YOUR_SERVER_IP_HERE");
    server.sin_port = htons(110);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    char username[BUFFER_SIZE];
    printf("Enter your email address: ");
    fgets(username, BUFFER_SIZE, stdin);
    strtok(username, "\n");

    char password[BUFFER_SIZE];
    printf("Enter your password: ");
    fgets(password, BUFFER_SIZE, stdin);
    strtok(password, "\n");

    char response[BUFFER_SIZE];
    read(sock, response, BUFFER_SIZE);
    printf("%s", response);

    char command[BUFFER_SIZE];
    sprintf(command, "USER %s\r\n", username);
    write(sock, command, strlen(command));
    read(sock, response, BUFFER_SIZE);
    printf("%s", response);

    sprintf(command, "PASS %s\r\n", password);
    write(sock, command, strlen(command));
    read(sock, response, BUFFER_SIZE);
    printf("%s", response);

    sprintf(command, "LIST\r\n");
    write(sock, command, strlen(command));
    read(sock, response, BUFFER_SIZE);
    printf("%s", response);

    close(sock);
    return 0;
}