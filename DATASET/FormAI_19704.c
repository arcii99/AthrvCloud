//FormAI DATASET v1.0 Category: Chat server ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

int client_count = 0;
int client_socket[MAX_CLIENTS];
pthread_t thread_id[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void error(char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_msg(char *msg, int curr_client){
    pthread_mutex_lock(&mutex);

    for(int i = 0; i < client_count; i++){
        if(client_socket[i] != curr_client){
            send(client_socket[i], msg, strlen(msg), 0);
        }
    }

    pthread_mutex_unlock(&mutex);
}

void *client_handler(void *client){
    int client_socket_fd = *(int*) client;
    char username[16];
    char msg[256];

    recv(client_socket_fd, username, sizeof(username), 0);
    printf("%s has joined the chat\n", username);

    while(1){
        memset(msg, 0, sizeof(msg));
        if(recv(client_socket_fd, msg, sizeof(msg), 0) == 0){
            break;
        }
        printf("%s: %s\n", username, msg);
        send_msg(msg, client_socket_fd);
    }

    close(client_socket_fd);
    printf("%s has left the chat\n", username);

    pthread_mutex_lock(&mutex);
    for(int i = 0; i < client_count; i++){
        if(client_socket[i] == client_socket_fd){
            while(i < client_count-1){
                client_socket[i] = client_socket[i+1];
                i++;
            }
            break;
        }
    }
    client_count--;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main (){
    int server_socket_fd, valread;
    struct sockaddr_in server_address;
    char buffer[256];
    int address_len = sizeof(server_address);

    for(int i = 0; i < MAX_CLIENTS; i++){
        client_socket[i] = 0;
    }

    if((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        error("Socket creation failed.");
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if(bind(server_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0){
        error("Binding failed.");
    }

    if(listen(server_socket_fd, 3) < 0){
        error("Listening failed.");
    }

    printf("Server started on port %d\n", PORT);

    while(1){
        int client_socket_fd;
        if((client_socket_fd = accept(server_socket_fd, 
            (struct sockaddr*)&server_address, &address_len)) < 0){
            error("Failed to accept client connection.");
        }

        if(client_count >= MAX_CLIENTS){
            printf("Failed to accept new connection. Max clients reached.\n");
            close(client_socket_fd);
            continue;
        }

        client_socket[client_count] = client_socket_fd;

        if(pthread_create(&thread_id[client_count], NULL, client_handler, &client_socket[client_count]) != 0){
            printf("Failed to create thread for client.\n");
            continue;
        }

        client_count++;
    }

    for(int i = 0; i < client_count; i++){
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}