//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool detect_intrusion(int num_attempts, int num_failures) {
    /* The game is afoot! */
    int threshold = num_attempts / 3;
    if (num_failures > threshold) {
        printf("Elementary, my dear Watson! Intrusion detected!\n");
        return true;
    }
    printf("It seems that our network is secure for now.\n");
    return false;
}

int main() {
    int num_attempts = 0;
    int num_failures = 0;
    bool done = false;
    printf("Welcome to our Intrusion Detection System.\n");
    while (!done) {
        printf("Number of attempts so far: %d\n", num_attempts);
        printf("Number of failures so far: %d\n", num_failures);
        printf("Please enter the result of the latest attempt (1 for success, 0 for failure):\n");
        int result;
        scanf("%d", &result);
        if (result == 1) {
            printf("Great work, my dear fellow!\n");
        } else {
            printf("Alas, another failure.\n");
            num_failures++;
        }
        num_attempts++;
        if (num_attempts >= 5) {
            done = detect_intrusion(num_attempts, num_failures);
            num_attempts = 0;
            num_failures = 0;
        }
    }
    printf("The game is over. Until next time, my friend.\n");
    return 0;
}