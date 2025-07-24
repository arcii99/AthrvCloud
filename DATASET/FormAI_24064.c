//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    // Initialize variables
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    // Set server details
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert address to binary
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Generate random data to send to server
    char data[BUFFER_SIZE] = {0};
    srand(time(NULL));
    for (int i = 0; i < BUFFER_SIZE; i++) {
        data[i] = rand();
    }

    // Start timer
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Send data to server
    send(sock, data, sizeof(data), 0);

    // Receive response from server
    valread = read(sock, buffer, BUFFER_SIZE);

    // End timer
    gettimeofday(&end, NULL);

    // Calculate time difference
    double time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;

    // Calculate transfer rate
    double transfer_rate = ((double)BUFFER_SIZE / time_taken) / 1048576;

    // Print results
    printf("Transfer Rate: %.2f MB/s\n", transfer_rate);

    return 0;
}