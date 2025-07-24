//FormAI DATASET v1.0 Category: Text processing ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to check if the given text has a keyword
int hasKeyword(char* text, char* keyword) {
    char* tmp = strstr(text, keyword);
    if(tmp == NULL) return 0;
    if(tmp != text && isalpha(*(tmp-1))) return 0;
    if(!isalpha(*(tmp+strlen(keyword)))) return 0;
    return 1;
}

// Function to replace the given keyword in the text with a new word
void replaceKeyword(char* text, char* keyword, char* newWord) {
    char* tmp = strstr(text, keyword);
    int keywordLen = strlen(keyword);
    int newWordLen = strlen(newWord);
    while(tmp != NULL) {
        strncpy(tmp, newWord, newWordLen);
        memmove(tmp+newWordLen, tmp+keywordLen, strlen(tmp+keywordLen)+1);
        tmp = strstr(tmp+newWordLen, keyword);
    }
}

int main() {
    char text[1000];
    char keyword[100];
    char newWord[100];

    printf("Enter the text:");
    fgets(text, 1000, stdin);
    printf("Enter the keyword:");
    scanf("%s", keyword);
    printf("Enter the new word to replace the keyword:");
    scanf("%s", newWord);

    if(hasKeyword(text, keyword)) {
        replaceKeyword(text, keyword, newWord);
        printf("The new text is:%s\n", text);
    }
    else {
        printf("The given text does not contain the keyword.\n");
    }

    return 0;
}