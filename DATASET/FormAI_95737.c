//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: real-life
/* FTP Client Program */

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int socket_desc;
    struct sockaddr_in server_addr;
    char *server_ip = "127.0.0.1";
    int server_port = 21;
    char buffer[BUFFER_SIZE];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Error: Could not create socket");
        return 1;
    }

    // Set server details
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    // Connect to the server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Connection to the server failed");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: Failed to receive response from server");
        return 1;
    }
    printf("Server response: %s\n", buffer);

    // Send user name
    char *user_name = "USER anonymous\r\n";
    if (send(socket_desc, user_name, strlen(user_name), 0) < 0) {
        printf("Error: Failed to send user name to server");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: Failed to receive response from server");
        return 1;
    }
    printf("Server response: %s\n", buffer);

    // Send password
    char *password = "PASS password\r\n";
    if (send(socket_desc, password, strlen(password), 0) < 0) {
        printf("Error: Failed to send password to server");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: Failed to receive response from server");
        return 1;
    }
    printf("Server response: %s\n", buffer);

    // Send request for file
    char *file_name = "RETR file.txt\r\n";
    if (send(socket_desc, file_name, strlen(file_name), 0) < 0) {
        printf("Error: Failed to send file request to server");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: Failed to receive response from server");
        return 1;
    }
    printf("Server response: %s\n", buffer);

    // Create file to save content
    FILE *file = fopen("file.txt", "w");

    // Receive file content
    int bytes_received;
    while ((bytes_received = recv(socket_desc, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }
    fclose(file);

    printf("File download successful\n");

    // Disconnect from server
    close(socket_desc);

    return 0;
}