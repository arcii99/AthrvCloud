//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// function to display the character frequency
void displayCharacterFrequency(int count[]){
    printf("Character Frequency:\n\n");
    printf("CHARACTER\t FREQUENCY\n");

    for (int i = 0; i <= 255; i++) {
        if (count[i] != 0) {
            printf("%c\t\t %d\n", i, count[i]);
        }
    }
}

// function to count the character frequency
void countCharacterFrequency(char str[], int count[]) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        count[str[i]]++;
    }

    displayCharacterFrequency(count);
}

int main() {
    char str[100];
    int count[256] = {0};

    printf("Welcome to the C Word Frequency Counter!\n\n");
    printf("Please enter a string: ");
    fgets(str, 100, stdin);

    countCharacterFrequency(str, count);

    return 0;
}