//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

void die(char *s)
{
    perror(s);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char user[MAX_BUFFER], pass[MAX_BUFFER];
    char buffer[MAX_BUFFER];
    char command[MAX_BUFFER];
    int msg_count = 0;
    int i = 0;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("Could not create socket");
    }

    // Prepare the server sockaddr_in structure
    server.sin_addr.s_addr = inet_addr("POP3_SERVER_ADDRESS");
    server.sin_family = AF_INET;
    server.sin_port = htons(110);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        die("Connection failed.");
    }

    // Receive greeting message from server
    if (recv(sock, buffer, MAX_BUFFER, 0) < 0) {
        die("Recv failed");
    }
    printf("%s", buffer);

    // Send username and password
    printf("Enter your username: ");
    fgets(user, MAX_BUFFER, stdin);
    printf("Enter your password: ");
    fgets(pass, MAX_BUFFER, stdin);
    sprintf(buffer, "USER %s", user);
    send(sock, buffer, strlen(buffer), 0);
    if (recv(sock, buffer, MAX_BUFFER, 0) < 0) {
        die("Recv failed");
    }
    sprintf(buffer, "PASS %s", pass);
    send(sock, buffer, strlen(buffer), 0);
    if (recv(sock, buffer, MAX_BUFFER, 0) < 0) {
        die("Recv failed");
    }

    // Show message count
    sprintf(buffer, "STAT");
    send(sock, buffer, strlen(buffer), 0);
    if (recv(sock, buffer, MAX_BUFFER, 0) < 0) {
        die("Recv failed");
    }
    printf("%s", buffer);
    sscanf(buffer, "+OK %d %*s", &msg_count);

    // Show message list
    sprintf(buffer, "LIST");
    send(sock, buffer, strlen(buffer), 0);
    if (recv(sock, buffer, MAX_BUFFER, 0) < 0) {
        die("Recv failed");
    }
    printf("%s", buffer);

    // Read first unread message
    if (msg_count > 0) {
        sprintf(command, "RETR %d", msg_count);
        sprintf(buffer, command);
        send(sock, buffer, strlen(buffer), 0);
        memset(buffer, 0, MAX_BUFFER);
        while (recv(sock, buffer, MAX_BUFFER, 0)) {
            printf("%s", buffer);
            memset(buffer, 0, MAX_BUFFER);
        }
        printf("\n\nDelete message? (y/n): ");
        fgets(buffer, MAX_BUFFER, stdin);
        if (buffer[0] == 'y' || buffer[0] == 'Y') {
            sprintf(command, "DELE %d", msg_count);
            sprintf(buffer, command);
            send(sock, buffer, strlen(buffer), 0);

            if (recv(sock, buffer, MAX_BUFFER, 0) < 0) {
                die("Recv failed");
            }
            printf("%s", buffer);
        }
    }

    // Quit
    sprintf(buffer, "QUIT");
    send(sock, buffer, strlen(buffer), 0);

    close(sock);
    return 0;
}