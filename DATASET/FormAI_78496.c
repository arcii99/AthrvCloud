//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 4096

// Structure for FTP client
struct ftp {
    int sock;
    char buffer[BUF_SIZE];
    char response[BUF_SIZE];
};

// Function to connect to FTP server
int connect_to_server(struct ftp *client, char *ip, int port) {
    
    // Create socket
    if ((client->sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error!\n");
        return -1;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    // Fill server address information
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if (inet_pton(AF_INET, ip, &server_address.sin_addr) <= 0) {
        printf("Invalid address/Address not supported!\n");
        return -1;
    }

    // Connect to server
    if (connect(client->sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Connection failed!\n");
        return -1;
    }

    // Receive welcome message from server
    recv(client->sock, client->buffer, BUF_SIZE, 0);
    printf("%s", client->buffer);

    return 0;
}

// Function to send command to FTP server
int send_command(struct ftp *client, char *command) {
    memset(client->response, 0, BUF_SIZE);

    // Send command to server
    if (send(client->sock, command, strlen(command), 0) < 0) {
        printf("Command sending error!\n");
        return -1;
    }

    // Receive response from server
    recv(client->sock, client->response, BUF_SIZE, 0);
    printf("%s", client->response);

    return 0;
}

// Function to login to FTP server
int login(struct ftp *client, char *username, char *password) {
    char command[BUF_SIZE];

    // User command
    sprintf(command, "USER %s\r\n", username);
    if (send_command(client, command) < 0) {
        return -1;
    }

    // Password command
    sprintf(command, "PASS %s\r\n", password);
    if (send_command(client, command) < 0) {
        return -1;
    }

    return 0;
}

// Function to download file from FTP server
int download_file(struct ftp *client, char *filename) {
    char command[BUF_SIZE];

    // Passive mode command
    sprintf(command, "PASV\r\n");
    if (send_command(client, command) < 0) {
        return -1;
    }

    char *ip_port_str;
    char ip[16];
    int port;

    // Parse IP and port from response
    ip_port_str = strchr(client->response, '(') + 1;
    sscanf(ip_port_str, "%[^,],%d,%*d,%*d,%*d,%*d)", ip, &port);

    // Replace commas with dots
    for (int i = 0; i < strlen(ip); i++) {
        if (ip[i] == ',') {
            ip[i] = '.';
        }
    }

    // Open data connection with server
    struct sockaddr_in data_address;
    memset(&data_address, 0, sizeof(data_address));

    data_address.sin_family = AF_INET;
    data_address.sin_port = htons(port);

    if (inet_pton(AF_INET, ip, &data_address.sin_addr) <= 0) {
        printf("Invalid address/Address not supported!\n");
        return -1;
    }

    int data_socket;

    if ((data_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Data socket creation error!\n");
        return -1;
    }

    if (connect(data_socket, (struct sockaddr *) &data_address, sizeof(data_address)) < 0) {
        printf("Data connection failed!\n");
        return -1;
    }

    // Retrieve file from server
    sprintf(command, "RETR %s\r\n", filename);
    if (send_command(client, command) < 0) {
        return -1;
    }

    FILE *file = fopen(filename, "wb");

    if (!file) {
        printf("File opening error!\n");
        return -1;
    }

    int bytes_received;

    while ((bytes_received = recv(data_socket, client->buffer, BUF_SIZE, 0)) > 0) {
        fwrite(client->buffer, 1, bytes_received, file);
    }

    fclose(file);
    close(data_socket);

    return 0;
}

// Function to logout from FTP server
int logout(struct ftp *client) {
    char command[BUF_SIZE];

    sprintf(command, "QUIT\r\n");
    if (send_command(client, command) < 0) {
        return -1;
    }

    close(client->sock);

    printf("Logout successful!\n");

    return 0;
}

// Main function
int main() {
    struct ftp client;

    // Connect to server
    if (connect_to_server(&client, "127.0.0.1", 21) < 0) {
        return -1;
    }

    // Login to server
    if (login(&client, "username", "password") < 0) {
        return -1;
    }

    // Download file from server
    if (download_file(&client, "test.txt") < 0) {
        return -1;
    }

    // Logout from server
    if (logout(&client) < 0) {
        return -1;
    }

    return 0;
}