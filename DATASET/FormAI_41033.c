//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: artistic
#include <stdio.h>

// Define a function to count the number of "meows" in a string
int count_meows(char* string) {
    int count = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == 'm' && string[i+1] == 'e' && string[i+2] == 'o' && string[i+3] == 'w') {
            count++;
        }
    }
    return count;
}

// Define the main function
int main() {

    // Greet the user
    printf("Welcome to the C Cat Language Translator!\n");

    // Prompt the user for input
    printf("Please enter a phrase in English: ");
    char english[100];
    fgets(english, 100, stdin);

    // Convert the input to lowercase
    for (int i = 0; english[i] != '\0'; i++) {
        if (english[i] >= 'A' && english[i] <= 'Z') {
            english[i] = english[i] + ('a' - 'A');
        }
    }

    // Count the number of "meows" in the input
    int num_meows = count_meows(english);

    // Print the translation
    if (num_meows == 0) {
        printf("Sorry, we could not translate that phrase.\n");
    } else {
        printf("In C Cat Language, \"%s\" becomes:\n", english);
        for (int i = 0; i < num_meows; i++) {
            printf("meow ");
        }
        printf("\n");
    }

    // Say goodbye
    printf("Thank you for using the C Cat Language Translator!\n");

    return 0;
}