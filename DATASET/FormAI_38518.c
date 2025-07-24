//FormAI DATASET v1.0 Category: Simple Web Server ; Style: medieval
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 

#define PORT 8080 
#define MAX_REQUEST_SIZE 1024 

void handle_request(int client_socket) {
    char buffer[MAX_REQUEST_SIZE] = {0};
    int valread = read(client_socket, buffer, MAX_REQUEST_SIZE);
    if (valread <= 0) {
        fprintf(stderr, "Failed to read from client socket\n");
        return;
    }

    const char* response = "HTTP/1.1 200 OK\nContent-Type: text/html; charset=UTF-8\n\n<!DOCTYPE html>\n<html>\n<head>\n<title>Welcome to the Castle!</title>\n</head>\n<body>\n<h1>Welcome Stranger!</h1>\n<h2>You have entered the Castle's Web Server!</h2>\n<p>The web page is still under construction.</p>\n</body>\n</html>";

    if (send(client_socket, response, strlen(response), 0) < 0) {
        fprintf(stderr, "Failed to send response to client\n");
        return;
    }

    printf("Response sent to client successfully!\n");
}

int main(int argc, char const *argv[]) { 
    int server_socket;
    int addrlen = sizeof(struct sockaddr_in);
    struct sockaddr_in address;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
        perror("Failed to set socket options");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 
    
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) { 
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) { 
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }

    printf("The Castle's Web Server is running on port %d\n", PORT);

    while (1) {
        int client_socket;
        if ((client_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) { 
            perror("Failed to accept client connection");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
        handle_request(client_socket);
        close(client_socket);
    }

    return 0; 
}