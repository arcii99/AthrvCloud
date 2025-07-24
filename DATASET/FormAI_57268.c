//FormAI DATASET v1.0 Category: Chat server ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10

typedef struct {
    int client_socket;
    struct sockaddr_in client_address;
    char username[32];
} client_info_t;

client_info_t client_infos[MAX_CLIENTS];
int client_count;

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char username[32];
    recv(sock, username, sizeof(username), 0);
    strcpy(client_infos[client_count - 1].username, username);
    char message[256];
    while (1) {
        int recv_size = recv(sock, message, sizeof(message), 0);
        if (recv_size == 0) {
            printf("%s disconnected.\n", username);
            break;
        }
        message[recv_size] = '\0';
        printf("%s: %s", username, message);
        // Send message to all other clients
        for (int i = 0; i < client_count; i++) {
            if (client_infos[i].client_socket != sock)
                send(client_infos[i].client_socket, message, strlen(message), 0);
        }
    }
    close(sock);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Could not create socket.\n");
        return 1;
    }
    // Bind socket to port 12345
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(12345);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Could not bind socket.\n");
        return 1;
    }
    listen(server_socket, 1);
    printf("Server listening on port %d.\n", ntohs(server_address.sin_port));
    // Accept incoming connections
    pthread_t threads[MAX_CLIENTS];
    int thread_count = 0;
    while (1) {
        client_infos[client_count].client_socket = accept(server_socket, (struct sockaddr *)&client_infos[client_count].client_address, (socklen_t*)&client_infos[client_count].client_address);
        send(client_infos[client_count].client_socket, "Enter your username: ", strlen("Enter your username: "), 0);
        pthread_create(&threads[thread_count], NULL, handle_client, (void *)&client_infos[client_count].client_socket);
        thread_count++;
        client_count++;
        if (client_count == MAX_CLIENTS) {
            printf("Maximum clients reached.\n");
            break;
        }
    }
    // Wait for all threads to finish
    for (int i = 0; i < thread_count; i++)
        pthread_join(threads[i], NULL);
    close(server_socket);
    return 0;
}