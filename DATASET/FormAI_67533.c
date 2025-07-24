//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server_ip = argv[1];
    int server_port = 8080;

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket.");
        exit(EXIT_FAILURE);
    }

    // Set server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server_address.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server.");
        exit(EXIT_FAILURE);
    }

    // Send a request to the server
    char request[BUFFER_SIZE];
    time_t start_time = time(NULL);
    sprintf(request, "GET /measure-speed HTTP/1.1\r\nHost: %s\r\n\r\n", server_ip);
    if (write(sockfd, request, strlen(request)) < 0) {
        perror("Failed to send request to server.");
        exit(EXIT_FAILURE);
    }

    // Receive response from the server
    char response[BUFFER_SIZE];
    int bytes_received = 0;
    while (1) {
        int n = read(sockfd, response + bytes_received, BUFFER_SIZE - bytes_received);
        if (n < 0) {
            perror("Failed to receive response from server.");
            exit(EXIT_FAILURE);
        } else if (n == 0) {
            break;
        } else {
            bytes_received += n;
            if (bytes_received >= BUFFER_SIZE) {
                fprintf(stderr, "Response too large to fit in buffer.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    time_t end_time = time(NULL);

    // Parse the server response
    long long response_time;
    if (sscanf(response, "OK,%lld", &response_time) != 1) {
        fprintf(stderr, "Invalid response from server.\n");
        exit(EXIT_FAILURE);
    }

    // Calculate the speed
    double speed = (double)(BUFFER_SIZE / 1024) / response_time;

    // Print result
    printf("Your internet speed is %.2f Kbps.\n", speed);

    // Close socket
    close(sockfd);

    return 0;
}