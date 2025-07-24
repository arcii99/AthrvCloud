//FormAI DATASET v1.0 Category: Text processing ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
    char myString[100];
    int i, j, len;
    printf("Hey there! I'm a text processing program and I'm here to make your life funny. Give me a string to process:\n");
    fgets(myString, sizeof(myString), stdin);
    len = strlen(myString);
    printf("Nice choice! Let's begin our fun journey:\n\n");

    // Reversing the string
    printf("Reversing the string:\n");
    for(i = len-1; i >= 0; i--) {
        printf("%c", myString[i]);
    }
    printf("\n\n");

    // Counting the vowels
    printf("Counting the vowels:\n");
    int count = 0;
    for(i = 0; i < len; i++) {
        if(myString[i] == 'a' || myString[i] == 'e' || myString[i] == 'i' || myString[i] == 'o' || myString[i] == 'u') {
            count++;
        }
    }
    printf("There are %d vowels in the string.\n\n", count);

    // Capitalizing every even letter
    printf("Capitalizing every even letter:\n");
    for(i = 0; i < len; i++) {
        if(i % 2 == 0) {
            printf("%c", toupper(myString[i]));
        } else {
            printf("%c", myString[i]);
        }
    }
    printf("\n\n");

    // Replacing vowels with *
    printf("Replacing vowels with *:\n");
    for(i = 0; i < len; i++) {
        if(myString[i] == 'a' || myString[i] == 'e' || myString[i] == 'i' || myString[i] == 'o' || myString[i] == 'u' || myString[i] == 'A' || myString[i] == 'E' || myString[i] == 'I' || myString[i] == 'O' || myString[i] == 'U') {
            printf("*");
        } else {
            printf("%c", myString[i]);
        }
    }
    printf("\n\n");

    // Replacing every space with a random character
    printf("Replacing every space with a random character:\n");
    char randomChar;
    srand(time(NULL)); // Initializing random seed
    for(i = 0; i < len; i++) {
        if(myString[i] == ' ') {
            randomChar = (char)(rand() % 26 + 97); // Generating a random lowercase character
            printf("%c", randomChar);
        } else {
            printf("%c", myString[i]);
        }
    }
    printf("\n\n");

    // Separating every word with a hyphen
    printf("Separating every word with a hyphen:\n");
    for(i = 0; i < len; i++) {
        if(myString[i] == ' ') {
            printf("-");
        } else {
            printf("%c", myString[i]);
        }
    }
    printf("\n\n");

    // Reversing every word
    printf("Reversing every word:\n");
    for(i = len-1; i >= 0; i--) {
        if(myString[i] == ' ' || i == 0) {
            if(i == 0) {
                j = i;
            } else {
                j = i + 1;
            }
            while(myString[j] != ' ' && myString[j] != '\0') {
                printf("%c", myString[j]);
                j++;
            }
            printf(" ");
        }
    }
    printf("\n\n");

    printf("That was fun! Hope you enjoyed it as much as I did :)\n");

    return 0;
}