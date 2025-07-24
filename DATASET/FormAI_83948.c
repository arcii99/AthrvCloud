//FormAI DATASET v1.0 Category: Firewall ; Style: multiplayer
/*
Multiplayer Firewall program to block or allow traffic based on incoming IP addresses.
Users can enter IP addresses to be blocked or allowed.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_IP_NUM 20

int blockedIP[MAX_IP_NUM];
int allowedIP[MAX_IP_NUM];
int blockNum = 0, allowNum = 0;
pthread_mutex_t lock;

void blockIP(char *ip) {
    pthread_mutex_lock(&lock);
    blockedIP[blockNum] = inet_addr(ip);
    blockNum++;
    pthread_mutex_unlock(&lock);
}

void allowIP(char *ip) {
    pthread_mutex_lock(&lock);
    allowedIP[allowNum] = inet_addr(ip);
    allowNum++;
    pthread_mutex_unlock(&lock);
}

int isBlocked(char *ip) {
    int address = inet_addr(ip);
    for(int i=0; i<blockNum; i++) {
        if(blockedIP[i] == address) {
            return 1; //IP blocked
        }
    }
    return 0; //IP not blocked
}

int isAllowed(char *ip) {
    if(allowNum == 0) return 1; //No allowed IP list, so allow all
    int address = inet_addr(ip);
    for(int i=0; i<allowNum; i++) {
        if(allowedIP[i] == address) {
            return 1; //IP allowed
        }
    }
    return 0; //IP not allowed
}

void *connection_handler(void *socket_desc) {
    char *clientIP = (char*)socket_desc;
    
    if(isBlocked(clientIP)) {
        printf("Blocked IP %s tried to connect\n", clientIP);
        return NULL;
    }
    
    if(isAllowed(clientIP)) {
        printf("Allowed IP %s connected\n", clientIP);
    }
    else {
        printf("Unallowed IP %s tried to connect\n", clientIP);
    }
    
    return NULL;
}

int main() {
    pthread_mutex_init(&lock, NULL);
    
    //Add restricted IPs
    blockIP("192.168.0.1");
    blockIP("10.0.0.1");
    
    //Add allowed IPs
    allowIP("192.168.0.10");
    allowIP("192.168.0.20");
    
    //Simulate incoming connections
    char *ip1 = "192.168.0.1"; //Blocked IP
    char *ip2 = "192.168.0.10"; //Allowed IP
    char *ip3 = "10.0.0.2"; //Blocked IP
    char *ip4 = "192.168.0.30"; //Unallowed IP
    
    pthread_t thread[4];
    pthread_create(&thread[0], NULL, connection_handler, (void*)ip1);
    pthread_create(&thread[1], NULL, connection_handler, (void*)ip2);
    pthread_create(&thread[2], NULL, connection_handler, (void*)ip3);
    pthread_create(&thread[3], NULL, connection_handler, (void*)ip4);
    
    //Wait for all threads to complete
    for(int i=0; i<4; i++) {
        pthread_join(thread[i], NULL);
    }
    
    return 0;
}