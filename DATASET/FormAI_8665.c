//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main() {
    // Puzzle Time
    printf("\n");

    // Step 1: Create Socket
    int client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // Step 2: Define the server address
    struct sockaddr_in server_address;
    memset(&server_address, '\0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_aton("127.0.0.1", &server_address.sin_addr);

    // Step 3: Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) != 0) {
        printf("Couldn't connect to server!\n");
        printf("\n");
        return -1;
    }

    // Step 4: Get user input
    char request[BUFFER_SIZE] = {0};
    printf("Enter the URL: ");
    fgets(request, BUFFER_SIZE, stdin);

    // Step 5: Send the request
    send(client_socket, request, strlen(request), 0);

    // Step 6: Receive and display the response
    char response[BUFFER_SIZE] = {0};
    recv(client_socket, response, BUFFER_SIZE, 0);
    printf("Server Response:\n%s\n", response);

    // Step 7: Close the connection
    close(client_socket);

    return 0;
}