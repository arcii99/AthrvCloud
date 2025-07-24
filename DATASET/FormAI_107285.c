//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024
#define DEFAULT_PORT 21

typedef struct {
    char* ip_address;
    char* username;
    char* password;
    char* file_path;
    int port;
} FTP_CLIENT_INFO;

void error_exit(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

void send_control_message(int control_socket, char* message) {
    char buffer[MAX_BUF_SIZE];
    int read_size;

    if (write(control_socket, message, strlen(message)) < 0) {
        error_exit("Error sending message");
    }

    if ((read_size = read(control_socket, buffer, MAX_BUF_SIZE)) < 0) {
        error_exit("Error receiving message");
    }
    buffer[read_size] = '\0';

    printf("%s", buffer);
}

void send_data_message(int data_socket, char* message) { 
    if (write(data_socket, message, strlen(message)) < 0) {
        error_exit("Error sending message");
    }
}

int ftp_connect(FTP_CLIENT_INFO* info) {
    int control_socket;
    struct sockaddr_in server_address;

    if ((control_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_exit("Error creating socket");
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(info->port);
    if (inet_pton(AF_INET, info->ip_address, &server_address.sin_addr) < 0) {
        error_exit("Invalid IP address");
    }

    if (connect(control_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        error_exit("Error connecting to server");
    }

    send_control_message(control_socket, "USER ");
    send_control_message(control_socket, info->username);
    send_control_message(control_socket, "\r\n");

    send_control_message(control_socket, "PASS ");
    send_control_message(control_socket, info->password);
    send_control_message(control_socket, "\r\n");

    return control_socket;
}

void ftp_get(FTP_CLIENT_INFO* info) {
    int data_socket;
    char file_name[MAX_BUF_SIZE];
    char command[MAX_BUF_SIZE];
    sprintf(command, "RETR %s\r\n", info->file_path);

    send_control_message(ftp_connect(info), "PASV\r\n");

    sscanf(info->file_path, "%[^/]/%s", file_name, file_name + strlen(file_name) + 1);

    char buffer[MAX_BUF_SIZE];
    sscanf(buffer, "%*[^(](%d,%d,%d,%d,%d,%d)", &data_socket);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(data_socket);

    if ((data_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_exit("Error creating socket");
    }
    if (bind(data_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        error_exit("Error binding socket");
    }
    if (listen(data_socket, 1) < 0) {
        error_exit("Error listening on socket");
    }

    send_control_message(ftp_connect(info), command);

    int file_size = 0;
    int bytes_received = 0;
    char buffer_recv[MAX_BUF_SIZE];
    FILE* file = fopen(file_name, "w");

    while ((bytes_received = read(data_socket, buffer_recv, MAX_BUF_SIZE)) > 0) {
        fwrite(buffer_recv, 1, bytes_received, file);
        file_size += bytes_received;
    }

    fclose(file);

    send_control_message(ftp_connect(info), "QUIT\r\n");
}

int main() {
    FTP_CLIENT_INFO info;
    info.ip_address = "127.0.0.1";
    info.username = "user";
    info.password = "password";
    info.file_path = "example.txt";
    info.port = DEFAULT_PORT;

    ftp_get(&info);

    return 0;
}