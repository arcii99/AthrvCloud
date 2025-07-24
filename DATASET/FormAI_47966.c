//FormAI DATASET v1.0 Category: Simple Web Server ; Style: energetic
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 8080
#define BUFSIZE 1024

int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFSIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        // Accepting incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("accept");
            continue;
        }

        // Reading HTTP request from the client
        valread = read(new_socket, buffer, BUFSIZE);

        // Extracting the requested file path
        char req_file[BUFSIZE] = {0};
        sscanf(buffer, "GET %s HTTP", req_file);

        // Opening the requested file
        int fd = open(req_file+1, O_RDONLY);

        if (fd < 0) {
            char *msg = "HTTP/1.1 404 Not Found\nContent-Length: 22\nContent-Type: text/plain\n\n404 Not Found\n";
            write(new_socket, msg, strlen(msg));
            close(new_socket);
            continue;
        }

        // Writing file content to the socket
        char file_buffer[BUFSIZE] = {0};
        int bytes_read;
        while ((bytes_read = read(fd, file_buffer, BUFSIZE)) > 0) {
            write(new_socket, file_buffer, bytes_read);
        }

        // Closing file descriptor and socket
        close(fd);
        close(new_socket);
    }

    return 0;
}