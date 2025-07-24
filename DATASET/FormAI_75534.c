//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 110

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s server_address username\n", argv[0]);
        return 0;
    }

    // Initialize socket
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        printf("Invalid address or Address not supported\n");
        return 1;
    }

    // Connect to server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Connection failed\n");
        return 1;
    }

    // Get banner from server
    bzero(buffer, BUFFER_SIZE);
    read(client_socket, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Login
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", argv[2]);
    write(client_socket, command, strlen(command));
    bzero(buffer, BUFFER_SIZE);
    read(client_socket, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    snprintf(command, sizeof(command), "PASS %s\r\n", getpass("Enter password:"));
    write(client_socket, command, strlen(command));
    bzero(buffer, BUFFER_SIZE);
    read(client_socket, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // List available mails
    write(client_socket, "LIST\r\n", strlen("LIST\r\n"));
    bzero(buffer, BUFFER_SIZE);
    read(client_socket, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Get a specific mail
    int mail_number;
    printf("Enter mail number to retrieve: ");
    scanf("%d", &mail_number);

    snprintf(command, sizeof(command), "RETR %d\r\n", mail_number);
    write(client_socket, command, strlen(command));

    snprintf(buffer, sizeof(buffer), "mail%d.txt", mail_number);
    FILE *fp = fopen(buffer, "w");
    if (!fp) {
        printf("Unable to save mail\n");
        return 1;
    }

    // Read contents of mail
    int n;
    while ((n = read(client_socket, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, sizeof(char), n, fp);
    }
    fclose(fp);

    // Quit
    write(client_socket, "QUIT\r\n", strlen("QUIT\r\n"));
    bzero(buffer, BUFFER_SIZE);
    read(client_socket, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    close(client_socket);
    printf("Disconnected from server\n");
    return 0;
}