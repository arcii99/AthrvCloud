//FormAI DATASET v1.0 Category: Socket programming ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char **argv){
    
    int socket_fd;
    struct sockaddr_in server_addr;

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0){
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE] = {0};
    ssize_t read_bytes = 0;

    while (1) {
        printf("Enter a message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(socket_fd, buffer, strlen(buffer), 0);
        
        read_bytes = read(socket_fd, buffer, BUFFER_SIZE);
        if (read_bytes == 0){
            printf("Connection closed by the server.\n");
            break;
        }
        else if (read_bytes < 0){
            perror("Error occurred while reading from the server");
            break;
        }
        printf("Server's reply: %s\n", buffer);
    }

    close(socket_fd);
    exit(EXIT_SUCCESS);
}