//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *server_ip_address = "127.0.0.1";
    int server_port = 21;
    int client_socket;
    struct sockaddr_in server_address;
    char read_buffer[BUFFER_SIZE] = {0};
    char write_buffer[BUFFER_SIZE] = {0};
    int recv_count;
    int send_count;
    char user_input[BUFFER_SIZE] = {0};

    // Create a client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket == -1) {
        perror("Error: could not create socket");
        return EXIT_FAILURE;
    }

    // Set the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip_address);
    server_address.sin_port = htons(server_port);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error: connection failed");
        return EXIT_FAILURE;
    }

    // Receive welcome message from server
    memset(read_buffer, 0, BUFFER_SIZE);
    recv_count = read(client_socket, read_buffer, BUFFER_SIZE);
    if (recv_count < 0) {
        perror("Error: receive failed");
        return EXIT_FAILURE;
    }

    printf("\n\n%s", read_buffer);

    // Send user name to server
    printf("User name: ");
    fgets(user_input, BUFFER_SIZE, stdin);

    memset(write_buffer, 0, BUFFER_SIZE); // clear the buffer
    sprintf(write_buffer, "USER %s", user_input);
    send_count = send(client_socket, write_buffer, strlen(write_buffer), 0);

    if (send_count < 0) {
        perror("Error: send failed");
        return EXIT_FAILURE;
    }

    // Receive response from server
    memset(read_buffer, 0, BUFFER_SIZE);
    recv_count = read(client_socket, read_buffer, BUFFER_SIZE);
    if (recv_count < 0) {
        perror("Error: receive failed");
        return EXIT_FAILURE;
    }

    printf("\n\n%s", read_buffer);

    // Send password to server
    printf("Password: ");
    fgets(user_input, BUFFER_SIZE, stdin);

    memset(write_buffer, 0, BUFFER_SIZE); // clear the buffer
    sprintf(write_buffer, "PASS %s", user_input);
    send_count = send(client_socket, write_buffer, strlen(write_buffer), 0);

    if (send_count < 0) {
        perror("Error: send failed");
        return EXIT_FAILURE;
    }

    // Receive response from server
    memset(read_buffer, 0, BUFFER_SIZE);
    recv_count = read(client_socket, read_buffer, BUFFER_SIZE);
    if (recv_count < 0) {
        perror("Error: receive failed");
        return EXIT_FAILURE;
    }

    printf("\n\n%s", read_buffer);

    // User is now logged in successfully
    // We can now start sending FTP commands
    while(1) {
        printf("FTP> ");
        fgets(user_input, BUFFER_SIZE, stdin);

        // Send user input to server
        memset(write_buffer, 0, BUFFER_SIZE); // clear the buffer
        sprintf(write_buffer, "%s", user_input);
        send_count = send(client_socket, write_buffer, strlen(write_buffer), 0);

        if (send_count < 0) {
            perror("Error: send failed");
            return EXIT_FAILURE;
        }

        // Receive response from server
        memset(read_buffer, 0, BUFFER_SIZE);
        recv_count = read(client_socket, read_buffer, BUFFER_SIZE);
        if (recv_count < 0) {
            perror("Error: receive failed");
            return EXIT_FAILURE;
        }

        printf("\n%s", read_buffer);

        // Quit program if user enters quit command
        if (strcmp("quit\n", user_input) == 0) {
            break;
        }
    }

    // Close the connection
    close(client_socket);

    return EXIT_SUCCESS;
}