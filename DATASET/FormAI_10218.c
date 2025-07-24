//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    // Define constants for the port and server IP address
    const int PORT = 5000;
    const char *SERVER_IP = "127.0.0.1";

    struct sockaddr_in server_address;

    // Create a socket for the client
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_address.sin_port = htons(PORT);

    // Connect to the server
    int connection_status = connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    if (connection_status < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send requests to the server and measure the response time
    double total_time = 0.0;
    int requests=20;

    for (int i = 1; i <= requests; i++) {
        clock_t start_time = clock();

        char *message = "Hello, server!";
        send(client_socket, message, strlen(message), 0);

        char server_response[256];
        recv(client_socket, &server_response, sizeof(server_response), 0);

        clock_t end_time = clock();

        double response_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

        printf("Response time for request %d: %f seconds\n", i, response_time);

        total_time += response_time;
        sleep(1); // delay for 1 second
    }

    // Calculate the average response time and display it to the user
    double average_time = total_time / requests;
    printf("Average response time: %f seconds\n", average_time);

    // Close the socket and exit the program
    close(client_socket);
    return 0;
}