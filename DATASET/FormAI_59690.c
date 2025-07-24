//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: surrealist
#include <stdio.h> 

int main(){
    // Welcome message to the user
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Please enter a phrase using the C Alien language: ");
    char phrase[100];
    scanf("%s", phrase);

    // Alien dictionary
    char alienChar[26] = {'c', 'a', 'b', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char englishChar[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    // Loop through the phrase character by character
    int i = 0;
    while(phrase[i] != '\0'){
        // Translate each character using the dictionary
        int j = 0;
        while(j < 26){
            if (phrase[i] == alienChar[j]){
                phrase[i] = englishChar[j];
                break;
            }
            j++;
        }
        i++;
    }

    // Print the translated phrase
    printf("\nTranslation: %s\n", phrase);

    return 0;
}