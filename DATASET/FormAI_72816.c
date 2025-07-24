//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: optimized
#include <stdio.h>
#include <stdbool.h>

#define MAX_LOGIN_ATTEMPTS 3

bool is_login_attempt_successful() {
    // Code to check if login attempt is successful
    return true;
}

void report_intrusion_attempt() {
    // Code to report intrusion attempt
    printf("INTRUSION DETECTED: Multiple failed login attempts\n");
}

int main() {
    int login_attempts = 0;
    bool is_intrusion_detected = false;

    while (login_attempts < MAX_LOGIN_ATTEMPTS) {
        if (is_login_attempt_successful()) {
            printf("Login successful\n");
            break;
        } else {
            login_attempts++;
            printf("Login failed. Attempt %d out of %d\n", login_attempts, MAX_LOGIN_ATTEMPTS);
            if (login_attempts == MAX_LOGIN_ATTEMPTS) {
                is_intrusion_detected = true;
            }
        }
    }

    if (is_intrusion_detected) {
        report_intrusion_attempt();
    }

    return 0;
}