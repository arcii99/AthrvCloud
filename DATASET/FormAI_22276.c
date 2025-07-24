//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 16

char generate_random_char(int min, int max) {
    return (char)(rand() % (max - min + 1) + min);
}

int main() {
    srand(time(NULL));
    int i;
    char password[PASSWORD_LENGTH+1];
    char random_char;

    printf("Generating secure password...\n");
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        random_char = generate_random_char(33, 126);
        while (random_char == '"' || random_char == '\'' || random_char == '\\')
            random_char = generate_random_char(33, 126);
        password[i] = random_char;
    }
    password[PASSWORD_LENGTH] = '\0';

    printf("Secure password generated:\n%s\n", password);

    return 0;
}