//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Claude Shannon
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define PORT 80    // Port Number

int main(int argc, char const *argv[]) {
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    int fd_server, fd_client;
    char buffer[1024];
    int file_fd, nbytes;
    long ret;
    char *fstr;
    char file_location[80];

    // Create socket
    fd_server = socket(AF_INET, SOCK_STREAM, 0);
    if (fd_server < 0) { perror("Cannot create socket"); return -1; }

    // Setup address structure
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(fd_server, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Cannot bind socket to address"); return -1;
    }

    // Listen on socket
    if (listen(fd_server, 10) < 0) { perror("Cannot listen on socket"); return -1; }

    // Infinite loop to accept client connections
    while(1) {
        printf("Waiting for connection on port %d ...\n", PORT);
        fd_client = accept(fd_server, (struct sockaddr*) &client_addr, &client_len);
        if (fd_client < 0) { perror("Cannot accept client connection"); return -1; }
        memset(buffer, 0, 1024);

        // Read client request
        nbytes = read(fd_client, buffer, 1024);
        if (nbytes < 0) { perror("Cannot read from client socket"); return -1; }
        sscanf(buffer, "GET %s ", file_location);
        printf("Request for file: %s\n", file_location);

        // Check if file exists
        if ((file_fd = open(file_location, O_RDONLY)) == -1) {
            file_fd = open("404.html", O_RDONLY);
            fstr = "HTTP/1.0 404 Not Found\r\n\r\n";
        } else {
            fstr = "HTTP/1.0 200 OK\r\n\r\n";
        }

        // Serve file to client
        ret = write(fd_client, fstr, strlen(fstr));
        while ((nbytes = read(file_fd, buffer, 1024)) > 0) {
            write(fd_client, buffer, nbytes);
        }

        // Close client socket
        close(fd_client);
    }

    // Close server socket
    close(fd_server);
    return 0;
}