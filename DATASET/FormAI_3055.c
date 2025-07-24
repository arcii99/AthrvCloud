//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define PORT 8080

int main() {
    int client_socket = 0, ret_val = 0;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // create the client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        printf("Error: Could not create socket.\n");
        return -1;
    }

    // setup the server socket
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // connect to the server socket
    ret_val = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (ret_val < 0) {
        printf("Error: Could not connect to server.\n");
        return -1;
    }

    printf("Connection established.\n");

    while (1) {
        printf("> ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\r\n")] = '\0';
        
        // send the message to the server
        ret_val = send(client_socket, buffer, strlen(buffer), 0);
        if (ret_val < 0) {
            printf("Error: Send failed.\n");
            continue;
        }

        // if the user enters "exit", break the loop and exit the program
        if (strcmp(buffer, "exit") == 0) {
            printf("Exiting.\n");
            break;
        }
        
        // receive the response from the server
        memset(buffer, 0, MAX_BUFFER_SIZE);
        ret_val = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
        if (ret_val < 0) {
            printf("Error: Receive failed.\n");
            continue;
        } else if (ret_val == 0) {
            printf("Error: Connection closed by server.\n");
            break;
        }

        printf("Server response: %s\n", buffer);
    }

    close(client_socket);
    return 0;
}