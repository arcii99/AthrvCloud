//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024
#define MAX_LOGS 100

typedef struct {
    char packet[MAX_PACKET_SIZE];
    int packet_size;
} Packet;

typedef struct {
    Packet packets[MAX_LOGS];
    int current_log;
} IDSLogs;

int detect_intrusion(Packet *p);

void log_packet(IDSLogs *logs, Packet *p);

int main(void) {
    Packet p1 = {"malicious packet", 17};
    Packet p2 = {"normal packet", 13};
    Packet p3 = {"suspicious packet", 17};
    IDSLogs logs = {0};
    
    if (detect_intrusion(&p1)) {
        printf("Intrusion detected!\n");
        log_packet(&logs, &p1);
    } else {
        printf("No intrusion detected.\n");
    }
    
    if (detect_intrusion(&p2)) {
        printf("Intrusion detected!\n");
        log_packet(&logs, &p2);
    } else {
        printf("No intrusion detected.\n");
    }
    
    if (detect_intrusion(&p3)) {
        printf("Intrusion detected!\n");
        log_packet(&logs, &p3);
    } else {
        printf("No intrusion detected.\n");
    }
    
    return 0;
}

int detect_intrusion(Packet *p) {
    int i;
    char* malicious_patterns[] = {"malicious", "hacker", "virus"};
    int num_patterns = sizeof(malicious_patterns)/sizeof(malicious_patterns[0]);
    
    for (i = 0; i < num_patterns; i++) {
        if (strstr(p->packet, malicious_patterns[i])) {
            return 1;
        }
    }
    
    return 0;
}

void log_packet(IDSLogs *logs, Packet *p) {
    if (logs->current_log == MAX_LOGS) {
        printf("IDS logs are full. Cannot log any more packets.\n");
        return;
    }
    
    logs->packets[logs->current_log] = *p;
    logs->current_log++;
}