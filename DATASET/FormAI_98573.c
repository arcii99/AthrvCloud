//FormAI DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    printf("Enter some text: ");
    fgets(text, 100, stdin);
    printf("\nWow, you really typed that whole thing out?\n\n");

    printf("The length of your text is %d\n", strlen(text));

    printf("\nThat's a lot of characters to process.. but I'm up for the challenge!\n");

    int vowels = 0, consonants = 0;
    for(int i = 0; i < strlen(text); i++) {
        if(text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U') {
            vowels++;
        }
        else if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            consonants++;
        }
    }

    printf("\nI found %d vowels and %d consonants in your text.\n", vowels, consonants);

    printf("\nBut wait! I want to show off my text manipulation skills!\n");

    printf("Your text in uppercase letters is: ");
    for(int i = 0; i < strlen(text); i++) {
        printf("%c", toupper(text[i]));
    }

    printf("\n");

    printf("Your text in lowercase letters is: ");
    for(int i = 0; i < strlen(text); i++) {
        printf("%c", tolower(text[i]));
    }

    printf("\n");

    printf("And finally, your text in reverse order is: ");
    for(int i = strlen(text) - 1; i >= 0; i--) {
        printf("%c", text[i]);
    }

    printf("\n\nPhew, that was a lot of work. But I did it with ease! Thanks for the challenge!\n");

    return 0;
}