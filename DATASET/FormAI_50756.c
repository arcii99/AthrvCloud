//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

void check_for_intrusion(char* input) {
    int i, j;
    char* keywords[] = {"hack", "exploit", "rootkit", "trojan", "malware", "backdoor"};

    for (i = 0; i < 6; i++) {
        if (strstr(input, keywords[i])) {
            printf("INTRUSION DETECTED! Possible attack using %s\n", keywords[i]);

            // Log intrusion
            FILE* log_file = fopen("intrusion.log", "a");
            if (log_file == NULL) {
                printf("ERROR: Unable to access intrusion log file\n");
                return;
            }

            fprintf(log_file, "INTRUSION DETECTED! Possible attack using %s\n", keywords[i]);
            fclose(log_file);

            return;
        }
    }

    printf("No intrusion detected\n");
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Enter input for intrusion check: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    check_for_intrusion(input);

    return 0;
}