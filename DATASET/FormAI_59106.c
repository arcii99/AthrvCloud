//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

#define IMAP_SERVER_ADDRESS "imap.gmail.com"
#define IMAP_SERVER_PORT 993

typedef struct {
    int sock_fd;
    char buffer[MAX_BUFFER_SIZE];
} IMAP;

void *read_socket(void *arg) {
    IMAP *imap = (IMAP *)arg;

    while(1) {
        memset(imap->buffer, 0, MAX_BUFFER_SIZE);
        ssize_t bytes_read = read(imap->sock_fd, imap->buffer, MAX_BUFFER_SIZE);

        if(bytes_read < 0) {
            perror("Error reading from socket");
            break;
        }

        printf("Received message: %s\n", imap->buffer);
    }

    pthread_exit(NULL);
}

int main() {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(sock_fd < 0) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(IMAP_SERVER_PORT);
    inet_pton(AF_INET, IMAP_SERVER_ADDRESS, &server_address.sin_addr);

    int connect_result = connect(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address));

    if(connect_result < 0) {
        perror("Error connecting to server");
        return EXIT_FAILURE;
    }

    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytes_read;

    // Login
    bytes_read = read(sock_fd, buffer, MAX_BUFFER_SIZE);

    if(bytes_read < 0) {
        perror("Error reading login message from server");
        return EXIT_FAILURE;
    }

    printf("Login message: %s\n", buffer);
    sprintf(buffer, "LOGIN USERNAME PASSWORD\r\n");
    write(sock_fd, buffer, strlen(buffer));

    // Create new thread to read from socket
    IMAP imap;
    imap.sock_fd = sock_fd;
    pthread_t read_thread;
    pthread_create(&read_thread, NULL, read_socket, (void *)&imap);

    // Send logout command after 5 seconds
    sleep(5);
    sprintf(buffer, "LOGOUT\r\n");
    write(sock_fd, buffer, strlen(buffer));

    // Wait for read thread to finish
    pthread_join(read_thread, NULL);

    // Close socket
    close(sock_fd);

    return EXIT_SUCCESS;
}