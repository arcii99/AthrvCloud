//FormAI DATASET v1.0 Category: Spam Detection System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countOccurrences(char* text, char* pattern){
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int count = 0;
    
    for (int i = 0; i <= textLength - patternLength; i++){
        int j;
        for (j = 0; j < patternLength; j++){
            if (text[i + j] != pattern[j]){
                break;
            }
        }
        if (j == patternLength){
            count++;
        }
    }
    return count;
}

int main(){
    char spamText[1000];
    char spamWords[10][100] = {"free", "offer", "discount", "buy", "click", "now", "limited", "act", "save", "today"}; // array of spam trigger words
    int spamCount = 0; // counter for the number of spam trigger words found
    
    printf("*** Welcome to the Spam Detection System ***\n");
    printf("Please enter the text you wish to check for spam:\n");
    fgets(spamText, 1000, stdin); // get input from user
    
    for(int i = 0; i < 10; i++){ // loop through the array of spam trigger words
        int count = countOccurrences(spamText, spamWords[i]); // check for occurrences of the word in the input text
        if(count > 0){ // if the word is found, increment the spam counter
            printf("Spam trigger word '%s' found %d times!\n", spamWords[i], count);
            spamCount += count;
        }
    }
    
    if(spamCount == 0){ // if no spam trigger words were found, the input text is clean
        printf("No spam trigger words found! Your text is clean.\n");
    }else{ // otherwise, the input text contains spam
        printf("WARNING! %d spam trigger words found in your text. It may be spam!\n", spamCount);
    }
    
    return 0;
}