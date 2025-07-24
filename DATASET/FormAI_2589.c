//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASS_LENGTH 20

void generateSecurePassword(char* password, int length); 

int main() {
    char password[MAX_PASS_LENGTH];
    srand(time(NULL));
    generateSecurePassword(password, MAX_PASS_LENGTH);
    printf("Your secure password is: %s", password);
    return 0;
}

void generateSecurePassword(char* password, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}[];':\"<>,.?/";
    int charset_length = sizeof(charset) - 1;
    int i;
    for (i = 0; i < length-1; i++) {
        password[i] = charset[rand() % charset_length];
    }
    password[length-1] = '\0';
}