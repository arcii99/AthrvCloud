//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 1000
#define EVENT_LEN 50

void log_event(char *event_type, char *event_msg);
int detect_intrusion();

char event_list[MAX_EVENTS][EVENT_LEN];
int event_count = 0;

int main() {
    log_event("login", "john_doe logged in");
    log_event("access", "john_doe accessed sensitive data");
    log_event("logout", "john_doe logged out");
    log_event("login", "hacker1 attempted to log in as admin");
    log_event("access", "hacker1 accessed sensitive data");
    log_event("logout", "hacker1 logged out");
    
    if (detect_intrusion()) {
        printf("An intrusion has been detected!\n");
    } else {
        printf("No intrusions detected.\n");
    }
    
    return 0;
}

void log_event(char *event_type, char *event_msg) {
    char event[EVENT_LEN];
    sprintf(event, "%s: %s", event_type, event_msg);
    
    if (event_count < MAX_EVENTS) {
        strcpy(event_list[event_count], event);
        event_count++;
    } else {
        printf("Error: event log full.\n");
    }
}

int detect_intrusion() {
    int login_count = 0;
    int access_count = 0;
    int logout_count = 0;
    int hack_attempt = 0;
    int data_accessed = 0;
    
    for (int i = 0; i < event_count; i++) {
        if (strstr(event_list[i], "login")) {
            login_count++;
        }
        if (strstr(event_list[i], "access")) {
            access_count++;
            if (strstr(event_list[i], "sensitive data")) {
                data_accessed++;
            }
        }
        if (strstr(event_list[i], "logout")) {
            logout_count++;
        }
        if (strstr(event_list[i], "login") && strstr(event_list[i], "admin")) {
            hack_attempt++;
        }
        if (strstr(event_list[i], "access") && strstr(event_list[i], "hacker")) {
            data_accessed++;
        }
    }
    
    if (login_count > 1 || access_count > 10 || hack_attempt > 0 || data_accessed > 3) {
        return 1;
    } else {
        return 0;
    }
}