//FormAI DATASET v1.0 Category: Simple Web Server ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define PORT 8080
#define BUFF_SIZE 2048

int main(int argc, char const *argv[]) {

    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFF_SIZE] = {0};
    int address_len = sizeof(server_address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Setting server address properties
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding socket to the server address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Handling incoming connections
    while (1) {
        printf("\nWaiting for incoming connections...\n");
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&address_len))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("New client connected. IP address: %s port number: %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Receiving request data from client
        memset(buffer, 0, BUFF_SIZE);
        if (read(client_fd, buffer, BUFF_SIZE) < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Received request:\n%s\n", buffer);

        // Parsing request data
        const char delim[2] = " ";
        char *token = strtok(buffer, delim);
        char *request_method = token;
        token = strtok(NULL, delim);
        char *request_path = token;

        if (strcasecmp(request_method, "GET") == 0) {
            FILE *requested_file;

            if (strcmp(request_path, "/") == 0) { // Default case
                requested_file = fopen("index.html", "r");
            } else { // Serving request for any other file
                requested_file = fopen(request_path + 1, "r");
            }

            if (requested_file == NULL) {
                char response[] = "HTTP/1.1 404 Not Found\r\n\r\n";
                write(client_fd, response, strlen(response));
            } else {
                char response[BUFF_SIZE];
                sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
                write(client_fd, response, strlen(response));

                int bytes_read;
                char file_buffer[BUFF_SIZE];
                while ((bytes_read = fread(file_buffer, 1, BUFF_SIZE, requested_file)) > 0) {
                    write(client_fd, file_buffer, bytes_read);
                }
                fclose(requested_file);
            }
        } else {
            char response[] = "HTTP/1.1 405 Method Not Allowed\r\n\r\n";
            write(client_fd, response, strlen(response));
        }

        close(client_fd);
        printf("Connection with client closed.\n");
    }

    close(server_fd);
    return 0;
}