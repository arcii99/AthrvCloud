//FormAI DATASET v1.0 Category: Log analysis ; Style: Cryptic
#include <stdio.h>

int main() {
    char log[] = "DK5$+!w##$123$m,~2Gia";

    printf("Analyzing log...\n\n");

    for (int i = 0; i < strlen(log); i++) {
        if (log[i] >= 'a' && log[i] <= 'z') {
            printf("Encountered lowercase letter: %c\n", log[i]);
        } else if (log[i] >= 'A' && log[i] <= 'Z') {
            printf("Encountered uppercase letter: %c\n", log[i]);
        } else if (log[i] >= '0' && log[i] <= '9') {
            printf("Encountered number: %c\n", log[i]);
        } else if (log[i] == '$' || log[i] == ',' || log[i] == '+' || log[i] == '~') {
            printf("Encountered special character: %c\n", log[i]);
        } else {
            printf("Encountered unknown character: %c\n", log[i]);
        }
    }

    printf("\nAnalysis complete!\n");

    return 0;
}