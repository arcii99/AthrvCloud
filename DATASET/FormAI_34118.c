//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* generatePassword(int length);

int main() {
    printf("Welcome to Secure Password Generator\n");
    printf("Enter the length of password to generate: ");
    int length;
    scanf("%d", &length);

    char* password = generatePassword(length);
    printf("Your generated password: %s\n", password);
    free(password);

    return 0;
}

char* generatePassword(int length) {
    srand(time(NULL));
    char* password = (char*) malloc((length + 1) * sizeof(char));
    if (!password) {
        printf("Error while allocating memory for password\n");
        exit(1);
    }

    int i;
    for (i = 0; i < length; i++) {
        int charType = rand() % 3; // generate 0 for digits, 1 for uppercase letters, 2 for lowercase letters

        if (charType == 0) {
            password[i] = rand() % 10 + '0'; // generate digit
        } else if (charType == 1) {
            password[i] = rand() % 26 + 'A'; // generate uppercase letter
        } else {
            password[i] = rand() % 26 + 'a'; // generate lowercase letter
        }
    }
    password[i] = '\0'; // terminating null character

    return password;
}