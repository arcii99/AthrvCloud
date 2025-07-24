//FormAI DATASET v1.0 Category: Client Server Application ; Style: artistic
/* A creative application of Client-Server architecture */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_MSG_LENGTH 256

int main() {

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[MAX_MSG_LENGTH] = {0};
    char client_message[MAX_MSG_LENGTH] = {0};
    int choice;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server socket parameters
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to a specific address and port number
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming client connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("\033[1m"); // Bold print
    printf("\n##### Welcome to the Creative Messaging App #####\n");
    printf("##################################################\n");
    printf("Listening for incoming client connections...\n\n");
    printf("\033[0m"); // Reset print formatting

    // Wait for incoming client connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Print the client's IP address and port number
    printf("\033[1m"); // Bold print
    printf("Connection established from:\n");
    printf("\033[32;1m"); // Bright green color
    printf("IP address: %s\n", inet_ntoa(address.sin_addr));
    printf("Port number: %d\n", ntohs(address.sin_port));
    printf("\033[0m"); // Reset print formatting

    do {
        // Clear the input buffer
        memset(buffer, 0, MAX_MSG_LENGTH);

        // Receive data from the client
        valread = read(new_socket, buffer, MAX_MSG_LENGTH);

        // Print the received message
        printf("\n\033[36;1m"); // Bright cyan color 
        printf("Client: %s\n", buffer);

        // Display the menu options to the client
        printf("\n\033[35;1m"); // Bright magenta color
        printf("Menu Options:\n");
        printf("1. Reply with a funny joke\n");
        printf("2. Reply with an interesting fact\n");
        printf("3. Exit the app\n");
        printf("Enter your choice: ");
        printf("\033[0m"); // Reset print formatting

        // Get the user's menu choice
        scanf("%d", &choice);

        // Clear the input buffer
        while ((getchar()) != '\n');

        // Choose a response based on the user's menu selection
        switch (choice) {

            // Reply with a funny joke
            case 1:
                strcpy(client_message, "Why did the tomato turn red? Because it saw the salad dressing!");
                break;

            // Reply with an interesting fact
            case 2:
                strcpy(client_message, "A group of flamingos is called a flamboyance.");
                break;

            // Exit the app
            case 3:
                strcpy(client_message, "Goodbye!");
                break;

            // Invalid menu choice
            default:
                strcpy(client_message, "Invalid menu choice. Please try again.");
                break;
        }

        // Send the response to the client
        send(new_socket, client_message, strlen(client_message), 0);

    } while (choice != 3);

    // Close the server socket
    close(server_fd);

    return 0;
}