//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isSuspicious(char* packet) {
    // This function checks whether a given packet is suspicious or not
    char* keywords[] = {"password", "admin", "root", "backdoor", "virus"};
    int n = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < n; i++) {
        if (strstr(packet, keywords[i]) != NULL) {
            return true;
        }
    }
    return false;
}

int main() {
    // This program simulates an Intrusion Detection System for a network
    int numPackets = 10;
    char* packets[] = {
        "GET /index.html HTTP/1.1\r\nHost: example.com\r\n\r\n",
        "POST /login.php HTTP/1.1\r\nHost: example.com\r\n\r\n",
        "DROP TABLE users;\r\n",
        "You have been hacked!\r\n",
        "SELECT * FROM passwords;\r\n",
        "admin:password123\r\n",
        "rm -rf /tmp/*\r\n",
        "cd /home/user/backdoor/\r\n",
        "hello world\r\n",
        "virus installed successfully!\r\n"
    };
    printf("Checking %d packets...\n", numPackets);
    for (int i = 0; i < numPackets; i++) {
        if (isSuspicious(packets[i])) {
            printf("ALERT: Suspicious packet detected: %s", packets[i]);
            // Code to send an alert message to a security admin can be added here
        }
    }
    printf("All packets checked. No suspicious activity detected.\n");
    return 0;
}