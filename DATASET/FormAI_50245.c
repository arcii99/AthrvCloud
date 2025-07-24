//FormAI DATASET v1.0 Category: Browser Plugin ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// This plugin converts all text into emojis

void convertToEmoji(char* text) {
    printf("Converting to emojis... 🌟🦄🎉\n");

    // Replace all occurrences of words with emojis
    char* happyEmojis[] = {"😄", "🤩", "😍", "😜"};
    char* sadEmojis[] = {"😔", "😢", "😭", "😞"};
    char* loveEmojis[] = {"❤️", "💕", "😘", "💘"};

    while (*text) {
        if (*text == ' ') {
            printf(" ");
        } else {
            // Pick a random emoji from the array
            if (*text == 'h') {
                printf("%s", happyEmojis[rand() % 4]);
            } else if (*text == 's') {
                printf("%s", sadEmojis[rand() % 4]);
            } else if (*text == 'l') {
                printf("%s", loveEmojis[rand() % 4]);
            } else {
                printf("%c", *text);
            }
        }
        text++;
    }

    printf("\n");
}

int main() {
    char inputText[100];

    printf("Enter some text: ");
    scanf("%[^\n]", inputText);

    convertToEmoji(inputText);

    return 0;
}