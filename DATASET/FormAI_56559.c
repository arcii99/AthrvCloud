//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ATTEMPTS 3

int main() {
    char passwords[] = {'p', 'a', 's', 's', 'w', 'o', 'r', 'd'}; // Pre-defined password
    char input[10]; // Input buffer
    int attempts = 0; // Number of login attempts

    printf("Welcome to the Intrusion Detection System!\n");
    printf("Please enter the password to proceed: ");

    while (attempts < MAX_ATTEMPTS) {
        scanf("%s", input);

        if (strcmp(input, passwords) == 0) {
            printf("Access Granted!\n");
            break;
        } else {
            printf("Invalid password, please try again. (%d attempts remaining)\n", MAX_ATTEMPTS - attempts - 1);
            attempts++;
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Maximum attempts exceeded. Intrusion detected.\n");
        // Send alarm signal
    }

    return 0;
}