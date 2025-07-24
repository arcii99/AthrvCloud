//FormAI DATASET v1.0 Category: Temperature monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8888
#define MAX_CLIENTS 5

void* connection_handler(void*);
void signal_handler(int);

int main(int argc, char* argv[]){
    int server_fd, client_fd, opt=1;
    socklen_t address_length;
    struct sockaddr_in server_address, client_address;

    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
        &opt, sizeof(opt))){
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if(bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if(listen(server_fd, MAX_CLIENTS) < 0){
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, signal_handler);

    while(1){
        printf("Waiting for incoming connections...\n");
        address_length = sizeof(client_address);

        if((client_fd = accept(server_fd, (struct sockaddr*)&client_address,
            &address_length)) < 0){
            perror("accept failed");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr),
            ntohs(client_address.sin_port));

        pthread_t thread_id;
        if(pthread_create(&thread_id, NULL, connection_handler, (void*)&client_fd) < 0){
            perror("thread creation failed");
            continue;
        }
        pthread_detach(thread_id);
    }
    return 0;
}

void* connection_handler(void* socket_descriptor){
    int client_fd = *(int*)socket_descriptor;
    char message[1024];
    ssize_t read_value;

    while((read_value = read(client_fd, message, sizeof(message))) > 0){
        message[read_value] = '\0';
        printf("Message from client: %s", message);

        float temperature = atof(message);
        if(temperature <= 20){
            printf("Temperature below threshold, sending alert to server...\n");
            char alert_message[] = "Temperature too low!";
            send(client_fd, alert_message, strlen(alert_message), 0);
        }
        else if(temperature >= 30){
            printf("Temperature above threshold, sending alert to server...\n");
            char alert_message[] = "Temperature too high!";
            send(client_fd, alert_message, strlen(alert_message), 0);
        }
    }

    if(read_value == 0){
        printf("Client disconnected\n");
    }
    else{
        perror("read failed");
    }

    close(client_fd);
    return NULL;
}

void signal_handler(int signal_number){
    printf("Closing server...\n");
    exit(0);
}