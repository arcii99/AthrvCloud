//FormAI DATASET v1.0 Category: Spell checking ; Style: funny
#include<stdio.h>
#include<string.h>
#include<ctype.h>

//Function to check if a character is a letter or not
int isLetter(char ch){
    ch = tolower(ch);
    if(ch >= 'a' && ch <= 'z') {
        return 1;
    }
    return 0;
}

int main(){
    char text[1000]; //Text to be checked
    char dictionary[1000][100]; //Dictionary for spell checking
    int dictIndex = 0; //Current index in dictionary
    int wordIndex = 0; //Current index in word
    int errorCount = 0; //Number of spelling errors
    int i, j, k; //Loop variables

    //Welcome message
    printf("Welcome to the spell checker program!\n");
    printf("Please enter some text to be spell checked:\n");

    //Read in the text
    fgets(text, 1000, stdin);

    //Add some words to the dictionary
    strcpy(dictionary[dictIndex++], "hello");
    strcpy(dictionary[dictIndex++], "world");
    strcpy(dictionary[dictIndex++], "computer");
    strcpy(dictionary[dictIndex++], "science");
    strcpy(dictionary[dictIndex++], "funny");

    //Loop through the text and check each word
    for(i=0; i<strlen(text); i++){
        //Found a letter
        if(isLetter(text[i])){
            //Add it to the current word
            wordIndex = 0;
            char word[100] = {0};
            while(isLetter(text[i]) && i<strlen(text)){
                word[wordIndex++] = tolower(text[i++]);
            }
            //Check if the word is in the dictionary
            int found = 0;
            for(j=0; j<dictIndex; j++){
                if(strcmp(word, dictionary[j]) == 0){
                    found = 1;
                    break;
                }
            }
            //If not, it's a spelling mistake!
            if(!found){
                errorCount++;
                printf("Error: %s is not in the dictionary!\n", word);
            }
        }
    }

    //Print out the results
    if(errorCount == 0){
        printf("No spelling errors found! Good job!\n");
    } else {
        printf("Found %d spelling error(s). Better luck next time!\n", errorCount);
    }

    return 0;
}