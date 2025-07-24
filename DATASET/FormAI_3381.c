//FormAI DATASET v1.0 Category: Chat server ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

void *handle_client(void *socket_desc);
void send_message(char message[], int current_client);
void add_client(int socket_desc, struct sockaddr_in address);
void remove_client(int current_client);
void broadcast(char message[], int current_client);

int clients[10];
struct sockaddr_in addresses[10];
int num_clients = 0;

int main(int argc, char const *argv[]) {

    int server_fd, client_socket_desc;
    struct sockaddr_in server_address, client_address;

    // Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting up server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and start handling them
    while(1) {
        int client_len = sizeof(client_address);
        client_socket_desc = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&client_len);

        if (client_socket_desc < 0) {
            printf("Acceptance of client failed\n");
            continue;
        }

        add_client(client_socket_desc, client_address);

        pthread_t thread_id;
        if(pthread_create(&thread_id, NULL, handle_client, &client_socket_desc) < 0) {
            printf("Could not create thread\n");
            continue;
        }
    }

    return 0;
}

void *handle_client(void *socket_desc) {
    int current_client = *(int*)socket_desc;
    char buffer[1024] = {0};

    while (1) {
        int valread = read(current_client, buffer, 1024);
        if(valread <= 0) {
            remove_client(current_client);
            close(current_client);
            break;
        }

        broadcast(buffer, current_client);
    }
}

void send_message(char message[], int current_client) {
    send(clients[current_client], message, strlen(message), 0);
}

void add_client(int socket_desc, struct sockaddr_in address) {
    addresses[num_clients] = address;
    clients[num_clients] = socket_desc;
    num_clients++;
}

void remove_client(int current_client) {
    close(clients[current_client]);
    
    for(int i = current_client; i < num_clients - 1; i++) {
        clients[i] = clients[i + 1];
        addresses[i] = addresses[i + 1];
    }

    num_clients--;
}

void broadcast(char message[], int current_client) {
    char modified_message[1024];
    strcpy(modified_message, "Your love message: ");
    strcat(modified_message, message);

    for(int i = 0; i < num_clients; i++) {
        if(i == current_client) {
            send_message(modified_message, i);
        } else {
            char broadcast_message[1024];
            char client_address[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(addresses[current_client].sin_addr), client_address, INET_ADDRSTRLEN);
            sprintf(broadcast_message, "%s says, %s", client_address, message);
            send_message(broadcast_message, i);
        }
    }
}