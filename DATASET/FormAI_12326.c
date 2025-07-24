//FormAI DATASET v1.0 Category: Client Server Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, file_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char filename[1024];
    int choice;

    // Create a socket to listen for connections
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server running on port %d\n", PORT);

    // Loop to keep accepting client connections
    while(1) {
        // Accept a client connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Client connected\n");

        // Prompt the client for an upload or download operation
        strcpy(buffer, "Select an operation:\n1. Upload\n2. Download\n");
        send(new_socket, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer));

        // Receive the client's choice
        recv(new_socket, &choice, sizeof(int), 0);

        if(choice == 1) { // Upload operation
            // Receive the filename from the client
            recv(new_socket, filename, 1024, 0);
            printf("Received upload filename: %s\n", filename);

            // Create the file on the server
            if((file_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666)) < 0) {
                perror("Could not create file");
                exit(EXIT_FAILURE);
            }

            // Receive and write the data to the server file
            int bytes_read;
            while((bytes_read = recv(new_socket, buffer, sizeof(buffer), 0)) > 0) {
                write(file_fd, buffer, bytes_read);
                memset(buffer, 0, sizeof(buffer));
            }

            printf("File upload complete\n");

            // Close the server file
            close(file_fd);
        }
        else if(choice == 2) { // Download operation
            // Receive the filename from the client
            recv(new_socket, filename, 1024, 0);
            printf("Received download filename: %s\n", filename);

            // Open the file on the server
            if((file_fd = open(filename, O_RDONLY)) < 0) {
                perror("Could not open file");
                exit(EXIT_FAILURE);
            }

            // Send the file size to the client
            struct stat st;
            stat(filename, &st);
            int filesize = st.st_size;
            send(new_socket, &filesize, sizeof(int), 0);

            // Read from the server file and send to the client
            int bytes_read;
            while((bytes_read = read(file_fd, buffer, sizeof(buffer))) > 0) {
                send(new_socket, buffer, bytes_read, 0);
                memset(buffer, 0, sizeof(buffer));
            }

            printf("File download complete\n");

            // Close the server file
            close(file_fd);
        }
        else { // Invalid operation
            strcpy(buffer, "Invalid operation selected\n");
            send(new_socket, buffer, strlen(buffer), 0);
        }

        // Close the client socket and wait for the next connection
        close(new_socket);
    }

    return 0;
}