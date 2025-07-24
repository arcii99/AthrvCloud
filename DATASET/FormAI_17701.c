//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: optimized
/* C program to demo a FTP Client */
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in server_address;
    char *ftp_server_ip_address = "127.0.0.1"; // FTP Server IP address
    int port_number = 21; // Default port number for FTP

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set the server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    if(inet_pton(AF_INET,ftp_server_ip_address,&server_address.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to the FTP server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // Get response message from server
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send FTP commands
    char *user = "USER ftpuser\r\n";
    char *password = "PASS ftpuserpass\r\n";
    char *list_command = "LIST\r\n";
    char *quit_command = "QUIT\r\n";

    send(sock, user, strlen(user), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    send(sock, password, strlen(password), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    send(sock, list_command, strlen(list_command), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    send(sock, quit_command, strlen(quit_command), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Close the socket
    close(sock);

    return 0;
}