//FormAI DATASET v1.0 Category: System administration ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SERVER_NUM 5
#define MAX_CPU_USAGE 100
#define MAX_RAM_USAGE 8192

typedef struct server {
    int id;
    float cpu_usage;
    int ram_usage;
    int is_online;
} Server;

void print_server_stats(Server* server) {
    printf("Server %d:\n", server->id);
    printf("CPU Usage: %.2f%%\n", server->cpu_usage);
    printf("RAM Usage: %d MB\n", server->ram_usage);
    if (server->is_online) {
        printf("Status: Online\n");
    } else {
        printf("Status: Offline\n");
    }
    printf("\n");
}

int main() {
    Server servers[SERVER_NUM];
    srand(time(NULL));

    for (int i = 0; i < SERVER_NUM; i++) {
        servers[i].id = i+1;
        servers[i].cpu_usage = (float) (rand() % (MAX_CPU_USAGE + 1)) / 100;
        servers[i].ram_usage = rand() % (MAX_RAM_USAGE + 1);
        servers[i].is_online = rand() % 2;     
    }

    int online_servers = 0;
    int offline_servers = 0;
    int overused_servers = 0;

    printf("Server Statistics:\n");
    for (int i = 0; i < SERVER_NUM; i++) {
        print_server_stats(&servers[i]);
        if (servers[i].is_online) {
            online_servers++;
            if (servers[i].cpu_usage > 0.8 || servers[i].ram_usage > 6144) {
                overused_servers++;
            }
        } else {
            offline_servers++;
        }
    }

    printf("Total number of servers: %d\n", SERVER_NUM);
    printf("Online servers: %d\n", online_servers);
    printf("Offline servers: %d\n", offline_servers);
    printf("Overused servers: %d\n", overused_servers);

    return 0;
}