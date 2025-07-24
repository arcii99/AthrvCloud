//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void *http_request(void *arg);

int main(int argc, char **argv)
{
    char *url = "http://example.com"; // the URL to request
    int num_requests = 5; // number of requests to make
    int num_threads = 2; // number of threads to use
    pthread_t tid[num_threads]; // thread array
    int i;

    // create threads to make HTTP requests
    for (i = 0; i < num_threads; i++) {
        if (pthread_create(&tid[i], NULL, http_request, (void *)url) != 0) {
            printf("Error: Could not create thread.\n");
            exit(1);
        }
    }

    // wait for threads to finish
    for (i = 0; i < num_threads; i++) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}

void *http_request(void *arg)
{
    int sock;
    struct sockaddr_in server;
    char *url = (char *)arg;
    char request[1000] = {0};
    char response[10000] = {0};
    char *host, *path;
    int port = 80;
    int i;

    // extract host and path from URL
    host = strstr(url, "://");
    if (host == NULL) {
        printf("Error: Invalid URL.\n");
        pthread_exit(NULL);
    }
    host += 3;
    path = strchr(host, '/');
    if (path == NULL) {
        path = "/";
    }
    else {
        *path = '\0';
        path++;
    }

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: Could not create socket.\n");
        pthread_exit(NULL);
    }

    // set server details
    server.sin_addr.s_addr = inet_addr(host);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error: Could not connect to server.\n");
        pthread_exit(NULL);
    }

    // create HTTP 1.1 GET request
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: keep-alive\r\n\r\n", path, host);

    // send request to server
    if (send(sock, request, strlen(request), 0) < 0) {
        printf("Error: Could not send request.\n");
        pthread_exit(NULL);
    }

    // receive response from server
    if (recv(sock, response, sizeof(response), 0) < 0) {
        printf("Error: Could not receive response.\n");
        pthread_exit(NULL);
    }

    // close socket
    close(sock);

    // print response
    printf("Response:\n%s\n", response);

    pthread_exit(NULL);
}