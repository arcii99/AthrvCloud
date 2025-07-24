//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: retro
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    const char *server_address = "127.0.0.1";
    const int server_port = 110;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Socket creation failed.\n");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(server_port);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Connection failed.\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // Receive the welcome message
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the USER command
    char user_command[] = "USER username\r\n";
    send(sock, user_command, strlen(user_command), 0);

    // Receive the response to the USER command
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the PASS command
    char pass_command[] = "PASS password\r\n";
    send(sock, pass_command, strlen(pass_command), 0);

    // Receive the response to the PASS command
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the LIST command
    char list_command[] = "LIST\r\n";
    send(sock, list_command, strlen(list_command), 0);

    // Receive the response to the LIST command
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the QUIT command
    char quit_command[] = "QUIT\r\n";
    send(sock, quit_command, strlen(quit_command), 0);

    close(sock);
    return 0;
}