//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LENGTH 1000

int main(void) {
    char input[MAX_STR_LENGTH];
    char suspicious[MAX_STR_LENGTH];
    int suspicious_flag = 1;

    printf("Enter your input: ");
    fgets(input, MAX_STR_LENGTH, stdin);

    for (int i = 0; i < MAX_STR_LENGTH; i++) {
        if (input[i] == 'h' && input[i+1] == 'a' && input[i+2] == 'c' && input[i+3] == 'k') {
            suspicious_flag = 0;
            printf("Intrusion detected!\n");
            break;
        }
    }

    if (suspicious_flag) {
        printf("No intrusion detected.\n");
    }

    return 0;
}