//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: brave
#include <stdio.h>

#define MAX_ATTEMPTS 3

int main() {
    int attempts = 0;
    int count = 0;
    char buffer[10];

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter your password: ");

        fgets(buffer, sizeof(buffer), stdin);

        if (strcmp(buffer, "password123\n") == 0) {
            printf("Access granted!\n");
            break;
        } else {
            printf("Access denied!\n");
            attempts++;
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("INTRUSION DETECTED!!!\n");
        // code to alert security or take other action
    }

    return 0;
}