//FormAI DATASET v1.0 Category: Firewall ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_IP_LENGTH 15
#define MAX_RULE_LENGTH 50

// Struct to store each rule
typedef struct {
    char ip[MAX_IP_LENGTH];
    char action[10];
} rule;

// Array of rules and its count
rule firewall_rules[100];
int firewall_rules_count = 0;

// Function to add a rule to the firewall
void add_rule(char* ip, char* action) {
    strcpy(firewall_rules[firewall_rules_count].ip, ip);
    strcpy(firewall_rules[firewall_rules_count].action, action);
    firewall_rules_count++;
}

// Function to check if a given IP is allowed or blocked based on the firewall rules
bool check_ip(char* ip) {
    for(int i = 0; i < firewall_rules_count; i++) {
        if(strncmp(ip, firewall_rules[i].ip, strlen(firewall_rules[i].ip)) == 0) {
            if(strcmp(firewall_rules[i].action, "block") == 0) {
                return false;
            } else {
                return true;
            }
        }
    }
    return true;
}

// Main function to handle incoming connections
void* handle_connection(void* arg) {
    int connfd = *(int*)arg;
    char buffer[MAX_RULE_LENGTH];
    char temp_ip[MAX_IP_LENGTH];
    char* action;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    getpeername(connfd, (struct sockaddr*)&addr, &addr_len);
    inet_ntop(AF_INET, &addr.sin_addr, temp_ip, MAX_IP_LENGTH);
    if(check_ip(temp_ip)) {
        printf("Connection accepted from IP address: %s\n", temp_ip);
        write(connfd, "Connection accepted.\n", strlen("Connection accepted.\n"));
    } else {
        printf("Connection blocked from IP address: %s\n", temp_ip);
        write(connfd, "Connection blocked.\n", strlen("Connection blocked.\n"));
        close(connfd);
        pthread_exit(NULL);
    }
    memset(buffer, 0, MAX_RULE_LENGTH);
    read(connfd, buffer, MAX_RULE_LENGTH);
    printf("Received data: %s", buffer);
    close(connfd);
    pthread_exit(NULL);
}

int main() {
    int sockfd, connfd;
    pthread_t thread_id;
    struct sockaddr_in addr;

    // Add firewall rules
    add_rule("10.0.0.1", "block");
    add_rule("192.168.0.10", "allow");

    // Setup socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error creating socket.");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if(bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("Error binding socket.");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(sockfd, 10) < 0) {
        perror("Error listening on socket.");
        exit(EXIT_FAILURE);
    }

    printf("Firewall started. Listening on port 8080...\n");

    while(true) {
        connfd = accept(sockfd, (struct sockaddr*)NULL, NULL);
        if(connfd < 0) {
            perror("Error accepting connection.");
            continue;
        }
        pthread_create(&thread_id, NULL, handle_connection, (void*)&connfd);
        pthread_detach(thread_id);
    }

    close(sockfd);
    return 0;
}