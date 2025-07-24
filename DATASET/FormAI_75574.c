//FormAI DATASET v1.0 Category: Simple Web Server ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    // Create Socket
    int server_fd, new_socket, valread;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(server_addr);
    char buffer[BUFFER_SIZE] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }

    // Set Socket Options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0) {
        perror("setsockopt() failed");
        return EXIT_FAILURE;
    }

    // Bind Socket to Address and Port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind() failed");
        return EXIT_FAILURE;
    }

    // Start Listening
    if (listen(server_fd, BACKLOG) < 0) {
        perror("listen() failed");
        return EXIT_FAILURE;
    }

    // Handle Incoming Connections
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&server_addr,
            (socklen_t*)&addrlen)) < 0) {
            perror("accept() failed");
            return EXIT_FAILURE;
        }

        // Read Request From Client
        valread = read(new_socket, buffer, BUFFER_SIZE);

        // Handle Different Requests
        if (strncmp(buffer, "GET /", 5) == 0) {
            // Serve Web Page
            char page[] = "<html><body><h1>404 - Page Not Found</h1></body></html>";
            send(new_socket, page, strlen(page), 0);
        } else if (strncmp(buffer, "POST ", 5) == 0) {
            // Process Form Data
            char *pos = strstr(buffer, "\r\n\r\n");
            if (pos != NULL) {
                // Store Form Data (in this post-apocalyptic world, we don't waste anything)
                FILE *fptr;
                fptr = fopen("form_data.txt", "a");
                fwrite(pos+4, sizeof(char), valread-(pos-buffer)-4, fptr);
                fclose(fptr);

                // Send Response to Client
                char response[] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Form Data Submitted Successfully!<h1></body></html>";
                send(new_socket, response, strlen(response), 0);
            } else {
                // Invalid Request
                char response[] = "HTTP/1.1 400 Bad Request\nContent-Type: text/html\n\n<html><body><h1>Invalid Request<h1></body></html>";
                send(new_socket, response, strlen(response), 0);
            }
        } else {
            // Invalid Request
            char response[] = "HTTP/1.1 400 Bad Request\nContent-Type: text/html\n\n<html><body><h1>Invalid Request<h1></body></html>";
            send(new_socket, response, strlen(response), 0);
        }

        // Close Connection
        close(new_socket);
    }

    // Close Server Socket
    close(server_fd);

    return EXIT_SUCCESS;
}