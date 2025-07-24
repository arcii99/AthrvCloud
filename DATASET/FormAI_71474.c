//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINES 1000

int main(){
    char input[MAX_LINES][MAX_WORD_LENGTH];
    int count[MAX_LINES], total = 0;

    printf("Hark! What words dost thou wish to countetheth?\n");

    // Get input from user, line by line
    int numLines = 0;
    while(numLines < MAX_LINES && fgets(input[numLines], MAX_WORD_LENGTH, stdin)){
        numLines++;
    }

    // Count occurrences of each word
    for(int i = 0; i < numLines; i++){
        char *word = strtok(input[i], " ,.!?\"\'\n");
        while(word){
            // Convert word to lowercase
            for(int j = 0; j < strlen(word); j++){
                word[j] = tolower(word[j]);
            }

            // Check if word is already in list
            int index = -1;
            for(int j = 0; j < total; j++){
                if(strcmp(input[j], word) == 0){
                    index = j;
                    break;
                }
            }

            // If word not in list, add it
            if(index == -1){
                strcpy(input[total], word);
                count[total] = 1;
                total++;
            }
            // If word already in list, increment count
            else{
                count[index]++;
            }

            word = strtok(NULL, " ,.!?\"\'\n");
        }
    }

    // Print results
    printf("Hark! Here be the frequency of each word:\n");
    for(int i = 0; i < total; i++){
        printf("%s: %d\n", input[i], count[i]);
    }

    return 0;
}