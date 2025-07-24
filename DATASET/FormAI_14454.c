//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <sys/stat.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    // Set server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\n Invalid address/ Address not supported \n");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\n Connection Failed \n");
        return -1;
    }

    // Receive welcome message from server
    valread = read(sock, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Log in user
    bzero(buffer, BUFFER_SIZE); // Clear buffer
    printf("Username: ");
    scanf("%s", buffer);
    send(sock, buffer, strlen(buffer), 0);
    bzero(buffer, BUFFER_SIZE); // Clear buffer
    printf("Password: ");
    scanf("%s", buffer);
    send(sock, buffer, strlen(buffer), 0);

    // Receive login response from server
    valread = read(sock, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    while (1) {
        bzero(buffer, BUFFER_SIZE); // Clear buffer
        printf("Enter command: ");
        scanf("%s", buffer);
        send(sock, buffer, strlen(buffer), 0);
        if (strcmp(buffer, "quit") == 0) {
            break;
        }
        if (strcmp(buffer, "ls") == 0) {
            char data_buffer[BUFFER_SIZE] = {0};
            while ((valread = read(sock, data_buffer, BUFFER_SIZE)) > 0) {
                printf("%s", data_buffer);
                bzero(data_buffer, BUFFER_SIZE); // Clear data buffer
            }
            printf("\n");
        }
        if (strcmp(buffer, "get") == 0) {
            char filename[BUFFER_SIZE] = {0}, path[BUFFER_SIZE] = {0};
            bzero(buffer, BUFFER_SIZE); // Clear buffer
            printf("Enter filename: ");
            scanf("%s", filename);
            sprintf(path, "Downloads/%s", filename);
            int file_fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (file_fd == -1) {
                printf("Error creating file\n");
                continue;
            }
            int filesize = 0;
            valread = read(sock, &filesize, sizeof(filesize));
            if (filesize == -1) {
                printf("File doesn't exist on server\n");
                continue;
            }
            printf("File size: %d bytes\n", filesize);
            int bytes_received = 0, bytes_left = filesize;
            while (bytes_received < filesize) {
                int bytes_to_receive = (bytes_left > BUFFER_SIZE) ? BUFFER_SIZE : bytes_left;
                bzero(buffer, BUFFER_SIZE); // Clear buffer
                valread = read(sock, buffer, bytes_to_receive);
                if (valread < 0) {
                    printf("Error receiving file\n");
                    break;
                }
                bytes_received += valread;
                bytes_left -= valread;
                write(file_fd, buffer, valread);
            }
            close(file_fd);
            printf("File saved to Downloads folder\n");
        }
        if (strcmp(buffer, "put") == 0) {
            char filename[BUFFER_SIZE] = {0}, path[BUFFER_SIZE] = {0};
            bzero(buffer, BUFFER_SIZE); // Clear buffer
            printf("Enter filename: ");
            scanf("%s", filename);
            sprintf(path, "Uploads/%s", filename);
            int file_fd = open(path, O_RDONLY);
            if (file_fd == -1) {
                printf("Error opening file\n");
                continue;
            }
            struct stat file_stat;
            if (fstat(file_fd, &file_stat) == -1) {
                printf("Error getting file size\n");
                continue;
            }
            int filesize = file_stat.st_size;
            printf("File size: %d bytes\n", filesize);
            send(sock, &filesize, sizeof(filesize), 0);
            int bytes_sent = 0, bytes_left = filesize;
            while (bytes_sent < filesize) {
                int bytes_to_send = (bytes_left > BUFFER_SIZE) ? BUFFER_SIZE : bytes_left;
                bzero(buffer, BUFFER_SIZE); // Clear buffer
                valread = read(file_fd, buffer, bytes_to_send);
                if (valread < 0) {
                    printf("Error reading file\n");
                    break;
                }
                bytes_sent += valread;
                bytes_left -= valread;
                send(sock, buffer, valread, 0);
            }
            printf("File sent to server\n");
            close(file_fd);
        }
    }

    close(sock);
    return 0;
}