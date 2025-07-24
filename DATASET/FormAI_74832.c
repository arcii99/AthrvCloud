//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    long double start_time, end_time;
    struct timeval start, end;
    gettimeofday(&start, NULL);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    int n = 0, count = 0;
    char text[512];
    for (int i = 0; i < 512; i++) {
        text[i] = rand() % 256;
    }

    start_time = clock();
    gettimeofday(&start, NULL);

    while (count <= 10) {
        n = send(sock, text, strlen(text), MSG_NOSIGNAL);
        count++;
    }
    
    end_time = clock();
    gettimeofday(&end, NULL);

    printf("Total time taken: %Lf seconds\n", (end_time - start_time) / CLOCKS_PER_SEC);
    printf("Time taken by send: %ld microseconds\n", ((end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec));
    return 0;
}