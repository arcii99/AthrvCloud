//FormAI DATASET v1.0 Category: Chat server ; Style: multi-threaded
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 

#define MAX_CONNECTIONS 5 
#define BUFFER_SIZE 1024 

int client_sockets[MAX_CONNECTIONS]; 
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER; 
char buffer[BUFFER_SIZE]; 

void* handle_client(void* client_socket) { 
    int client = *(int*)client_socket; 

    while(1) { 
        memset(buffer, 0, BUFFER_SIZE); 
        int read = recv(client, buffer, BUFFER_SIZE, 0); 
        if (read == 0) { 
            pthread_mutex_lock(&clients_mutex); 
            for (int i = 0; i < MAX_CONNECTIONS; i++) { 
                if (client_sockets[i] == client) { 
                    client_sockets[i] = -1; 
                } 
            } 
            pthread_mutex_unlock(&clients_mutex); 
            break; 
        } 
        for (int i = 0; i < MAX_CONNECTIONS; i++) { 
            if (client_sockets[i] != -1 && client_sockets[i] != client) { 
                send(client_sockets[i], buffer, strlen(buffer), 0); 
            } 
        } 
    } 

    close(client); 
    pthread_exit(NULL); 
} 

int main() { 
    int server = socket(AF_INET, SOCK_STREAM, 0); 
    if (server < 0) { 
        perror("Socket creation failed.\n"); 
        exit(1); 
    } 

    struct sockaddr_in server_address; 
    server_address.sin_family = AF_INET; 
    server_address.sin_addr.s_addr = INADDR_ANY; 
    server_address.sin_port = htons(9000); 

    if (bind(server, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) { 
        perror("Bind failed.\n"); 
        exit(1); 
    } 

    if (listen(server, MAX_CONNECTIONS) < 0) { 
        perror("Listen failed.\n"); 
        exit(1); 
    } 

    printf("Server started on port 9000.\n"); 

    pthread_t tid; 
    int i = 0; 
    while(1) { 
        struct sockaddr_in client_address; 
        socklen_t client_address_len = sizeof(client_address); 
        int client = accept(server, (struct sockaddr*)&client_address, &client_address_len); 

        pthread_mutex_lock(&clients_mutex); 
        for (i = 0; i < MAX_CONNECTIONS; i++) { 
            if (client_sockets[i] == -1) { 
                client_sockets[i] = client; 
                pthread_create(&tid, NULL, handle_client, &client); 
                pthread_detach(tid); 
                break; 
            } 
        } 
        if (i == MAX_CONNECTIONS) { 
            printf("Connection limit reached.\n"); 
            close(client); 
        } 
        pthread_mutex_unlock(&clients_mutex); 
    } 

    close(server); 
    exit(0); 
}