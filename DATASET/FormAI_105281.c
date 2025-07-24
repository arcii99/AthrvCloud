//FormAI DATASET v1.0 Category: Simple Web Server ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PORT 8080

int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the provided port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening to the incoming client requests
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        // Accepting incoming client requests
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Reading the client request
        valread = read(new_socket, buffer, 1024);
        printf("%s\n", buffer);

        // Getting the filename from the client request
        char filename[1024] = {0};
        sscanf(buffer, "GET /%s HTTP/1", filename);
        printf("Filename is: %s\n", filename);
        int fd = open(filename, O_RDONLY);

        // Sending the requested file back to the client
        struct stat file_info;
        fstat(fd, &file_info);
        char header[1024] = {0};
        sprintf(header, "HTTP/1.1 200 OK\nContent-Length: %ld\n\n", file_info.st_size);
        send(new_socket, header, strlen(header), 0);
        sendfile(new_socket, fd, NULL, file_info.st_size);

        // Closing the file descriptor and client socket
        close(fd);
        close(new_socket);
    }

    return 0;
}