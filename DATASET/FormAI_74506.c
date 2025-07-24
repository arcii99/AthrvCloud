//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALERTS 100

typedef struct {
    char *ip_address;
    char *timestamp;
    char *message;
} Alert;

Alert *alerts[MAX_ALERTS];
int num_alerts = 0;

void add_alert(char *ip_address, char *timestamp, char *message) {
    if (num_alerts >= MAX_ALERTS) {
        printf("Maximum number of alerts reached\n");
        return;
    }
    Alert *new_alert = malloc(sizeof(Alert));
    new_alert->ip_address = strdup(ip_address);
    new_alert->timestamp = strdup(timestamp);
    new_alert->message = strdup(message);
    alerts[num_alerts++] = new_alert;
}

void print_alerts() {
    for (int i = 0; i < num_alerts; i++) {
        printf("Alert %d\n", i + 1);
        printf("IP Address: %s\n", alerts[i]->ip_address);
        printf("Timestamp: %s\n", alerts[i]->timestamp);
        printf("Message: %s\n", alerts[i]->message);
        printf("\n");
    }
}

int main() {
    add_alert("192.168.1.1", "2021-08-01 10:10:10", "Suspicious activity detected");
    add_alert("192.168.2.1", "2021-08-02 11:11:11", "Attempted SQL injection detected");
    add_alert("192.168.3.1", "2021-08-03 12:12:12", "Multiple failed login attempts detected");
    
    print_alerts();
    
    return 0;
}