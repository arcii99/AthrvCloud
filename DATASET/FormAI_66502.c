//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Function to calculate password strength
int calculate_password_strength(char *password) {
    int length = strlen(password);
    int score = 0;
    int has_lower = 0, has_upper = 0, has_digit = 0, has_special = 0;

    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lower = 1;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            has_upper = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }

    if (length >= 8) {
        score += 10;
        if (length >= 12) {
            score += 10;
        }
    }

    if (has_lower && has_upper) {
        score += 10;
    }

    if (has_digit && has_special) {
        score += 10;
    }

    return score;
}

// Thread function to check password strength
void *check_password_strength(void *arg) {
    char *password = (char *)arg;

    int strength = calculate_password_strength(password);

    printf("Password: %s\n", password);
    printf("Strength: %d\n", strength);

    pthread_exit(NULL);
}

int main() {
    int num_threads = 3;
    pthread_t threads[num_threads];
    char *passwords[] = {"abc123", "Password123", "p@ssw0rd"};

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, check_password_strength, (void *)passwords[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}