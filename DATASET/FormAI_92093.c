//FormAI DATASET v1.0 Category: Simple Web Server ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char response[4096] = {0};

    char *html_response = "<html><body><h1>Welcome to the Curious Web Server!</h1></body></html>\r\n";
    char *css_response = "body {background-color: yellow;}\r\nh1 {color: blue;}\r\n";
    char *js_response = "alert('Hello from the Curious Web Server!');\r\n";

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Allow socket to be reused immediately after termination
    int enable = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &enable, sizeof(enable))) {
        perror("setsockopt failed");
        return -1;
    }

    // Bind server to IP address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        return -1;
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        return -1;
    }

    printf("Waiting for incoming connections...\n");

    while(1) {

        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            return -1;
        }

        char buffer[1024] = {0};
        valread = read(new_socket, buffer, 1024);
        printf("%s", buffer);

        // Check if request is GET method
        if (strncmp(buffer, "GET", 3) != 0) {
            sprintf(response, "HTTP/1.1 501 Not Implemented\r\n\r\n");
            send(new_socket, response, strlen(response), 0);
            close(new_socket);
            continue;
        }

        // Check if requested resource is /, /index.html, or /index.htm
        if (strncmp(buffer + 4, "/", 1) == 0 ||
            strncmp(buffer + 4, "/index.html", 11) == 0 ||
            strncmp(buffer + 4, "/index.htm", 10) == 0) {
            sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n%s", html_response);
        }
        // Check if requested resource is /styles.css
        else if (strncmp(buffer + 4, "/styles.css", 11) == 0) {
            sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/css\r\n\r\n%s", css_response);
        }
        // Check if requested resource is /script.js
        else if (strncmp(buffer + 4, "/script.js", 10) == 0) {
            sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/javascript\r\n\r\n%s", js_response);
        }
        // Else, resource not found
        else {
            sprintf(response, "HTTP/1.1 404 Not Found\r\n\r\n");
        }

        send(new_socket, response, strlen(response), 0);
        close(new_socket);
    }
    
    return 0;
}