//FormAI DATASET v1.0 Category: String manipulation ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main() {
    char name[100];

    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\nYour name in uppercase letters: ");

    for(int i = 0; i < strlen(name); i++) {
        printf("%c", toupper(name[i]));
    }

    printf("\nYour name in lowercase letters: ");

    for(int j = 0; j < strlen(name); j++) {
        printf("%c", tolower(name[j]));
    }

    printf("\nYour name with every second letter capitalized: ");

    for(int k = 0; k < strlen(name); k++) {
        if(k % 2 == 0) {
            printf("%c", toupper(name[k]));
        } else {
            printf("%c", name[k]);
        }
    }

    printf("\n");

    return 0;
}