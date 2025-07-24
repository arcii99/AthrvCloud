//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: complete
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDR "imap.gmail.com"
#define SERVER_PORT 993

const char USER[] = "example@gmail.com";
const char PASSWORD[] = "password";

int main(int argc, char *argv[]) {

    struct sockaddr_in server;
    char buffer[1024];
    int socket_desc, bytes_received;
    int message_count = 0;

    // Initialize socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket.\n");
        return 1;
    }

    // Initialize server address
    server.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);

    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection error.\n");
        return 1;
    }

    // Receive server greeting
    bytes_received = recv(socket_desc, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        printf("Error receiving greeting.\n");
        return 1;
    }
    printf("%s\n", buffer);

    // Send login credentials
    sprintf(buffer, "a001 LOGIN %s %s\r\n", USER, PASSWORD);
    if (send(socket_desc, buffer, strlen(buffer), 0) < 0) {
        printf("Error sending login credentials.\n");
        return 1;
    }

    // Receive login response
    bytes_received = recv(socket_desc, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        printf("Error receiving login response.\n");
        return 1;
    }
    printf("%s\n", buffer);

    // Send command to select inbox
    sprintf(buffer, "a002 SELECT INBOX\r\n");
    if (send(socket_desc, buffer, strlen(buffer), 0) < 0) {
        printf("Error sending SELECT command.\n");
        return 1;
    }

    // Receive response to select command
    bytes_received = recv(socket_desc, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        printf("Error receiving SELECT response.\n");
        return 1;
    }
    printf("%s\n", buffer);

    // Send command to fetch message count
    sprintf(buffer, "a003 STATUS INBOX (MESSAGES)\r\n");
    if (send(socket_desc, buffer, strlen(buffer), 0) < 0) {
        printf("Error sending STATUS command.\n");
        return 1;
    }

    // Receive response to status command
    bytes_received = recv(socket_desc, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        printf("Error receiving STATUS response.\n");
        return 1;
    }
    printf("%s\n", buffer);

    // Parse message count from status response
    char *status_pos = strstr(buffer, "MESSAGES ");
    if (!status_pos) {
        printf("Error parsing message count.\n");
        return 1;
    }
    message_count = atoi(status_pos + strlen("MESSAGES "));

    // Send command to fetch message headers
    sprintf(buffer, "a004 FETCH 1:%d (BODY[HEADER.FIELDS (FROM SUBJECT DATE)])\r\n", message_count);
    if (send(socket_desc, buffer, strlen(buffer), 0) < 0) {
        printf("Error sending FETCH command.\n");
        return 1;
    }

    // Receive response to fetch command
    bytes_received = recv(socket_desc, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        printf("Error receiving FETCH response.\n");
        return 1;
    }
    printf("%s\n", buffer);

    // Close connection
    close(socket_desc);

    return 0;
}