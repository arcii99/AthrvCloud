//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main(int argc, char const *argv[]) {
    char input[MAX_SIZE];
    char *suspicious_code[] = { "rm -rf", "passwd", "mkdir", "chmod", "chown", "su", "sudo" };
    char *reason[] = { "removing files from system", "changing password", "creating directory", "modifying file permissions", "changing ownership", "switching user", "elevating privileges" };

    printf("Please enter a command to check for intrusions:\n");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // remove trailing newline character

    int detected = 0;
    for (int i = 0; i < sizeof(suspicious_code) / sizeof(suspicious_code[0]); i++) {
        if (strstr(input, suspicious_code[i])) {
            printf("Intrusion detected! Reason: %s\n", reason[i]);
            detected = 1;
            break;
        }
    }

    if (!detected) {
        printf("Command is safe.\n");
    }

    return 0;
}