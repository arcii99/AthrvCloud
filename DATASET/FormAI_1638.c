//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>

#define MAX_INCIDENTS 10

typedef struct {
    char *ip_address;
    int count;
} incident_t;

bool is_ip_whitelisted(char *ip_address);
void process_incident(char *ip_address, incident_t incidents[], int *num_incidents);
void print_incidents(incident_t incidents[], int num_incidents);

int main(void) {
    // Initialize incidents array
    incident_t incidents[MAX_INCIDENTS] = {0};
    int num_incidents = 0;

    // Loop to simulate incoming traffic
    char *traffic[] = {"1.2.3.4", "8.8.8.8", "1.2.3.4", "192.168.0.1", "9.9.9.9", "1.2.3.4", "8.8.8.8", "192.168.0.1", "9.9.9.9", "1.2.3.4", "8.8.8.8", "192.168.0.1", "9.9.9.9", "1.2.3.4", "8.8.8.8", "192.168.0.1", "9.9.9.9", "1.2.3.4", "8.8.8.8", "192.168.0.1", "9.9.9.9"};

    for (int i = 0; i < sizeof(traffic) / sizeof(*traffic); i++) {
        char *ip_address = traffic[i];

        if (!is_ip_whitelisted(ip_address)) {
            process_incident(ip_address, incidents, &num_incidents);
        }
    }

    print_incidents(incidents, num_incidents);

    return 0;
}

bool is_ip_whitelisted(char *ip_address) {
    // Check if the IP address is in the whitelist
    char *whitelist[] = {"192.168.0.1", "127.0.0.1"};

    for (int i = 0; i < sizeof(whitelist) / sizeof(*whitelist); i++) {
        if (strcmp(ip_address, whitelist[i]) == 0) {
            return true;
        }
    }

    return false;
}

void process_incident(char *ip_address, incident_t incidents[], int *num_incidents) {
    // Check if the incident has already occurred
    for (int i = 0; i < *num_incidents; i++) {
        if (strcmp(ip_address, incidents[i].ip_address) == 0) {
            incidents[i].count++;
            return;
        }
    }

    // Add the incident to the incidents array
    if (*num_incidents < MAX_INCIDENTS) {
        incidents[*num_incidents].ip_address = ip_address;
        incidents[*num_incidents].count = 1;
        (*num_incidents)++;
    }
}

void print_incidents(incident_t incidents[], int num_incidents) {
    printf("=== INCIDENTS ===\n");

    for (int i = 0; i < num_incidents; i++) {
        printf("%s: %d\n", incidents[i].ip_address, incidents[i].count);
    }
}