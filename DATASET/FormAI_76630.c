//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Alan Touring
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define PORT 8080
#define BUFFER_SIZE 1048576

// Function to calculate speed in KB/s
float calculate_speed(clock_t start, clock_t end, int bytes_received) {
    float speed = ((float) bytes_received / (end - start)) * CLOCKS_PER_SEC / 1024.0;
    return speed;
}

int main(int argc, char const *argv[]) {
    struct sockaddr_in server_address;
    int sock = 0, bytes_received = 0;
    char buffer[BUFFER_SIZE] = {0};
    clock_t start, end;
    float speed;

    // Create socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        printf("\n Invalid address/ Address not supported \n");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("\n Connection Failed \n");
        return -1;
    }

    // Start timer
    start = clock();

    // Receive data from server in chunks of BUFFER_SIZE bytes
    while ((bytes_received = read(sock, buffer, BUFFER_SIZE)) > 0);

    // Stop timer
    end = clock();

    // Calculate speed
    speed = calculate_speed(start, end, bytes_received);

    printf("Internet Speed: %.2f KB/s\n", speed);

    return 0;
}