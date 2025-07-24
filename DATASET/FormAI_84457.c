//FormAI DATASET v1.0 Category: Chat server ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>

#define MAX_CLIENTS 15
#define BUFFER_SIZE 1024

int client_count = 0;
int client_sockets[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void send_message(char *message, int current_socket){
    pthread_mutex_lock(&mutex);
    for(int i=0; i<client_count; i++){
        if(client_sockets[i] != current_socket){
            write(client_sockets[i], message, strlen(message));
        }
    }
    pthread_mutex_unlock(&mutex);
}

void *handle_client(void *arg){
    int current_socket = *((int *) arg);
    char buffer[BUFFER_SIZE];
    while(1){
        bzero(buffer, BUFFER_SIZE);
        int read_bytes = read(current_socket, buffer, BUFFER_SIZE);
        if(read_bytes <= 0){
            pthread_mutex_lock(&mutex);
            for(int i=0; i<client_count; i++){
                if(client_sockets[i] == current_socket){
                    client_sockets[i] = client_sockets[client_count-1];
                    client_count--;
                    break;
                }
            }
            pthread_mutex_unlock(&mutex);
            close(current_socket);
            pthread_exit(NULL);
        }
        send_message(buffer, current_socket);
    }
}

int main(){
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    pthread_t client_threads[MAX_CLIENTS];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1){
        printf("Error: Cannot create server socket.\n");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1){
        printf("Error: Cannot bind server socket.\n");
        exit(1);
    }

    if(listen(server_socket, MAX_CLIENTS) == -1){
        printf("Error: Cannot listen on server socket.\n");
        exit(1);
    }

    printf("Server started and is listening on port 9001...\n");

    while(1){
        socklen_t client_address_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if(client_socket == -1){
            printf("Error: Cannot accept client connection.\n");
            continue;
        }
        if(client_count == MAX_CLIENTS){
            printf("Error: Too many clients.\n");
            close(client_socket);
            continue;
        }
        client_sockets[client_count++] = client_socket;
        pthread_create(&client_threads[client_count-1], NULL, handle_client, &client_sockets[client_count-1]);
    }

    close(server_socket);
    return 0;
}