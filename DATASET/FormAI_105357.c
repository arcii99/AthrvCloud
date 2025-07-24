//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    char username[50], password[50], command[100], filename[100];
    int sock, port, data_sock, file_size, bytes_read;
    struct sockaddr_in server_address, data_address;
    FILE *file;

    // User input for ftp server details
    printf("Enter FTP Server IP Address: ");
    scanf("%s", server_address.sin_addr.s_addr);
    printf("Enter FTP Server Port: ");
    scanf("%d", &port);
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    // Socket creation and connection
    sock = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));

    // Login to FTP server
    sprintf(command, "USER %s\n", username);
    send(sock, command, sizeof(command), 0);
    sleep(1);
    sprintf(command, "PASS %s\n", password);
    send(sock, command, sizeof(command), 0);
    sleep(1);

    // Request a file from the server
    printf("Enter filename to download: ");
    scanf("%s", filename);
    sprintf(command, "SIZE %s\n", filename);
    send(sock, command, sizeof(command), 0);
    sleep(1);

    // Get file size
    char server_response[200];
    recv(sock, server_response, sizeof(server_response), 0);
    sscanf(server_response, "%*d %d", &file_size);

    // Set up data connection for file transfer
    data_address.sin_family = AF_INET;
    data_address.sin_addr.s_addr = server_address.sin_addr.s_addr;
    data_address.sin_port = htons(port + 1);
    data_sock = socket(AF_INET, SOCK_STREAM, 0);
    bind(data_sock, (struct sockaddr *)&data_address, sizeof(data_address));
    listen(data_sock, 1);

    // Request file from server
    sprintf(command, "RETR %s\n", filename);
    send(sock, command, sizeof(command), 0);

    // Accept incoming data connection and receive data
    int data_sock_fd = accept(data_sock, NULL, NULL);
    file = fopen(filename, "wb");
    while (bytes_read < file_size) {
        char buffer[1024];
        int bytes = recv(data_sock_fd, buffer, sizeof(buffer), 0);
        fwrite(buffer, sizeof(char), bytes, file);
        bytes_read += bytes;
    }

    // Close data connection and file
    close(data_sock_fd);
    fclose(file);

    // Logout and close control connection
    send(sock, "QUIT\n", sizeof("QUIT\n"), 0);
    close(sock);

    return 0;
}