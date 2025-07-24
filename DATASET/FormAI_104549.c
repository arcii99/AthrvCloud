//FormAI DATASET v1.0 Category: Firewall ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PACKET_SIZE 1024
#define MAX_RULE_SIZE 256
#define MAX_RULES 10

// declare a rule struct
typedef struct {
    char* src_ip;
    char* dest_ip;
    int src_port;
    int dest_port;
} Rule;

// declare a packet struct
typedef struct {
    char* src_ip;
    char* dest_ip;
    int src_port;
    int dest_port;
    char* message;
} Packet;

// declare an array of rules
Rule rules[MAX_RULES];

// add a rule to the rules array
void add_rule(char* rule_str, int index) {
    char* src_ip = strtok(rule_str, ",");
    char* dest_ip = strtok(NULL, ",");
    int src_port = atoi(strtok(NULL, ","));
    int dest_port = atoi(strtok(NULL, ","));
    
    rules[index].src_ip = src_ip;
    rules[index].dest_ip = dest_ip;
    rules[index].src_port = src_port;
    rules[index].dest_port = dest_port;
}

// check if a packet matches a rule
int check_packet(Packet packet) {
    int i;
    for (i = 0; i < MAX_RULES; i++) {
        Rule rule = rules[i];
        if (rule.src_ip != NULL && rule.dest_ip != NULL) {
            if (strcmp(packet.src_ip, rule.src_ip) == 0 &&
                strcmp(packet.dest_ip, rule.dest_ip) == 0 &&
                packet.src_port == rule.src_port &&
                packet.dest_port == rule.dest_port) {
                return 1;
            }
        }
    }
    return 0;
}

// function for handling packets
void* handle_packet(void* arg) {
    Packet packet = *(Packet*)arg;
    if (check_packet(packet)) {
        printf("Packet blocked: %s:%d -> %s:%d : %s\n",
            packet.src_ip, packet.src_port,
            packet.dest_ip, packet.dest_port,
            packet.message);
    } else {
        printf("Packet allowed: %s:%d -> %s:%d : %s\n",
            packet.src_ip, packet.src_port,
            packet.dest_ip, packet.dest_port,
            packet.message);
    }
    free(packet.src_ip);
    free(packet.dest_ip);
    free(packet.message);
    free(arg);
}

int main(int argc, char *argv[]) {
    // initialize rules
    add_rule("10.0.0.1,10.0.0.2,80,443", 0);
    add_rule("10.0.0.2,10.0.0.1,80,443", 1);
    
    // start packet threads
    pthread_t threads[MAX_PACKET_SIZE];
    int packet_count = 0;
    char line[MAX_RULE_SIZE];
    while (fgets(line, MAX_RULE_SIZE, stdin)) {
        char* src_ip = strtok(line, ",");
        char* dest_ip = strtok(NULL, ",");
        int src_port = atoi(strtok(NULL, ","));
        int dest_port = atoi(strtok(NULL, ","));
        char* message = strtok(NULL, "");
        
        Packet* packet = (Packet*)malloc(sizeof(Packet));
        packet->src_ip = strdup(src_ip);
        packet->dest_ip = strdup(dest_ip);
        packet->src_port = src_port;
        packet->dest_port = dest_port;
        packet->message = strdup(message);
        
        pthread_create(&threads[packet_count], NULL, handle_packet, packet);
        packet_count++;
    }
    
    // join packet threads
    int i;
    for (i = 0; i < packet_count; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}