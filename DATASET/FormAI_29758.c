//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char generateRandomChar() {
    int rand_int = rand() % 62;
    if (rand_int < 26) // uppercase letters
        return rand_int + 'A';
    else if (rand_int < 52) // lowercase letters
        return rand_int - 26 + 'a';
    else // digits
        return rand_int - 52 + '0';
}

void generatePassword(int length) {
    char password[length];
    srand(time(NULL)); // seed the random number generator
    for (int i = 0; i < length; i++) {
        password[i] = generateRandomChar();
        printf("%c", password[i]);
    }
}

int main() {
    printf("Enter the length of the password you want to generate: ");
    int length;
    scanf("%d", &length);
    generatePassword(length);
    return 0;
}