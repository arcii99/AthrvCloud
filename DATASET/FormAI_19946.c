//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define MAX_FILENAME_LEN 50

void* sync_files(void* client_socket_fd_ptr);

int main()
{
    int server_socket_fd, client_socket_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    pthread_t thread_id;

    // Create server socket
    if((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set server address properties
    memset(&server_addr, 0, sizeof(server_addr));  
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind server socket to server address
    if(bind(server_socket_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1)
    {
        perror("Error binding socket to address");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(server_socket_fd, MAX_CLIENTS) == -1)
    {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    // Wait for and handle incoming connections
    while(1)
    {
        printf("Waiting for connections...\n");
        client_addr_len = sizeof(client_addr);
        client_socket_fd = accept(server_socket_fd, (struct sockaddr*) &client_addr, &client_addr_len);

        if(client_socket_fd == -1)
        {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        // Start a new thread to handle file sync operation with new client
        if(pthread_create(&thread_id, NULL, sync_files, (void*) &client_socket_fd) != 0)
        {
            perror("Error creating thread");
            exit(EXIT_FAILURE);
        }

        printf("New client connected. Thread id: %ld\n", thread_id);
    }

    return 0;
}

void* sync_files(void* client_socket_fd_ptr)
{
    int client_socket_fd = *(int*) client_socket_fd_ptr;
    char filename[MAX_FILENAME_LEN];
    FILE* file_ptr;
    int file_size, bytes_read, bytes_sent;
    char* file_buffer;
    struct timeval timeout;
    fd_set read_fds;
    int select_retval;

    // Receive file name from client
    if(recv(client_socket_fd, filename, MAX_FILENAME_LEN, 0) == -1)
    {
        perror("Error receiving file name from client");
        close(client_socket_fd);
        pthread_exit(NULL);
    }

    printf("Received file name '%s' from client.\n", filename);

    // Open file
    if((file_ptr = fopen(filename, "rb")) == NULL)
    {
        perror("Error opening file");
        close(client_socket_fd);
        pthread_exit(NULL);
    }

    // Get file size
    fseek(file_ptr, 0L, SEEK_END);
    file_size = ftell(file_ptr);
    rewind(file_ptr);

    // Allocate memory for file buffer
    file_buffer = (char*) malloc(file_size);
    if(file_buffer == NULL)
    {
        perror("Error allocating memory for file buffer");
        fclose(file_ptr);
        close(client_socket_fd);
        pthread_exit(NULL);
    }

    // Read file into buffer
    if((bytes_read = fread(file_buffer, sizeof(char), file_size, file_ptr)) != file_size)
    {
        perror("Error reading file");
        free(file_buffer);
        fclose(file_ptr);
        close(client_socket_fd);
        pthread_exit(NULL);
    }

    fclose(file_ptr);

    // Set send timeout
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    // Send file size to client
    if(send(client_socket_fd, &file_size, sizeof(int), 0) == -1)
    {
        perror("Error sending file size to client");
        free(file_buffer);
        close(client_socket_fd);
        pthread_exit(NULL);
    }

    printf("Sent file size %d to client.\n", file_size);

    // Wait for acknowledgement from client
    FD_ZERO(&read_fds);
    FD_SET(client_socket_fd, &read_fds);
    select_retval = select(client_socket_fd+1, &read_fds, NULL, NULL, &timeout);

    if(select_retval == -1)
    {
        perror("Error waiting for acknowledgement from client");
        free(file_buffer);
        close(client_socket_fd);
        pthread_exit(NULL);
    }
    else if(select_retval == 0)
    {
        perror("Timeout waiting for acknowledgement from client");
        free(file_buffer);
        close(client_socket_fd);
        pthread_exit(NULL);
    }

    // Send file buffer to client
    if((bytes_sent = send(client_socket_fd, file_buffer, file_size, 0)) == -1)
    {
        perror("Error sending file buffer to client");
        free(file_buffer);
        close(client_socket_fd);
        pthread_exit(NULL);
    }

    printf("Sent %d bytes of file data to client.\n", bytes_sent);

    close(client_socket_fd);
    free(file_buffer);
    pthread_exit(NULL);
}