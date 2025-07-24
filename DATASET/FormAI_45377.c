//FormAI DATASET v1.0 Category: Simple Web Server ; Style: enthusiastic
/*
Let's build a simple web server in C!
Isn't it amazing that with just a few lines of code, we can serve web pages and provide data to clients all over the world?
In this program, we'll create an HTTP server that listens for incoming requests, reads the requested file, and sends the file data back to the client.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define WEB_ROOT "/var/www/html" // root directory of web files
#define MAX_CONNECTIONS 10 // maximum number of clients that can connect simultaneously

int main(int argc, char *argv[])
{
    // create server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // setup server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80); // HTTP port
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind server socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) == -1)
    {
        perror("Error listening for incoming connections");
        exit(EXIT_FAILURE);
    }
    
    printf("Server running on port 80...\n");

    while (1)
    {
        // accept incoming connection
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1)
        {
            perror("Error accepting incoming connection");
            continue;
        }

        // read request from client
        char request[1024], method[20], filename[50], protocol[20];
        int bytes_read = read(client_socket, request, sizeof(request)-1);
        if (bytes_read == -1)
        {
            perror("Error reading request from client");
            close(client_socket);
            continue;
        }

        // parse request
        sscanf(request, "%s %s %s", method, filename, protocol);
        if (strcasecmp(method, "GET") != 0)
        {
            // unsupported HTTP method
            write(client_socket, "HTTP/1.1 405 Method Not Allowed\r\n", 33);
            close(client_socket);
            continue;
        }

        // construct file path
        char filepath[100];
        strcpy(filepath, WEB_ROOT);
        strcat(filepath, filename);
        if (filepath[strlen(filepath)-1] == '/')
        {
            // default page
            strcat(filepath, "index.html");
        }

        // open file for reading
        int file_fd = open(filepath, O_RDONLY);
        if (file_fd == -1)
        {
            // file not found
            write(client_socket, "HTTP/1.1 404 Not Found\r\n", 24);
            close(client_socket);
            continue;
        }

        // send file data to client
        char buf[4096];
        int bytes_sent;
        while ((bytes_read = read(file_fd, buf, sizeof(buf))) > 0)
        {
            bytes_sent = write(client_socket, buf, bytes_read);
            if (bytes_sent == -1)
            {
                perror("Error sending file data to client");
                break;
            }
        }

        // close file
        close(file_fd);

        // close client socket
        close(client_socket);
    }

    // close server socket
    close(server_socket);

    return 0;
}