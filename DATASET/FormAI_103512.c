//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 1000
#define MAX_IPS 100

typedef struct {
    char *ip;
    int count;
} ip_counter;

typedef struct {
    char *time;
    char *ip;
    char *message;
} intrusion_event;

ip_counter ips[MAX_IPS];
intrusion_event events[MAX_EVENTS];
int total_events = 0;
int total_ips = 0;

void log_event(char *time, char *ip, char *message) {
    if(total_events == MAX_EVENTS) {
        printf("WARNING: Max events reached\n");
        return;
    }

    intrusion_event e;
    e.time = time;
    e.ip = ip;
    e.message = message;

    events[total_events] = e;
    total_events++;

    for(int i = 0; i < total_ips; i++) {
        if(strcmp(ip, ips[i].ip) == 0) {
            ips[i].count++;
            return;
        }
    }

    ip_counter c;
    c.ip = ip;
    c.count = 1;
    ips[total_ips] = c;
    total_ips++;
}

int main() {
    log_event("12:05:01", "192.168.1.100", "Unauthorized access attempt");
    log_event("12:05:03", "192.168.1.101", "System compromise detected");
    log_event("12:05:07", "192.168.1.102", "Brute-force attack in progress");

    printf("Intrusion events:\n");
    for(int i = 0; i < total_events; i++) {
        printf("%s %s %s\n", events[i].time, events[i].ip, events[i].message);
    }

    printf("IPs with most events:\n");
    for(int i = 0; i < total_ips; i++) {
        printf("%s %d\n", ips[i].ip, ips[i].count);
    }

    return 0;
}