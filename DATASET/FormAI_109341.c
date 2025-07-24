//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>

#define BUFSIZE 1024
#define PORT 8080

void *access_resource(void *arg) {
    // asynchronous function to access a resource
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZE];
    int sockfd, n;
    char *message = "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n";

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    // send HTTP request to the server
    send(sockfd, message, strlen(message), 0);

    // receive the server's response
    while ((n = recv(sockfd, buffer, BUFSIZE, 0)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, BUFSIZE);
    }

    if (n < 0) {
        perror("Socket reading error");
        exit(EXIT_FAILURE);
    }

    return NULL;
}

int main() {
    pthread_t tid;
    int i;

    for (i = 0; i < 10; i++) {
        // access the resource asynchronously using threads
        pthread_create(&tid, NULL, access_resource, NULL);

        // wait a random amount of time between requests
        srand(time(NULL));
        usleep((rand() % 100) * 1000);
    }

    pthread_exit(NULL);
}