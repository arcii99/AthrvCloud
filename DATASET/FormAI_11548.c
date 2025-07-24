//FormAI DATASET v1.0 Category: Simple Web Server ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 8080

// Function to handle incoming requests
void handle_request(int clientSocket) {
    char buffer[1024] = {0};
    read(clientSocket, buffer, 1024);
    printf("%s\n", buffer);

    char response[2048] = {0};
    strcpy(response, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n");
    strcat(response, "<html><body><h1>Hello, World!</h1></body></html>\n");
    write(clientSocket, response, strlen(response));
    close(clientSocket);
}

int main(int argc, char const *argv[]) {
    int serverSocket, clientSocket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return -1;
    }

    // Attach socket to the given port
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        return -1;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to our specified IP and port
    if (bind(serverSocket, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        return -1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 3) < 0) {
        perror("listen failed");
        return -1;
    }

    printf("Server listening on port %d\n", PORT);

    // Handle incoming requests
    while(1) {
        if ((clientSocket = accept(serverSocket, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept failed");
            return -1;
        }

        handle_request(clientSocket);
    }
    return 0;
}