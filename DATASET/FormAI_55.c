//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int data_socket, command_socket, port, size;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE], *command, *filename, *ip_address;

    if (argc != 4) {
        printf("Usage: ftp_client <server-ip> <port> <filename>\n");
        exit(EXIT_FAILURE);
    }

    ip_address = argv[1];
    port = atoi(argv[2]);
    filename = argv[3];

    // Create command socket
    if ((command_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Failed to create command socket\n");
        exit(EXIT_FAILURE);
    }

    // Connect command socket to server
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip_address);
    server_address.sin_port = htons(port);

    if (connect(command_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    // Send RETR command to server to initiate data transfer
    command = (char *)malloc(strlen("RETR ") + strlen(filename) + 1);
    sprintf(command, "RETR %s", filename);

    if (send(command_socket, command, strlen(command), 0) < 0) {
        printf("Failed to send command to server\n");
        exit(EXIT_FAILURE);
    }

    free(command);

    // Create data socket
    if ((data_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Failed to create data socket\n");
        exit(EXIT_FAILURE);
    }

    // Connect data socket to server
    if (connect(data_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    // Receive file data from server and save to local file
    FILE *file_ptr = fopen(filename, "wb");

    while ((size = recv(data_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), size, file_ptr);
    }

    fclose(file_ptr);

    // Close sockets
    close(command_socket);
    close(data_socket);

    printf("File transfer complete!\n");

    return 0;
}