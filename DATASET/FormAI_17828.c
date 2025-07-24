//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100
#define MAX_IP_ADDRESSES 10
#define MAX_ATTEMPTS_ALLOWED 3

struct ip_attempt {
    char ip_address[MAX_BUFFER_SIZE];
    int attempts;
};

int num_ip_attempts = 0;
struct ip_attempt ip_attempts[MAX_IP_ADDRESSES];

void add_ip_attempt(char *ip_address) {
    int i;
    for(i=0; i<num_ip_attempts; i++) {
        if(strcmp(ip_attempts[i].ip_address, ip_address) == 0) {
            // IP address found; increment attempts
            ip_attempts[i].attempts++;
            printf("Intrusion attempt detected from IP address: %s (Attempt %d/%d)\n", ip_address, ip_attempts[i].attempts, MAX_ATTEMPTS_ALLOWED);
            
            if(ip_attempts[i].attempts >= MAX_ATTEMPTS_ALLOWED) {
                printf("Maximum attempts reached. Block IP address: %s\n", ip_address);
                // Add code to block IP address here
            }
            
            return;
        }
    }
    
    // IP address not found; add to array
    if(num_ip_attempts >= MAX_IP_ADDRESSES) {
        printf("Error: Maximum IP addresses reached. Cannot add new IP address.\n");
        return;
    }
    
    struct ip_attempt attempt = {0};
    strncpy(attempt.ip_address, ip_address, MAX_BUFFER_SIZE-1);
    attempt.attempts = 1;
    ip_attempts[num_ip_attempts] = attempt;
    num_ip_attempts++;
    
    printf("Intrusion attempt detected from IP address: %s (Attempt 1/%d)\n", ip_address, MAX_ATTEMPTS_ALLOWED);
}

int main() {
    char ip1[MAX_BUFFER_SIZE] = "192.168.0.1";
    char ip2[MAX_BUFFER_SIZE] = "192.168.0.2";
    char ip3[MAX_BUFFER_SIZE] = "192.168.0.3";
    
    add_ip_attempt(ip1); // Attempt 1
    add_ip_attempt(ip2); // Attempt 1
    add_ip_attempt(ip1); // Attempt 2
    add_ip_attempt(ip2); // Attempt 2
    add_ip_attempt(ip1); // Attempt 3; max attempts reached; block IP address
    add_ip_attempt(ip1); // Should not be added; maximum attempts reached
    
    return 0;
}