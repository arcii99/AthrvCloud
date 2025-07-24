//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePassword(int passwordLength) {
    srand(time(NULL));
    int i, random;
    char generatedPassword[passwordLength+1];

    for(i=0; i<passwordLength; i++) {
        random = rand() % 3;

        switch(random) {
            case 0:
                generatedPassword[i] = rand() % 26 + 'a';
                break;

            case 1:
                generatedPassword[i] = rand() % 26 + 'A';
                break;

            case 2:
                generatedPassword[i] = rand() % 10 + '0';
                break;
        }
    }

    generatedPassword[passwordLength] = '\0';

    printf("Generated Password is: %s", generatedPassword);
}

int main() {
    int passwordLength;

    printf("Enter Password Length: ");
    scanf("%d", &passwordLength);

    generatePassword(passwordLength);

    return 0;
}