//FormAI DATASET v1.0 Category: Simple Web Server ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define HTML_PAGE "<html><head><title>My First Web Page</title></head><body><h1>Hello World!</h1></body></html>"
#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *ok_response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    char response[2048];

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Binding socket to the address
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Starting the server
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Loop to serve clients
    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                           (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        memset(buffer, 0, sizeof(buffer));  // Clearing the buffer

        valread = read(new_socket, buffer, sizeof(buffer));

        // Check if request is GET "/" HTTP/1.1
        if (strstr(buffer, "GET / HTTP/1.1") != NULL) {
            sprintf(response, "%s%s", ok_response, HTML_PAGE);
        } else {  // if request is not GET "/"
            sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\n404 Not Found");
        }

        write(new_socket, response, strlen(response));  // Sending response

        printf("Response sent:\n%s\n", response);

        close(new_socket);  // Closing the socket
    }

    return 0;
}