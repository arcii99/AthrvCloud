//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Define variables for input and output
    char english[100];
    char cat[100];

    // Define arrays for translation
    char englishArr[26][10] = {"hello", "how", "are", "you", "doing", "today", "i", "am", "doing", "well", "thank", "you", "very", "much", "what", "is", "your", "name", "my", "name", "is", "cat", "food", "water", "play", "with", "me"};
    char catArr[26][10] = {"meow", "meowmeow", "meowmeowmeow", "meowmeow", "meowmeowmeowmeow", "meowmeowmeowmeowmeow", "me", "meow", "meowmeowmeow", "meowmeow", "meowmeowmeowmeowmeow", "meowmeow", "meowmeowmeowmeowmeowmeow", "meowmeowmeowmeowmeowmeow", "meowmeowmeowmeowmeowmeowmeow", "meowmeowmeow", "meowmeowme", "meowmeow", "me", "meow", "meowmeowmeowmeow", "meow", "meowmeowmeowmeowmeow", "meowmeowmeowmeowmeowmeowmeow", "meowmeowmeowmeowmeowmeowmeowmeow", "meowmeowmeowmeow"};

    printf("Enter a sentence in English: ");
    scanf("%[^\n]s", english);

    // Convert English sentence to lowercase
    for (int i = 0; english[i] != '\0'; i++) {
        if (english[i] >= 'A' && english[i] <= 'Z') {
            english[i] = english[i] + 32;
        }
    }

    // Parse English sentence and translate to Cat language
    int j = 0;
    for (int i = 0; english[i] != '\0'; i++) {
        if (english[i] == ' ') {
            cat[j++] = ' ';
            continue;
        }

        int index = english[i] - 'a';
        if (index < 0 || index > 25) {
            printf("Invalid input. Please enter only letters a-z.\n");
            return -1;
        }

        // Look up word in array and append to cat sentence
        int k = 0;
        while (catArr[index][k] != '\0') {
            cat[j++] = catArr[index][k++];
        }
    }

    // Output Cat language translation
    printf("The sentence translated to Cat language is:\n%s\n", cat);
    return 0;
}