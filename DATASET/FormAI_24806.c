//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000
#define BUF_SIZE 10000000 // 10 MB

int main() {
    struct sockaddr_in server_address;
    char buffer[BUF_SIZE];
    int socket_fd, bytes_sent, bytes_received, packet_size;

    // create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(1);
    }

    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // convert IP addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Error converting IP address");
        exit(1);
    }

    // connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    // send packets of increasing size and measure the time taken for each packet
    for (packet_size=1000; packet_size<=BUF_SIZE; packet_size+=1000) {
        printf("Sending packet of size %d bytes\n", packet_size);

        // generate random buffer
        srand(time(NULL));
        for (int i=0; i<packet_size; i++) {
            buffer[i] = rand() % 256;
        }

        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);

        // send packet
        bytes_sent = send(socket_fd, buffer, packet_size, 0);
        if (bytes_sent == -1) {
            perror("Error sending packet");
            exit(1);
        }

        // receive packet
        bytes_received = recv(socket_fd, buffer, packet_size, 0);
        if (bytes_received == -1) {
            perror("Error receiving packet");
            exit(1);
        }

        gettimeofday(&end_time, NULL);

        // calculate time taken to send and receive packet
        double time_taken = (end_time.tv_sec - start_time.tv_sec)
                + (double)(end_time.tv_usec - start_time.tv_usec) / (double)1000000;

        double speed = ((bytes_sent + bytes_received) * 8) / (time_taken * (double)1000000);

        printf("Time taken: %.3f s, Speed: %.3f Mbps\n", time_taken, speed);
    }

    close(socket_fd);

    return 0;
}