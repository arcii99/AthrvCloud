//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: optimized
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>

#define MAX_TIME 300 // Time in seconds for the program to run
#define MAX_TARGETS 10 // Maximum number of targets to monitor

// Function to handle interrupts and exit program gracefully
void handle_interrupt(int signum) {
    printf("\nStopping the program...\n");
    exit(0);
}

// Function to check if a website is up or down
int check_website(char *website) {
    struct sockaddr_in server;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_addr.s_addr = inet_addr(website);
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        close(sock);
        return 0;
    } else {
        close(sock);
        return 1;
    }
}

int main(int argc, char *argv[]) {
    // Register interrupt handler
    signal(SIGINT, handle_interrupt);
    // Check if no targets were specified
    if(argc <= 1) {
        printf("Usage: website-uptime-monitor website1.com website2.com ...\n");
        return 0;
    }
    // Initialize targets array
    char* targets[MAX_TARGETS];
    for(int i = 0; i < argc - 1 && i < MAX_TARGETS; i++) {
        targets[i] = argv[i+1];
    }
    // Print message and start monitoring
    printf("Monitoring %d websites...\n", argc - 1);
    int count = 0;
    while(count < MAX_TIME) {
        for(int i = 0; i < argc - 1 && i < MAX_TARGETS; i++) {
            printf("%s - ", targets[i]);
            if(check_website(targets[i])) {
                printf("UP\n");
            } else {
                printf("DOWN\n");
            }
        }
        sleep(10); // Sleep for 10 seconds between checks
        count += 10;
    }
    printf("Program run time exceeded, exiting...\n");
    return 0;
}