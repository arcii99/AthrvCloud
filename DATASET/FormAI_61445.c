//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

// Define surrealistic macros for IMAP commands
#define OPEN_DOOR(email_address, password) printf("Opening door to %s with password %s...\n", email_address, password);
#define WALK_IN printf("Walking in...\n");
#define SAY_HELLO printf("Saying hello...\n");
#define CHECK_MESSAGES printf("Checking messages...\n");

// Define surrealistic macros for server responses
#define DOOR_CREAKS printf("The door creaks open...\n");
#define WARM_WELCOME printf("A warm welcome awaits you...\n");
#define MESSAGES_AWAIT printf("You have messages waiting...\n");

int main(int argc, char *argv[]) {
    // Check for command line arguments
    if (argc != 3) {
        printf("Usage: imap-client <email-address> <password>\n");
        exit(EXIT_FAILURE);
    }
    
    // Set up socket connection
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(143);

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("ERROR: Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("ERROR: Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    // Open door to email account
    OPEN_DOOR(argv[1], argv[2]);
    DOOR_CREAKS;

    // Walk in and say hello
    WALK_IN;
    SAY_HELLO;

    // Check for messages
    CHECK_MESSAGES;

    // Receive response from server
    char buffer[MAX_BUFFER_SIZE];
    read(socket_fd, buffer, MAX_BUFFER_SIZE);
    printf("%s\n", buffer);

    // Get messages
    MESSAGES_AWAIT;

    // Close connection
    close(socket_fd);
    printf("Connection closed.\n");

    return 0;
}