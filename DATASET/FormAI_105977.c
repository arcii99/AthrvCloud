//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 21
#define BUFFER_SIZE 1024

int main() {
    int sock_fd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address;

    //Create a socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    //Setup server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_ADDR, &server_address.sin_addr) < 1) {
        printf("Error: Invalid server address\n");
        return 1;
    }

    //Connect to server
    if (connect(sock_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        printf("Error: Failed to connect to server\n");
        return 1;
    }

    //Read welcome message from server
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Error reading from server\n");
        return 1;
    }
    printf("%s", buffer);

    //Send username
    printf("Username: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    strcat(buffer, "\r\n");
    if (send(sock_fd, buffer, strlen(buffer), 0) == -1) {
        printf("Error sending username to server\n");
        return 1;
    }

    //Read response from server
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Error reading from server\n");
        return 1;
    }
    printf("%s", buffer);

    //Send password
    printf("Password: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    strcat(buffer, "\r\n");
    if (send(sock_fd, buffer, strlen(buffer), 0) == -1) {
        printf("Error sending password to server\n");
        return 1;
    }

    //Read response from server
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Error reading from server\n");
        return 1;
    }
    printf("%s", buffer);

    //Send PASV command
    const char* pasv_cmd = "PASV\r\n";
    if (send(sock_fd, pasv_cmd, strlen(pasv_cmd), 0) == -1) {
        printf("Error sending PASV command to server\n");
        return 1;
    }

    //Read response from server
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Error reading from server\n");
        return 1;
    }
    printf("%s", buffer);

    //Parse PASV response to get port number
    char* p = strtok(buffer, "(,");
    p = strtok(NULL, "(,");
    p = strtok(NULL, "(,");
    p = strtok(NULL, "(,");
    int port = atoi(p) * 256;
    p = strtok(NULL, "(,");
    port += atoi(p);

    //Create data socket for file transfer
    int data_sock_fd;
    if ((data_sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: Could not create data socket\n");
        return 1;
    }

    //Setup data socket address
    struct sockaddr_in data_address;
    memset(&data_address, 0, sizeof(data_address));
    data_address.sin_family = AF_INET;
    data_address.sin_port = htons(port);
    if (inet_pton(AF_INET, SERVER_ADDR, &data_address.sin_addr) < 1) {
        printf("Error: Invalid server address\n");
        return 1;
    }

    //Connect to data socket
    if (connect(data_sock_fd, (struct sockaddr*)&data_address, sizeof(data_address)) == -1) {
        printf("Error: Failed to connect to data socket\n");
        return 1;
    }

    //Send RETR command to download file
    const char* retr_cmd = "RETR file.txt\r\n";
    if (send(sock_fd, retr_cmd, strlen(retr_cmd), 0) == -1) {
        printf("Error sending RETR command to server\n");
        return 1;
    }

    //Read response from server
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Error reading from server\n");
        return 1;
    }
    printf("%s", buffer);

    //Receive file data
    FILE* file = fopen("file.txt", "wb");
    int bytes_received;
    while ((bytes_received = recv(data_sock_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }
    if (bytes_received == -1) {
        printf("Error receiving file data\n");
        return 1;
    }
    fclose(file);

    //Close data socket
    close(data_sock_fd);

    //Send QUIT command to disconnect from server
    const char* quit_cmd = "QUIT\r\n";
    if (send(sock_fd, quit_cmd, strlen(quit_cmd), 0) == -1) {
        printf("Error sending QUIT command to server\n");
        return 1;
    }

    //Read response from server
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Error reading from server\n");
        return 1;
    }
    printf("%s", buffer);

    //Close socket
    close(sock_fd);

    return 0;
}