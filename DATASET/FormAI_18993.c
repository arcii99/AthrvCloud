//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random character
char randomChar() {
    int choice = rand() % 3;
    if (choice == 0) {
        return 'A' + rand() % 26;
    } else if (choice == 1) {
        return 'a' + rand() % 26;
    } else {
        return '0' + rand() % 10;
    }
}

// Function to generate secure password
void generatePassword() {
    int length, i;
    printf("Enter password length: ");
    scanf("%d", &length);

    printf("Generated password: ");
    srand(time(NULL));
    for (i = 0; i < length; i++) {
        printf("%c", randomChar());
    }
    printf("\n");
}

int main() {
    generatePassword();
    return 0;
}