//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8888

int main(int argc, char const *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Failed to create socket!");
        return -1;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address
    if(bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to bind socket!");
        return -1;
    }

    // Listen for incoming connections
    if(listen(server_socket, 3) < 0) { // 3 is the maximum number of queued connections
        printf("Failed to listen for incoming connections!");
        return -1;
    }

    printf("Listening for incoming connections...\n");

    while(1) {
        int addr_size = sizeof(client_addr);

        // Accept incoming connection
        if((client_socket = accept(server_socket, (struct sockaddr*)&client_addr, (socklen_t*)&addr_size)) < 0) {
            printf("Failed to accept incoming connection!");
            return -1;
        }

        printf("Incoming connection accepted!\n");

        // Read data from client
        int valread = read(client_socket, buffer, BUFFER_SIZE);

        if(valread > 0) {
            printf("Received %d bytes of data from client:\n%s\n", valread, buffer);

            // Process data
            char *response = "Hello from server!";
            int data_len = strlen(response);

            // Send data back to client
            if(send(client_socket, response, data_len, 0) < 0) {
                printf("Failed to send data to client!");
                return -1;
            }

            printf("Response sent to client!\n");
        }

        // Close client socket
        close(client_socket);
        printf("Client connection closed.\n");
    }

    // Close server socket
    close(server_socket);

    return 0;
}