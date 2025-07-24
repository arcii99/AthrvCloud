//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 3
#define MAX_PASSWORD_LENGTH 15

char* generate_random_password(int length) {
    char random_password[MAX_PASSWORD_LENGTH];
    char source_characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`!@#$%^&*()_-+={}[]|\\;:'\",.<>/?";
    int len_source_characters = strlen(source_characters);

    srand((unsigned int)time(NULL));
    for (int i = 0; i < length; i++) {
        random_password[i] = source_characters[rand() % len_source_characters];
    }
    random_password[length] = '\0';

    return random_password;
}

int main() {
    char* password = generate_random_password(10);
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        printf("Please enter the password %d: ", attempts+1);
        char entered_password[MAX_PASSWORD_LENGTH];
        scanf("%s", entered_password);

        if (strcmp(password, entered_password) == 0) {
            printf("Access granted!\n");
            break;
        } else {
            printf("Access denied! Incorrect password.\n");
            attempts++;
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Intrusion detected! Initiating system shutdown.\n");
        system("shutdown /s /t 0");
    }

    return 0;
}