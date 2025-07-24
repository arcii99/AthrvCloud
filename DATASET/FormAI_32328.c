//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTACKS 1000
#define MAX_IP_LENGTH 15

struct attack {
    char ip[MAX_IP_LENGTH];
    char type[20];
};

typedef struct attack Attack;

Attack attacks[MAX_ATTACKS];
int num_attacks = 0;

void detect_intrusion(char ip[], char type[]) {
    int i;
    for (i = 0; i < num_attacks; i++) {
        if (strcmp(attacks[i].ip, ip) == 0 && strcmp(attacks[i].type, type) == 0) {
            printf("Intrusion detected: %s attacked with %s\n", ip, type);
            exit(0);
        }
    }
    strcpy(attacks[num_attacks].ip, ip);
    strcpy(attacks[num_attacks].type, type);
    num_attacks++;
}

int main() {
    char ip[MAX_IP_LENGTH];
    char type[20];

    while (1) {
        printf("Enter IP address: ");
        scanf("%s", ip);
        printf("Enter attack type: ");
        scanf("%s", type);

        detect_intrusion(ip, type);
    }

    return 0;
}