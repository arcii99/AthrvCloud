//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Test speed: Send and Receive buffer
    int i;
    double total_time = 0;
    for (i = 0; i < 1000; i++) {
        printf("Sending packet %d\n", i);
        clock_t start = clock();
        send(sock, hello, strlen(hello), 0 );
        valread = read(sock, buffer, 1024);
        clock_t end = clock();
        printf("Received %d bytes\n", valread);
        double time_taken = ((double) end - start) / CLOCKS_PER_SEC;
        total_time += time_taken;
    }

    printf("Average time taken per request: %f seconds\n", (total_time / i));

    return 0;
}