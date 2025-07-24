//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
/*
 * Secure Password Generator in C
 * Linus Torvalds style
 * Minimum length: 16 characters
 * Maximum length: 32 characters
 * Includes uppercase, lowercase, digits, and special characters
 * Usage: ./password_generator
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 16
#define MAX_LENGTH 32

char generate_char() {
    char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=";
    int len = sizeof(chars) - 1;
    return chars[rand() % len];
}

int main() {
    srand(time(NULL));
    int length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
    char password[length + 1];
    for(int i = 0; i < length; i++) {
        password[i] = generate_char();
    }
    password[length] = '\0';
    printf("Generated password: %s\n", password);
    return 0;
}