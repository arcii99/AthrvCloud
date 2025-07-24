//FormAI DATASET v1.0 Category: Spell checking ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[500];
    char dictionary[][20] = {
        "apple",
        "banana",
        "cherry",
        "dragonfruit",
        "eggplant",
        "fig",
        "grape",
        "honeydew",
        "kiwi",
        "lemon",
        "mango",
        "nectarine",
        "orange",
        "pineapple",
        "quince",
        "raspberry",
        "strawberry",
        "tangerine",
        "watermelon",
        "xylocarp",
        "yellowwatermelon",
        "zucchini"
    };
    int misspelled = 0;

    printf("Enter some text to spell check: ");
    fgets(text, 500, stdin);

    char *word = strtok(text, " \n");

    while (word != NULL) {
        // Convert word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Remove punctuation if necessary
        if (word[strlen(word) - 1] == '.' || word[strlen(word) - 1] == ',' || word[strlen(word) - 1] == ';') {
            word[strlen(word) - 1] = '\0';
        }

        // Check if word is in dictionary
        int found = 0;
        for (int i = 0; i < 22; i++) {
            if (strcmp(word, dictionary[i]) == 0) {
                found = 1;
                break;
            }
        }

        // If word is not found in dictionary, mark as misspelled
        if (!found) {
            printf("%s is misspelled\n", word);
            misspelled++;
        }

        word = strtok(NULL, " \n");
    }

    printf("Spell check complete. %d misspelled words found\n", misspelled);

    return 0;
}