//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* generate_password(int length) {
    char* password = malloc(sizeof(char) * (length + 1));

    // 35 possible characters
    char characters[] = "abcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[]\\|/><,.?";
    int num_characters = strlen(characters);

    // Set random seed
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        password[i] = characters[rand() % num_characters];
    }

    password[length] = '\0';

    return password;
}

int main() {
    // Get length of password from user
    int length;
    printf("Enter length of password: ");
    scanf("%d", &length);

    char* password = generate_password(length);
    printf("Your secure password: %s\n", password);

    free(password);

    return 0;
}