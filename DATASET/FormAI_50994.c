//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 20
#define MAX_ATTACK_TYPE_LEN 30

struct Log {
    char ip_address[MAX_IP_LEN];
    char attack_type[MAX_ATTACK_TYPE_LEN];
    int count;
};

void print_log(struct Log log) {
    printf("%s - %s - %d\n", log.ip_address, log.attack_type, log.count);
}

void print_logs(struct Log logs[], int size) {
    for (int i = 0; i < size; i++) {
        print_log(logs[i]);
    }
}

void update_log(struct Log *log, char *attack_type) {
    log -> count++;
    strcpy(log -> attack_type, attack_type);
}

int main() {
    int n;
    printf("Enter the number of logs: ");
    scanf("%d", &n);

    struct Log logs[n];
    int index = 0;

    for (int i = 0; i < n; i++) {
        char ip[MAX_IP_LEN];
        char attack_type[MAX_ATTACK_TYPE_LEN];

        printf("Enter the ip address: ");
        scanf("%s", ip);

        printf("Enter the attack type: ");
        scanf("%s", attack_type);

        int found = 0;
        for (int j = 0; j < index; j++) {
            if (strcmp(logs[j].ip_address, ip) == 0) {
                update_log(&logs[j], attack_type);
                found = 1;
                break;
            }
        }

        if (!found) {
            struct Log new_log;
            strcpy(new_log.ip_address, ip);
            strcpy(new_log.attack_type, attack_type);
            new_log.count = 1;

            logs[index] = new_log;
            index++;
        }
    }

    printf("\nLogs:\n");
    print_logs(logs, index);

    printf("\nDetecting Intrusions...\n");

    for (int i = 0; i < index; i++) {
        if (strcmp(logs[i].attack_type, "DDoS") == 0 && logs[i].count > 100) {
            printf("%s is under DDoS attack!\n", logs[i].ip_address);
        } else if (strcmp(logs[i].attack_type, "Brute Force") == 0 && logs[i].count > 50) {
            printf("%s is under Brute Force attack!\n", logs[i].ip_address);
        }
    }

    return 0;
}