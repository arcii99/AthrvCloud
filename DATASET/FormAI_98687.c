//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define buffer_size 1024

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_address;
    char file_name[buffer_size], command[buffer_size], buffer[buffer_size];
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(21);
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    if (connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }
    printf("Connected to ftp server\n");
    recv(client_socket, buffer, buffer_size, 0);
    printf("%s", buffer);
    memset(buffer, 0, buffer_size);
    printf("Enter command: \n");
    while (1) {
        memset(command, 0, buffer_size);
        memset(file_name, 0, buffer_size);
        fgets(command, buffer_size, stdin);
        strtok(command, "\n");
        if (strcmp(command, "quit") == 0) {
            send(client_socket, command, strlen(command), 0);
            recv(client_socket, buffer, buffer_size, 0);
            printf("%s", buffer);
            break;
        } else if (strcmp(command, "ls") == 0) {
            send(client_socket, command, strlen(command), 0);
            recv(client_socket, buffer, buffer_size, 0);
            printf("%s", buffer);
            memset(buffer, 0, buffer_size);
        } else if (strncmp(command, "get", 3) == 0) {
            memcpy(file_name, command+4, strlen(command)-4);
            send(client_socket, command, strlen(command), 0);
            recv(client_socket, buffer, buffer_size, 0);
            if (strcmp(buffer, "Error: Unable to get file") != 0) {
                FILE *fp = fopen(file_name, "wb");
                if (fp != NULL) {
                    while (1) {
                        memset(buffer, 0, buffer_size);
                        int bytes = recv(client_socket, buffer, buffer_size, 0);
                        if (bytes == 0)
                            break;
                        fwrite(buffer, 1, bytes, fp);
                    }
                    fclose(fp);
                    printf("File downloaded successfully to %s\n", file_name);
                } else {
                    printf("Error: Unable to create file\n");
                }
            } else {
                printf("Error: Unable to get file\n");
            }
            memset(buffer, 0, buffer_size);
        } else if (strncmp(command, "put", 3) == 0) {
            memcpy(file_name, command+4, strlen(command)-4);
            FILE *fp = fopen(file_name, "rb");
            if (fp != NULL) {
                send(client_socket, command, strlen(command), 0);
                recv(client_socket, buffer, buffer_size, 0);
                while (1) {
                    memset(buffer, 0, buffer_size);
                    int bytes = fread(buffer, 1, buffer_size, fp);
                    if (bytes == 0)
                        break;
                    send(client_socket, buffer, bytes, 0);
                }
                fclose(fp);
                recv(client_socket, buffer, buffer_size, 0);
                printf("%s", buffer);
            } else {
                printf("Error: Unable to open file\n");
            }
            memset(buffer, 0, buffer_size);
        } else {
            printf("Invalid command\n");
        }
        printf("Enter command: \n");
    }
    close(client_socket);
    return 0;
}