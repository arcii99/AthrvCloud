//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Alien language words with their corresponding translation in English
    char alienWords[][50] = {"Daqherucc", "Hello", "Rapheash", "Goodbye", "Floghoth", "Thank you", "Snurroth", "Please", "Hodel", "Friend"};
    char engWords[][50] = {"Daqherucc", "Hello", "Rapheash", "Goodbye", "Floghoth", "Thank you", "Snurroth", "Please", "Hodel", "Friend"};

    int i, j, flag;
    char alienInput[50];
    char engOutput[50];

    // Get the Alien word from the user
    printf("Enter the Alien word to translate: ");
    fgets(alienInput, 50, stdin);

    // Remove newline character from user input
    alienInput[strcspn(alienInput, "\n")] = 0;

    // Convert the Alien word to lowercase
    for(i = 0; alienInput[i]; i++){
        alienInput[i] = tolower(alienInput[i]); 
    }

    // Check if the input is a valid Alien word
    flag = 0;
    for(i = 0; i < 10; i++){
        if(strcmp(alienWords[i], alienInput) == 0){
            // If it is, get the English translation from the array
            for(j = 0; j < strlen(engWords[i]); j++){
                engOutput[j] = engWords[i][j];
            }
            engOutput[j] = '\0';
            flag = 1;
            break;
        }
    }

    // If the input is not a valid Alien word, output an error message
    if(flag == 0){
        printf("Error: Not a valid Alien word.\n");
        exit(1);
    }

    // Print the English translation of the Alien word
    printf("English translation: %s\n", engOutput);

    return 0;
}