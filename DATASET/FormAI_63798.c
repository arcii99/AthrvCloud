//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>
#include <string.h>

//function to check if the given character is a vowel in the alien language
int isVowel(char c) {
    if(c == 'x' || c == 'y' || c == 'z') //in the alien language, these letters are considered as vowels
        return 1;
    return 0;
}

//function to convert the given string from alien language to english
char* alienToEnglish(char* str) {
    int len = strlen(str);
    char res[len+1];
    int i, j=0;
    for(i=0; i<len; i++) {
        if(isVowel(str[i])) //if the current character is a vowel, skip it
            continue;
        else { //if the current character is a consonant, add it to the result string
            res[j] = str[i];
            j++;
        }
    }
    res[j] = '\0';
    return res;
}

int main() {
    char str[101];
    printf("Enter a string in the alien language: ");
    scanf("%s", str);
    char* res = alienToEnglish(str); //convert the string to english
    printf("Translated string: %s\n", res);
    return 0;
}