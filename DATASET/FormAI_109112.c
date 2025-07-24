//FormAI DATASET v1.0 Category: Networking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    printf("Hello! Welcome to the unique networking program. \n");

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: Could not create socket \n");
        return -1;
    }

    printf("Socket created successfully! \n");

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Binding failed \n");
        return -1;
    }

    printf("Binding successful! \n");

    if (listen(sock, 3) < 0) {
        printf("Error: Listen failed \n");
        return -1;
    }

    printf("Listening for incoming connections... \n");

    int client_socket = accept(sock, NULL, NULL);
    if (client_socket < 0) {
        printf("Error: Accept failed \n");
        return -1;
    }

    printf("Connection established with client! \n");

    char message[255] = "";
    read(client_socket, message, 255);
    printf("Client Message: %s \n", message);

    char reply[255] = "Hello! Thank you for connecting.";
    write(client_socket, reply, strlen(reply));
    printf("Message sent to client! \n");

    close(sock);
    printf("Socket closed. Exiting program. \n");
    return 0;

}