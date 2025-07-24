//FormAI DATASET v1.0 Category: Firewall ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define ALLOWED_PORTS 3
#define PROTECTED_IP "127.0.0.1"
#define BUFFER_SIZE 1024

struct Port {
    int number;
    int allowed;
};

struct IP {
    char address[BUFFER_SIZE];
    struct Port ports[ALLOWED_PORTS];
    int num_ports;
};

struct IP protected_ip;

void init_protected_ip() {
    strcpy(protected_ip.address, PROTECTED_IP);
    protected_ip.ports[0].number = 80;
    protected_ip.ports[0].allowed = 1;
    protected_ip.ports[1].number = 443;
    protected_ip.ports[1].allowed = 1;
    protected_ip.ports[2].number = 22;
    protected_ip.ports[2].allowed = 0;
    protected_ip.num_ports = ALLOWED_PORTS;
}

int is_allowed_port(int port_number) {
    for(int i = 0; i < protected_ip.num_ports; i++) {
        if(protected_ip.ports[i].number == port_number) {
            return protected_ip.ports[i].allowed;
        }
    }
    return 0;
}

void* receive_data(void* data) {
    char* receive_buffer = (char*) data;
    printf("Received data: %s\n", receive_buffer);
    return NULL;
}

void* process_connection(void* socket) {
    int* port_number = (int*) socket;
    printf("New connection on port %d\n", *port_number);
    if(is_allowed_port(*port_number)) {
        printf("Connection allowed.\n");

        char receive_buffer[BUFFER_SIZE];
        printf("Waiting for data...\n");
        scanf("%s", receive_buffer);
        pthread_t thread;
        int thread_status = pthread_create(&thread, NULL, receive_data, (void*) receive_buffer);
        if(thread_status != 0) {
            printf("Error creating thread.\n");
        }
        pthread_join(thread, NULL);
    } else {
        printf("Connection not allowed.\n");
    }
    return NULL;
}

int main() {
    init_protected_ip();

    pthread_t threads[ALLOWED_PORTS];
    int socket_numbers[ALLOWED_PORTS];

    for(int i = 0; i < protected_ip.num_ports; i++) {
        if(protected_ip.ports[i].allowed) {
            socket_numbers[i] = protected_ip.ports[i].number;
            int thread_status = pthread_create(&(threads[i]), NULL, process_connection, &(socket_numbers[i]));
            if(thread_status != 0) {
                printf("Error creating thread.\n");
            }
        } else {
            socket_numbers[i] = 0;
        }
    }

    for(int i = 0; i < protected_ip.num_ports; i++) {
        if(protected_ip.ports[i].allowed) {
            pthread_join(threads[i], NULL);
        }
    }
    
    return 0;
}