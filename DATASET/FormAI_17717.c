//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char buffer[1000];
    printf("\n\nWelcome to the Medieval Intrusion Detection System!\n\n");
    printf("Type in a phrase and our system will check it for any harmful words or phrases from the medieval times.\n\n");
    printf("Enter your phrase: ");
    fgets(buffer, 1000, stdin); // accepting user input

    char keywords[10][15] = { "witch", "sorcery", "dark magic", "dragon", "troll", "goblin", "foul play", "betrayal", "heretic", "treason" }; // list of medieval keywords

    int flag, i, j;
    for(i=0; i<strlen(buffer); i++) {
        if(isalpha(buffer[i])) { // checking only alphabets in user input
            flag=0;
            for(j=0; j<10; j++) {
                int k = 0;
                while(keywords[j][k] != '\0' && buffer[i+k] != '\0' && keywords[j][k] == buffer[i+k]) { // comparing each word from the list with the user input
                    k++;
                }
                if(keywords[j][k] == '\0') { // if the keyword matches
                    printf("\nDetected a harmful word/phrase: %s\n", keywords[j]);
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) break; // break out of loop after detecting first harmful word/phrase
        }
    }

    if(flag == 0) { // if no harmful words/phrases
        printf("\nNo harmful phrases detected.\n");
    }

    return 0;
}