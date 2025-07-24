//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: excited
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100]; // we'll store the user input here
    printf("Welcome to the Cat Translator!\n");
    printf("Please enter a sentence in English:\n");
    fgets(input, 100, stdin); // read user input into buffer

    // remove newline character if it exists
    int len = strlen(input);
    if (len > 0 && input[len-1] == '\n')
        input[len-1] = '\0';

    printf("Translating to Cat language...\n");

    // here's where the magic happens
    // we'll loop through each character in the sentence and replace it with "meow"
    char cat[1000] = ""; // we'll store the cat translation here
    int cat_index = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            strcat(cat, " "); // add space
        } else {
            strcat(cat, "meow"); // add "meow"
        }
        cat_index += 4; // increment cat_index by 4 to account for "meow"
    }

    printf("Your sentence in Cat language:\n%s\n", cat);

    return 0;
}