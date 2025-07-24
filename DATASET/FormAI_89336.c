//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: complete
#include <stdio.h>
#include <string.h>

void logEvent(char *event) {
    FILE *logFile;

    logFile = fopen("intrusion_log.txt", "a");
    if (logFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(logFile, "%s\n", event);
    fclose(logFile);
}

int main() {
    char buffer[256];
    int isAttack = 0;

    printf("Starting intrusion detection system...\n");

    while (1) {
        printf("Enter input: ");
        fgets(buffer, 256, stdin);

        if (strstr(buffer, "rm -rf")) {
            isAttack = 1;
        } else if (strstr(buffer, "sudo")) {
            isAttack = 1;
        } else if (strstr(buffer, "/bin/bash")) {
            isAttack = 1;
        } else if (strstr(buffer, "ssh")) {
            isAttack = 1;
        }

        if (isAttack) {
            printf("Intrusion detected!\n");
            logEvent(buffer);
            isAttack = 0;
        }
    }

    return 0;
}