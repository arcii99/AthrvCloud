//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <poll.h>

#define MAX_SOCKETS 1024
#define MAX_BUFFER_SIZE 8192

struct client{
    int socket;
    struct sockaddr_in address;
    int active;
    long last_packet_time;
};

struct client clients[MAX_SOCKETS];

void init_clients(){
    for(int i=0; i<MAX_SOCKETS; i++){
        clients[i].socket = -1;
        clients[i].active = 0;
        clients[i].last_packet_time = 0;
    }
}

void process_client(int index, char *buffer, int length){
    printf("Processing client at index %d\n", index);
    // Implement your QoS monitoring logic here
    // This could involve checking packet loss, latency, etc.
}

int main(int argc, char *argv[]){
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0){
        printf("Failed to create socket\n");
        return 1;
    }

    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0){
        printf("Failed to bind socket\n");
        return 1;
    }

    if(listen(server_socket, 5) < 0){
        printf("Failed to listen\n");
        return 1;
    }

    printf("Server is listening on port 8080...\n");

    init_clients();

    struct pollfd file_descriptors[MAX_SOCKETS+1];
    memset(file_descriptors, 0, sizeof(file_descriptors));
    file_descriptors[0].fd = server_socket;
    file_descriptors[0].events = POLLIN;

    while(1){
        int active_clients = 0;
        for(int i=0; i<MAX_SOCKETS; i++){
            if(clients[i].socket != -1){
                active_clients++;
                file_descriptors[active_clients].fd = clients[i].socket;
                file_descriptors[active_clients].events = POLLIN;
            }
        }
        int total_descriptors = active_clients + 1;

        poll(file_descriptors, total_descriptors, 500);

        if(file_descriptors[0].revents & POLLIN){
            int client_socket = accept(server_socket, NULL, NULL);
            int i;
            for(i=0; i<MAX_SOCKETS; i++){
                if(clients[i].socket == -1){
                    clients[i].socket = client_socket;
                    clients[i].active = 1;
                    clients[i].last_packet_time = time(NULL);
                    char welcome_message[] = "Welcome to the server!";
                    send(client_socket, welcome_message, strlen(welcome_message), 0);
                    break;
                }
            }
            if(i == MAX_SOCKETS){
                printf("Too many clients\n");
                close(client_socket);
                continue;
            }
        }

        for(int i=0; i<active_clients; i++){
            if(file_descriptors[i+1].revents & POLLIN){
                int index = -1;
                for(int j=0; j<MAX_SOCKETS; j++){
                    if(clients[j].socket == file_descriptors[i+1].fd){
                        index = j;
                        break;
                    }
                }
                if(index == -1){
                    printf("Client socket not found\n");
                    continue;
                }

                char buffer[MAX_BUFFER_SIZE];
                memset(buffer, 0, MAX_BUFFER_SIZE);
                int result = recv(clients[index].socket, buffer, MAX_BUFFER_SIZE, 0);
                if(result == 0){
                    printf("Client at index %d has disconnected\n", index);
                    close(clients[index].socket);
                    clients[index].socket = -1;
                    clients[index].active = 0;
                }
                else{
                    printf("Received data from client at index %d. Length: %d\n", index, result);
                    clients[index].last_packet_time = time(NULL);
                    process_client(index, buffer, result);
                }
            }
        }
    }

    return 0;
}