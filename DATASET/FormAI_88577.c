//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to the Alien Language Translator v1.0!\n");
    printf("Initializing language database...\n");
    
    //define the alien language characters and their english translations
    char alienLang[6] = {'#', '%', '!', '*', '$'};
    char englishLang[6][10] = {"Greetings", "Goodbye", "Peace", "Love", "Thank You"};
    
    printf("Language database initialized!\n");
    
    char input[100];
    int transCounter = 0;
    
    while(strcmp(input, "exit") != 0) {
        printf("Enter an alien language word: \n");
        scanf("%s", input);
        
        if(strcmp(input, "exit") == 0) {
            printf("Exiting program...\n");
            return 0;
        }
        
        //translating alien language to english
        int foundIndex = -1;
        for(int i = 0; i < strlen(input); i++) {
            for(int j = 0; j < 5; j++) {
                if(input[i] == alienLang[j]) {
                    foundIndex = j;
                }
            }
            
            if(foundIndex != -1) {
                printf("%s ", englishLang[foundIndex]);
                transCounter++;
            }
            
            foundIndex = -1;
        }
        printf("\n");
    }
    
    printf("Total alien words translated: %d\n", transCounter);
    printf("Thanks for translating with us! Come again soon!\n");
    
    return 0;
}