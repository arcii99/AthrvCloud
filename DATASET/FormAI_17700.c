//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>

#define SERVER "www.google.com"
#define PORT 80
#define MESSAGE_SIZE 1024

int main(int argc, char *argv[]) {

    // Define variables
    struct hostent *he;
    struct sockaddr_in server;
    int sock;
    clock_t start, end;
    double time_taken;
    char message[MESSAGE_SIZE + 1];
    memset(message, 0, sizeof(message));

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Get host name
    he = gethostbyname(SERVER);
    if (he == NULL) {
        fprintf(stderr, "Could not resolve host %s\n", SERVER);
        return 1;
    }

    // Set server
    server.sin_addr = *((struct in_addr *) he->h_addr);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        return 1;
    }

    // Preparation for sending http request
    sprintf(message, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", SERVER);

    printf("Running internet speed test...\n");

    // Start timer
    start = clock();

    // Send http request
    if (send(sock, message, strlen(message), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive http response and calculate time taken
    do {
        end = clock();
        time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    } while (recv(sock, message, MESSAGE_SIZE, MSG_DONTWAIT) > 0);

    printf("Test completed in %.2f seconds.\n", time_taken);

    // Calculate download speed
    double download_speed = ((double)MESSAGE_SIZE / time_taken) / 1000000;
    printf("Download speed: %.2f Mbps\n", download_speed);

    // Close socket
    close(sock);

    return 0;
}