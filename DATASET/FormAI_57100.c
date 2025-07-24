//FormAI DATASET v1.0 Category: Networking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Define the address for the server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the specified address
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    // Start listening for incoming connections
    listen(server_socket, 5);

    // Accept incoming connections
    int client_socket = accept(server_socket, NULL, NULL);

    // Start sending love messages
    char* message = "You are the light of my life, the one that I cherish above all else.\n";
    send(client_socket, message, strlen(message), 0);
    sleep(1);

    message = "I long for every moment we spend together, and miss you dearly when we're apart.\n";
    send(client_socket, message, strlen(message), 0);
    sleep(1);

    message = "Your beauty captures my heart and soul, and I am forever yours.\n";
    send(client_socket, message, strlen(message), 0);
    sleep(1);

    message = "I love you more with every passing day, and cannot imagine my life without you.\n";
    send(client_socket, message, strlen(message), 0);
    sleep(1);

    message = "Forever and always, my love.\n";
    send(client_socket, message, strlen(message), 0);

    // Close the sockets
    close(client_socket);
    close(server_socket);

    return 0;
}