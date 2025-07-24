//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: artistic
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int control_socket, data_socket;
    struct sockaddr_in server_address, data_address;
    char buffer[BUFFER_SIZE];

    // Create the control socket
    control_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (control_socket == -1) {
        printf("Failed to create control socket\n");
        return -1;
    }

    // Initialize the server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(21); // FTP Command port
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost IP address

    // Connect to the FTP server
    if (connect(control_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Failed to connect to FTP server\n");
        return -1;
    }

    // Receive welcome message from server
    memset(buffer, 0, BUFFER_SIZE);
    recv(control_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Login to FTP server
    char user[100], pass[100];
    printf("Username: ");
    fgets(user, 100, stdin);
    send(control_socket, user, strlen(user), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(control_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    printf("Password: ");
    fgets(pass, 100, stdin);
    send(control_socket, pass, strlen(pass), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(control_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Change to binary mode
    send(control_socket, "TYPE I\r\n", strlen("TYPE I\r\n"), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(control_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Open data socket
    data_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (data_socket == -1) {
        printf("Failed to create data socket\n");
        return -1;
    }

    // Initialize the data address structure
    memset(&data_address, 0, sizeof(data_address));
    data_address.sin_family = AF_INET;
    data_address.sin_port = htons(20); // FTP Data port
    data_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost IP address

    // Connect to data socket
    if (connect(data_socket, (struct sockaddr *)&data_address, sizeof(data_address)) < 0) {
        printf("Failed to connect to data socket\n");
        return -1;
    }

    // Download file
    char filename[100];
    printf("Enter filename to download: ");
    fgets(filename, 100, stdin);
    strtok(filename, "\n"); // Remove new line character

    char file_command[100];
    sprintf(file_command, "RETR %s\r\n", filename);
    send(control_socket, file_command, strlen(file_command), 0);

    int file = open(filename, O_WRONLY | O_CREAT, 0644);
    if (file == -1) {
        printf("Failed to open file for writing\n");
        return -1;
    }

    int bytes_read;
    memset(buffer, 0, BUFFER_SIZE);
    while ((bytes_read = recv(data_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        write(file, buffer, bytes_read);
        memset(buffer, 0, BUFFER_SIZE);
    }

    memset(buffer, 0, BUFFER_SIZE);
    recv(control_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    close(file);
    close(data_socket);
    close(control_socket);

    return 0;
}