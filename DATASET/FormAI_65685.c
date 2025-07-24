//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Ken Thompson
#include <stdio.h>

int main() {
    // Define an array of cat words
    char catWords[10][10] = {"meow", "purr", "hiss", "scratches", "mouse", "lick", 
                             "furry", "whiskers", "tuna", "nap"};

    // Define an array of English words
    char engWords[10][20] = {"Hello", "Goodbye", "Yes", "No", "Please", "Thank You",
                             "Friend", "Sleep", "Food", "Toy"};

    // Get user input of a cat word
    char userInput[10];
    printf("Enter a word in cat language: ");
    scanf("%s", &userInput);

    // Translate the cat word into English
    int i, transIndex = -1;
    for(i = 0; i < 10; i++) {
        if(strcmp(userInput, catWords[i]) == 0) {
            transIndex = i;
            break;
        }
    }
    if(transIndex == -1) {
        printf("Sorry, I do not understand that word in cat language\n");
    } else {
        printf("In English, \"%s\" means \"%s\"\n", userInput, engWords[transIndex]);
    }

    return 0;
}