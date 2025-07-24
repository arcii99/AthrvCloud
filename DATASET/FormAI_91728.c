//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_IP_ADDRESSES 100

struct log_entry {
    char ip_address[16];
    time_t timestamp;
};

struct ip_address {
    char address[16];
    int count;
};

struct log_entry logs[MAX_LOG_ENTRIES];
int log_count = 0;

struct ip_address ip_addresses[MAX_IP_ADDRESSES];
int ip_count = 0;

void add_log_entry(char *ip_address) {
    if (log_count == MAX_LOG_ENTRIES) {
        printf("Error: log entry limit has been reached\n");
        return;
    }

    strcpy(logs[log_count].ip_address, ip_address);
    logs[log_count].timestamp = time(NULL);
    printf("Added log entry for %s at %s\n", ip_address, ctime(&logs[log_count].timestamp));
    log_count++;
}

void add_ip_address(char *ip_address) {
    int i;

    for (i = 0; i < ip_count; i++) {
        if (strcmp(ip_addresses[i].address, ip_address) == 0) {
            ip_addresses[i].count++;
            return;
        }
    }

    if (ip_count == MAX_IP_ADDRESSES) {
        printf("Error: IP address limit has been reached\n");
        return;
    }

    strcpy(ip_addresses[ip_count].address, ip_address);
    ip_addresses[ip_count].count = 1;
    printf("Added IP address %s\n", ip_address);
    ip_count++;
}

int check_intrusion(char *ip_address) {
    int i;

    for (i = 0; i < ip_count; i++) {
        if (strcmp(ip_addresses[i].address, ip_address) == 0) {
            if (ip_addresses[i].count >= 5) {
                return 1;
            }
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    // simulate adding log entries for five different IP addresses
    add_log_entry("192.168.1.1");
    add_log_entry("192.168.1.2");
    add_log_entry("192.168.1.1");
    add_log_entry("192.168.1.3");
    add_log_entry("192.168.1.1");

    // add the IP addresses to our list and monitor for intrusions
    if (check_intrusion("192.168.1.1")) {
        printf("Intrusion detected for IP address %s\n", "192.168.1.1");
    } else {
        add_ip_address("192.168.1.1");
    }

    if (check_intrusion("192.168.1.2")) {
        printf("Intrusion detected for IP address %s\n", "192.168.1.2");
    } else {
        add_ip_address("192.168.1.2");
    }

    if (check_intrusion("192.168.1.3")) {
        printf("Intrusion detected for IP address %s\n", "192.168.1.3");
    } else {
        add_ip_address("192.168.1.3");
    }

    if (check_intrusion("192.168.1.4")) {
        printf("Intrusion detected for IP address %s\n", "192.168.1.4");
    } else {
        add_ip_address("192.168.1.4");
    }

    if (check_intrusion("192.168.1.1")) {
        printf("Intrusion detected for IP address %s\n", "192.168.1.1");
    } else {
        add_ip_address("192.168.1.1");
    }

    return 0;
}