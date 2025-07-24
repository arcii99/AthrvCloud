//FormAI DATASET v1.0 Category: Word Count Tool ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WORD_LEN 100

void countWords(char str[], int count[]) {
    int i = 0, j = 0, index = 0;
    int len = strlen(str);
    
    while(i < len) {
        while(str[i] == ' ' && i < len) {
            i++;
        }
        if(i == len) {
            break;
        }
        j = i;
        while(str[j] != ' ' && j < len) {
            j++;
        }
        int wordLength = j - i;
        char word[wordLength + 1];
        strncpy(word, str + i, wordLength);
        word[wordLength] = '\0';
        
        if(wordLength <= MAX_WORD_LEN) {
            count[wordLength]++;
        }
        i = j;
    }
}

int main() {
    char inputStr[1000];
    printf("Enter the string: \n");
    fgets(inputStr, 1000, stdin);
    
    int wordCount[MAX_WORD_LEN + 1] = { 0 };
    countWords(inputStr, wordCount);
    
    printf("Word count in the string: \n");
    for(int i = 0; i <= MAX_WORD_LEN; i++) {
        if(wordCount[i] != 0) {
            printf("%d letter words : %d\n", i, wordCount[i]);
        }
    }
    
    return 0;
}