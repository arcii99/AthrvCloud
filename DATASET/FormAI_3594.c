//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constant values
#define MAX_STRING_LEN 50
#define MAX_INTRUSION_ATTEMPTS 5

// define structure for intrusion attempts
typedef struct {
    char ip_address[MAX_STRING_LEN];
    char username[MAX_STRING_LEN];
    int num_attempts;
} IntrusionAttempt;

// function to check if an ip_address exists in the array of intrusion attempts
int find_ip_address(char ip_address[], IntrusionAttempt attempts[], int num_attempts) {
    for (int i = 0; i < num_attempts; i++) {
        if (strcmp(ip_address, attempts[i].ip_address) == 0) {
            return i;
        }
    }
    return -1;
}

// function to add a new intrusion attempt to the array
void add_intrusion_attempt(char ip_address[], char username[], IntrusionAttempt attempts[], int* num_attempts) {
    int index = find_ip_address(ip_address, attempts, *num_attempts);
    if (index >= 0) {
        attempts[index].num_attempts++;
        printf("Intrusion attempt detected from %s with username %s. %s now has %d attempts.\n", ip_address, username, ip_address, attempts[index].num_attempts);
    } else {
        IntrusionAttempt new_attempt;
        strcpy(new_attempt.ip_address, ip_address);
        strcpy(new_attempt.username, username);
        new_attempt.num_attempts = 1;
        attempts[*num_attempts] = new_attempt;
        *num_attempts += 1;
        printf("New intrusion attempt detected from %s with username %s.\n", ip_address, username);
    }
}

// main function
int main() {
    IntrusionAttempt attempts[MAX_INTRUSION_ATTEMPTS];
    int num_attempts = 0;
    char ip_address[MAX_STRING_LEN];
    char username[MAX_STRING_LEN];
    
    // simulate intrusion attempts
    add_intrusion_attempt("192.168.0.1", "hacker", attempts, &num_attempts);
    add_intrusion_attempt("192.168.0.2", "hacker", attempts, &num_attempts);
    add_intrusion_attempt("192.168.0.2", "hacker", attempts, &num_attempts);
    add_intrusion_attempt("192.168.0.1", "hacker", attempts, &num_attempts);
    add_intrusion_attempt("192.168.0.3", "hacker", attempts, &num_attempts);
    add_intrusion_attempt("192.168.0.2", "hacker", attempts, &num_attempts);
    add_intrusion_attempt("192.168.0.4", "hacker", attempts, &num_attempts);
    
    // check if any ip_addresses have reached the maximum number of intrusion attempts
    for (int i = 0; i < num_attempts; i++) {
        if (attempts[i].num_attempts >= 3) {
            printf("WARNING: %s has had %d attempts from username %s.\n", attempts[i].ip_address, attempts[i].num_attempts, attempts[i].username);
        }
    }
    
    return 0;
}