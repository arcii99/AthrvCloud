//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8888
#define MAX_CONN 5
#define MAX_BUFFER 1024

int conn_fd[MAX_CONN] = {0};
pthread_t thread_id[MAX_CONN] = {0};
int curr_conn = 0;

void* handle_connection(void* socket_desc) {
    int conn = *(int*)socket_desc;
    char buffer[MAX_BUFFER] = {0};
    while(recv(conn , buffer, MAX_BUFFER, 0) > 0) {
        printf("Data received: %s\n", buffer);
        memset(buffer, 0, MAX_BUFFER);
    }
    printf("Exiting thread\n");
    close(conn);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER] = {0};
       
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
       
    // Attach socket to the port 8888
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
       
    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    // Listen for incoming connections
    if (listen(server_fd, MAX_CONN) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Server started listening on port %d...\n", PORT);
       
    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            continue;
        }
        if(curr_conn == MAX_CONN) {
            printf("Maximum number of connections reached!\nClosing new socket...\n");
            close(new_socket);
            continue;
        }
        conn_fd[curr_conn] = new_socket;
        if(pthread_create(&thread_id[curr_conn], NULL, handle_connection, (void*)&conn_fd[curr_conn]) < 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
        curr_conn++;
    }
    
    // Close all open connections
    for(int i=0; i<MAX_CONN; i++) {
        if(conn_fd[i] > 0) {
            close(conn_fd[i]);
            pthread_join(thread_id[i], NULL);
        } 
    }

    return EXIT_SUCCESS;
}