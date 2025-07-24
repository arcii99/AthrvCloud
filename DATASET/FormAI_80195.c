//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 5050

struct sockaddr_in master_addr, worker_addr;
int worker_count = 0;

typedef struct {
    char worker_name[20];
    int mem_usage;
} Worker;

Worker workers[5];

void parse_input(char* buffer, int socket_fd) {
    int idx, usage;
    char worker_name[20];
    if (sscanf(buffer, "%s%d", worker_name, &usage) != 2) {
        send(socket_fd, "Invalid input\n", 15, 0);
        return;
    }
    for (idx = 0; idx < worker_count; idx++) {
        if (strcmp(workers[idx].worker_name, worker_name) == 0) {
            workers[idx].mem_usage = usage;
            break;
        }
    }
    if (idx == worker_count) {
        if (worker_count >= 5) {
            send(socket_fd, "Maximum worker count exceeded\n", 31, 0);
            return;
        }
        strcpy(workers[worker_count].worker_name, worker_name);
        workers[worker_count].mem_usage = usage;
        worker_count++;
    }
    send(socket_fd, "Usage recorded\n", 15, 0);
}

void report_usage(int socket_fd) {
    char buffer[100];
    int idx, len = 0;
    for (idx = 0; idx < worker_count; idx++) {
        len += sprintf(buffer + len, "%s - %dMB\n", workers[idx].worker_name, workers[idx].mem_usage);
    }
    send(socket_fd, buffer, strlen(buffer), 0);
}

int main() {
    int master_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (master_sock < 0) {
        perror("Socket creation failed\n");
        exit(1);
    }
    memset(&master_addr, 0, sizeof(master_addr));
    master_addr.sin_family = AF_INET;
    master_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    master_addr.sin_port = htons(PORT);
    if (bind(master_sock, (struct sockaddr*)&master_addr, sizeof(master_addr)) != 0) {
        perror("Socket binding failed\n");
        close(master_sock);
        exit(1);
    }
    printf("Waiting for workers to connect...\n");
    listen(master_sock, 5);
    int addrlen = sizeof(worker_addr), worker_sock, idx, opt = 1;
    char buffer[100];
    while (1) {
        worker_sock = accept(master_sock, (struct sockaddr*)&worker_addr, (socklen_t*)&addrlen);
        if (worker_sock < 0) {
            perror("Error accepting connection\n");
            continue;
        }
        printf("Received connection from %s:%d\n", inet_ntoa(worker_addr.sin_addr), ntohs(worker_addr.sin_port));
        setsockopt(worker_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
        while (1) {
            memset(buffer, 0, sizeof(buffer));
            int read_bytes = read(worker_sock, buffer, sizeof(buffer));
            if (read_bytes <= 0) {
                printf("Connection closed by worker %d\n", worker_sock);
                close(worker_sock);
                break;
            }
            if (strncmp(buffer, "quit", 4) == 0) {
                printf("Connection closed by worker %d\n", worker_sock);
                close(worker_sock);
                break;
            }
            if (strncmp(buffer, "report", 6) == 0) {
                report_usage(worker_sock);
            } else {
                parse_input(buffer, worker_sock);
            }
        }
    }
    close(master_sock);
    return 0;
}