//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define STAT_INTERVAL 5

struct client {
        int socket;
        char client_ip[INET_ADDRSTRLEN];
        time_t last_request;
};

int clients_count = 0;
struct client clients[MAX_CLIENTS];

void remove_client(int client_index) {
        close(clients[client_index].socket);
        printf("[STATS] Connection closed with client %s\n", clients[client_index].client_ip);
        clients[client_index].socket = 0;
        clients[client_index].last_request = 0;
        clients_count--;
}

int main() {
        int server_socket, client_socket;
        struct sockaddr_in server_address, client_address;
        socklen_t client_address_length = sizeof(client_address);
        char buffer[BUFFER_SIZE];
        int bytes_received;

        server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket < 0) {
                perror("Server socket error");
                exit(1);
        }

        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = htonl(INADDR_ANY);
        server_address.sin_port = htons(SERVER_PORT);

        if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
                perror("Bind error");
                exit(1);
        }

        if (listen(server_socket, MAX_CLIENTS) < 0) {
                perror("Listen error");
                exit(1);
        }

        printf("[STATS] Server is listening on port %d\n", SERVER_PORT);

        while (1) {
                fd_set fds;
                FD_ZERO(&fds);
                FD_SET(server_socket, &fds);

                for (int i = 0; i < MAX_CLIENTS; i++) {
                        if (clients[i].socket != 0) {
                                FD_SET(clients[i].socket, &fds);
                        }
                }

                int activity = select(0, &fds, NULL, NULL, NULL);
                if (activity < 0) {
                        perror("Select error");
                        exit(1);
                }

                if (FD_ISSET(server_socket, &fds)) {
                        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
                        if (client_socket < 0) {
                                perror("Accept error");
                                exit(1);
                        }

                        char client_ip[INET_ADDRSTRLEN];
                        inet_ntop(AF_INET, &client_address.sin_addr, client_ip, INET_ADDRSTRLEN);

                        if (clients_count == MAX_CLIENTS) {
                                printf("[STATS] Maximum number of clients reached. Connection refused from %s\n", client_ip);
                                close(client_socket);
                        } else {
                                for (int i = 0; i < MAX_CLIENTS; i++) {
                                        if (clients[i].socket == 0) {
                                                clients[i].socket = client_socket;
                                                strcpy(clients[i].client_ip, client_ip);
                                                clients[i].last_request = time(NULL);

                                                printf("[STATS] Connection established with client %s\n", client_ip);

                                                clients_count++;
                                                break;
                                        }
                                }
                        }
                }

                time_t current_time = time(NULL);
                for (int i = 0; i < MAX_CLIENTS; i++) {
                        if (clients[i].socket != 0 && (current_time - clients[i].last_request >= STAT_INTERVAL)) {
                                send(clients[i].socket, "STATS", strlen("STATS"), 0);
                                bytes_received = recv(clients[i].socket, buffer, BUFFER_SIZE, 0);
                                if (bytes_received < 0) {
                                        printf("[STATS] Error while receiving stats from client %s", clients[i].client_ip);
                                        remove_client(i);
                                } else {
                                        buffer[bytes_received] = '\0';
                                        printf("[STATS] Stats received from client %s: %s", clients[i].client_ip, buffer);
                                        clients[i].last_request = current_time;
                                }
                        } else if (clients[i].socket != 0 && (current_time - clients[i].last_request >= (STAT_INTERVAL * 2))) {
                                printf("[STATS] Connection idle with client %s. Closing connection\n", clients[i].client_ip);
                                remove_client(i);
                        }
                }

                for (int i = 0; i < MAX_CLIENTS; i++) {
                        if (clients[i].socket != 0 && FD_ISSET(clients[i].socket, &fds)) {
                                bytes_received = recv(clients[i].socket, buffer, BUFFER_SIZE, 0);
                                if (bytes_received < 0) {
                                        printf("[STATS] Error while receiving message from client %s", clients[i].client_ip);
                                        remove_client(i);
                                } else if (bytes_received == 0) {
                                        printf("[STATS] Connection closed by client %s\n", clients[i].client_ip);
                                        remove_client(i);
                                } else {
                                        buffer[bytes_received] = '\0';
                                        printf("[STATS] Message received from client %s: %s", clients[i].client_ip, buffer);
                                        clients[i].last_request = current_time;
                                }
                        }
                }
        }

        return 0;
}