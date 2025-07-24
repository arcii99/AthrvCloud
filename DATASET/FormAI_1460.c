//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 5000
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    struct sockaddr_in address;
    int active;
    int latency;
} client_t;

void add_client(client_t clients[], int new_socket, struct sockaddr_in address) {
    for(int i=0; i<MAX_CLIENTS; i++) {
        if(!clients[i].active) {
            clients[i].socket = new_socket;
            clients[i].address = address;
            clients[i].active = 1;
            clients[i].latency = 0;
            return;
        }
    }
}

void remove_client(client_t clients[], int socket) {
    for(int i=0; i<MAX_CLIENTS; i++) {
        if(clients[i].socket == socket) {
            clients[i].active = 0;
            return;
        }
    }
}

void update_latency(client_t clients[], int socket, int latency) {
    for(int i=0; i<MAX_CLIENTS; i++) {
        if(clients[i].socket == socket) {
            clients[i].latency = latency;
            return;
        }
    }
}

int main(void) {
    int master_socket, new_socket, activity, max_sd;
    struct sockaddr_in address;
    client_t clients[MAX_CLIENTS];
    fd_set readfds;
    char buffer[BUFFER_SIZE];

    for(int i=0; i<MAX_CLIENTS; i++) {
        clients[i].active = 0;
        clients[i].latency = 0;
    }

    if((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if(setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if(bind(master_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if(listen(master_socket, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    puts("QoS monitor is running...");

    while(1) {
        FD_ZERO(&readfds);
        FD_SET(master_socket, &readfds);
        max_sd = master_socket;

        for(int i=0; i<MAX_CLIENTS; i++) {
            if(clients[i].active) {
                FD_SET(clients[i].socket, &readfds);
                if(clients[i].socket > max_sd) max_sd = clients[i].socket;
            }
        }

        if(select(max_sd+1, &readfds, NULL, NULL, NULL) < 0) {
            perror("select failed");
            exit(EXIT_FAILURE);
        }

        if(FD_ISSET(master_socket, &readfds)) {
            struct sockaddr_in address;
            int addrlen = sizeof(address);
            if((new_socket = accept(master_socket, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }
            add_client(clients, new_socket, address);
            printf("New client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
        }

        for(int i=0; i<MAX_CLIENTS; i++) {
            if(clients[i].active && FD_ISSET(clients[i].socket, &readfds)) {
                int bytes = 0;
                if((bytes = recv(clients[i].socket, buffer, BUFFER_SIZE, 0)) <= 0) {
                    struct sockaddr_in address = clients[i].address;
                    close(clients[i].socket);
                    remove_client(clients, clients[i].socket);
                    printf("Client disconnected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    continue;
                }
                buffer[bytes] = '\0';
                printf("%s:%d - %s\n", inet_ntoa(clients[i].address.sin_addr), ntohs(clients[i].address.sin_port), buffer);
                char response[BUFFER_SIZE] = {0};
                if(strcmp(buffer, "LATENCY") == 0) {
                    struct timespec start, end;
                    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
                    send(clients[i].socket, "PING", strlen("PING"), 0);
                    recv(clients[i].socket, response, BUFFER_SIZE, 0);
                    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
                    int milliseconds = (end.tv_sec - start.tv_sec) * 1000 +
                                       (end.tv_nsec - start.tv_nsec) / 1000000;
                    update_latency(clients, clients[i].socket, milliseconds);
                    sprintf(response, "Latency is %dms", milliseconds);
                } else if(strcmp(buffer, "PLAYERS") == 0) {
                    int num_players = 0;
                    char player_list[BUFFER_SIZE];
                    for(int j=0; j<MAX_CLIENTS; j++) {
                        if(clients[j].active) {
                            num_players++;
                            sprintf(player_list+strlen(player_list), "%s:%d - %dms latency\n",
                                    inet_ntoa(clients[j].address.sin_addr),
                                    ntohs(clients[j].address.sin_port),
                                    clients[j].latency);
                        }
                    }
                    sprintf(response, "There are currently %d players online:\n%s", num_players, player_list);
                } else {
                    sprintf(response, "Unknown command: %s", buffer);
                }
                send(clients[i].socket, response, strlen(response), 0);
            }
        }
    }

    return 0;
}