//FormAI DATASET v1.0 Category: Client Server Application ; Style: artistic
/**
 * Title: The Paint Sharing App
 * Description: This program allows clients to share their paintings with each other
 *              through a client-server architecture.
 * Developer: [your name here]
 * Date: [current date]
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 5555
#define MAX_CLIENTS 5
#define MAX_BUFFER 1024

struct client {
    int sockfd;
    char name[20];
};

struct room {
    struct client clients[MAX_CLIENTS];
    int num_clients;
};

struct room rooms[MAX_CLIENTS];
int num_rooms = 0;

void handle_connection(int sockfd);
void handle_client(struct client cl);
void send_msg_all_clients(char *msg, int room_no, int sender_sockfd);
void *thread_handler(void *room_no_ptr);

int main() {
    int server_sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        printf("Failed to create socket");
        return 1;
    }
    printf("Socket created\n");

    // Prepare server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to bind socket");
        close(server_sockfd);
        return 1;
    }
    printf("Socket binded to %d\n", PORT);

    // Listen for connections
    if (listen(server_sockfd, MAX_CLIENTS) == -1) {
        printf("Failed to listen");
        close(server_sockfd);
        return 1;
    }
    printf("Listening...\n");

    // Wait for connections and handle them
    while (1) {
        int client_sockfd;
        struct sockaddr_in client_addr;
        int client_addr_len = sizeof(client_addr);

        // Accept connection
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            printf("Failed to accept connection");
            continue;
        }
        printf("Connection accepted\n");

        // Handle connection in a new thread
        handle_connection(client_sockfd);
    }

    close(server_sockfd);
    return 0;
}

void handle_connection(int sockfd) {
    char name[20];
    struct client cl;

    // Get client name
    if (recv(sockfd, name, 20, 0) == -1) {
        printf("Failed to get client name");
        return;
    }

    // Save client info
    cl.sockfd = sockfd;
    strcpy(cl.name, name);

    // Add client to a room or create a new room
    if (num_rooms == 0 || rooms[num_rooms-1].num_clients == MAX_CLIENTS) {
        struct room new_room;
        new_room.clients[0] = cl;
        new_room.num_clients = 1;
        rooms[num_rooms] = new_room;
        num_rooms++;
    } else {
        rooms[num_rooms-1].clients[rooms[num_rooms-1].num_clients] = cl;
        rooms[num_rooms-1].num_clients++;
    }

    // Send room number to client
    if (send(sockfd, &num_rooms, sizeof(int), 0) == -1) {
        printf("Failed to send room number");
        return;
    }

    // Handle client
    handle_client(cl);
}

void handle_client(struct client cl) {
    char buffer[MAX_BUFFER];

    while (1) {
        // Receive message from client
        int msg_len = recv(cl.sockfd, buffer, MAX_BUFFER, 0);
        if (msg_len == -1) {
            printf("Failed to receive message from client");
            continue;
        }

        // End connection if message is empty
        if (msg_len == 0) {
            printf("%s has disconnected\n", cl.name);
            close(cl.sockfd);
            break;
        }

        // Send message to all clients in the room except the sender
        send_msg_all_clients(buffer, num_rooms-1, cl.sockfd);
    }
}

void send_msg_all_clients(char *msg, int room_no, int sender_sockfd) {
    int num_clients = rooms[room_no].num_clients;
    struct client *clients = rooms[room_no].clients;

    // Create thread for each client except the sender
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].sockfd != sender_sockfd) {
            pthread_t tid;
            int err = pthread_create(&tid, NULL, thread_handler, &clients[i]);
            if (err != 0) {
                printf("Failed to create thread");
            }
        }
    }
}

void *thread_handler(void *client_ptr) {
    struct client *cl_ptr = (struct client *)client_ptr;
    char *msg = "Your friend has shared a painting!";

    // Send message to client
    if (send(cl_ptr->sockfd, msg, strlen(msg), 0) == -1) {
        printf("Failed to send message to client");
    }

    pthread_exit(NULL);
}