//FormAI DATASET v1.0 Category: Chat server ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8888

void *handle_client(void *sock_addr) {
    int sock_fd = *(int*)sock_addr;
    char buffer[1024];
    int read_len;
    
    while((read_len = read(sock_fd, buffer, 1024)) > 0) {
        buffer[read_len] = '\0';
        printf("Client sent: %s\n", buffer);
        write(sock_fd, buffer, strlen(buffer));
    }
    
    close(sock_fd);
    printf("Client disconnected\n");
    pthread_exit(NULL);
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    pthread_t thread_id;
    
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Failed to create socket");
        exit(1);
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to bind socket to port %d", PORT);
        exit(1);
    }
    
    if(listen(server_fd, 10) == -1) {
        printf("Failed to listen for clients");
        exit(1);
    }
    
    printf("Chat server running on port %d...\n", PORT);
    
    while(1) {
        socklen_t client_addr_len = sizeof(client_addr);
        
        if((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len)) == -1) {
            printf("Failed to accept client connection");
            continue;
        }
        
        printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));
        
        if(pthread_create(&thread_id, NULL, handle_client, (void *)&client_fd) != 0) {
            printf("Failed to create thread for client");
            continue;
        }
        
        pthread_detach(thread_id);
    }
    
    return 0;
}