//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP 20
#define MAX_LOGS 100

typedef struct log_file {
    char source[MAX_IP];
    char destination[MAX_IP];
    char message[100];
} log_file;

void log_message(log_file logs[], int *num_logs, char src[], char dst[], char msg[]) {
    if (*num_logs == MAX_LOGS) {
        printf("Log file max capacity reached. Entry not logged.\n");
        return;
    }
    strcpy(logs[*num_logs].source, src);
    strcpy(logs[*num_logs].destination, dst);
    strcpy(logs[*num_logs].message, msg);
    (*num_logs)++;
}

void check_for_intrusion(log_file logs[], int *num_logs, char ip[]) {
    int i, num_failed_login_attempts = 0;
    for (i=0; i<*num_logs; i++) {
        if (strcmp(ip, logs[i].source) == 0 && strstr(logs[i].message, "Login attempt failed") != NULL) {
            num_failed_login_attempts++;
        }
    }
    if (num_failed_login_attempts >= 3) {
        printf("INTRUSION ALERT: %s has had 3 or more failed login attempts.\n", ip);
        log_message(logs, num_logs, "INTRUSION DETECTION SYSTEM", ip, "INTRUSION ALERT");
    }
}

int main() {
    log_file logs[MAX_LOGS];
    int num_logs = 0;

    char ip1[MAX_IP] = "192.168.0.100";
    char ip2[MAX_IP] = "192.168.0.200";
    char ip3[MAX_IP] = "192.168.0.150";

    char log_msg1[100] = "Login attempt failed for user 'admin'";
    char log_msg2[100] = "Login attempt failed for user 'root'";
    char log_msg3[100] = "Login attempt failed for user 'admin'";
    char log_msg4[100] = "Login attempt failed for user 'admin'";
    char log_msg5[100] = "Login attempt failed for user 'root'";
    char log_msg6[100] = "Login attempt failed for user 'admin'";

    log_message(logs, &num_logs, ip1, ip2, log_msg1);
    log_message(logs, &num_logs, ip2, ip3, log_msg2);
    log_message(logs, &num_logs, ip3, ip1, log_msg3);
    log_message(logs, &num_logs, ip1, ip3, log_msg4);
    log_message(logs, &num_logs, ip2, ip1, log_msg5);
    log_message(logs, &num_logs, ip3, ip2, log_msg6);

    check_for_intrusion(logs, &num_logs, ip1);
    check_for_intrusion(logs, &num_logs, ip2);
    check_for_intrusion(logs, &num_logs, ip3);

    return 0;
}