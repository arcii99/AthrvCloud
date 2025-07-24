//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ATTEMPTS 5
#define MIN_SECONDS 2

int main(void) {
    int attempts = 0;
    int seconds = 0;
    char buffer[256];

    while (1) {
        printf("Please enter your password: ");
        fflush(stdout);
        fgets(buffer, sizeof(buffer), stdin);

        if (strcmp(buffer, "mypass123\n") == 0) {
            printf("Welcome to the system!\n");
            break;
        } else {
            attempts++;
            if (attempts == MAX_ATTEMPTS) {
                printf("INTRUSION DETECTED! LOCKING SYSTEM!\n");
                while (1) {
                    sleep(MIN_SECONDS);
                    seconds++;
                    printf("Your computer is locked for %d seconds... Muahahaha!\n", seconds);
                }
            } else {
                printf("Incorrect password. You have %d attempts left.\n", MAX_ATTEMPTS - attempts);
            }
        }
    }

    return EXIT_SUCCESS;
}