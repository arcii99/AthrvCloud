//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAXSIZE 4096

int main(int argc, char *argv[]) {
    int client_socket, port;
    char buffer[MAXSIZE], filename[100], filedata[MAXSIZE];
    struct sockaddr_in server_addr;

	// Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Set IP and port of the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the FTP server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Unable to connect to server");
        exit(EXIT_FAILURE);
    }

    // Receive welcome message from server
    memset(buffer, 0, MAXSIZE);
    read(client_socket, buffer, MAXSIZE);
    printf("%s", buffer);

    // Send user info to server
    strcpy(buffer, "USER anonymous\r\n");
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAXSIZE);
    read(client_socket, buffer, MAXSIZE);
    printf("%s", buffer);

    // Send password to server
    strcpy(buffer, "PASS guest\r\n");
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAXSIZE);
    read(client_socket, buffer, MAXSIZE);
    printf("%s", buffer);

    // Enter passive mode
    strcpy(buffer, "PASV\r\n");
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAXSIZE);
    read(client_socket, buffer, MAXSIZE);
    printf("%s", buffer);

    // Retrieve file from server
    printf("Enter file name to download: ");
    scanf("%s", filename);
    sprintf(buffer, "RETR %s\r\n", filename);
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAXSIZE);
    read(client_socket, buffer, MAXSIZE);
    printf("%s", buffer);

    // Receive file from server
    FILE* file = fopen(filename, "wb");
    while (1) {
        memset(filedata, 0, MAXSIZE);
        int bytes_received = recv(client_socket, filedata, MAXSIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        fwrite(filedata, sizeof(char), bytes_received, file);
    }
    fclose(file);

    // Close connection to server
    strcpy(buffer, "QUIT\r\n");
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAXSIZE);
    read(client_socket, buffer, MAXSIZE);
    printf("%s", buffer);
    close(client_socket);

    return 0;
}