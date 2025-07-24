//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024  //Maximum size for HTTP request/response
#define NUM_THREADS 4 //Number of threads to be used

//Function that will be executed by each thread
void *request(void *args) {
    int sock;
    struct sockaddr_in server;
    char message[MAX_SIZE], server_reply[MAX_SIZE];

    //Create socket and set server info
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        printf("Could not create socket\n");
        pthread_exit(NULL);
    }
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); //Server IP address
    server.sin_family = AF_INET;
    server.sin_port = htons(80); //Port number to connect to

    //Connect to server
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed\n");
         pthread_exit(NULL);
    }

    //Prepare HTTP request
    sprintf(message, "GET / HTTP/1.1\r\n\r\n");

    //Send HTTP request
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Request failed\n");
        pthread_exit(NULL);
    }

    //Receive response from server
    if(recv(sock, server_reply, MAX_SIZE, 0) < 0) {
        printf("Response failed\n");
        pthread_exit(NULL);
    }

    //Print server response
    printf("Server replied:\n%s\n", server_reply);

    //Close socket
    close(sock);

    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];

    printf("Starting HTTP client\n");

    //Create threads
    for(i=0; i<NUM_THREADS; i++) {
        if(pthread_create(&threads[i], NULL, request, NULL) != 0) {
            printf("Thread creation failed\n");
            return 1;
        }
    }

    //Join threads
    for(i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Exiting HTTP client\n");

    return 0;
}