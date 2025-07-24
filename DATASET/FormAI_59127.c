//FormAI DATASET v1.0 Category: Text processing ; Style: high level of detail
#include <stdio.h>

//function to count the number of vowels in a string
int countVowels(char *str){
    int count = 0;
    while (*str){
        switch(*(str++)){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                ++count;
        }
    }
    return count;
}

//function to count the number of consonants in a string
int countConsonants(char *str){
    int count = 0;
    while (*str){
        if ((*str <='Z' && *str >='A') || (*str <='z' && *str >='a')) {
            switch(*(str++)){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    break;
                default:
                    ++count;
            }
        }
        else{
            ++str;
        }
    }
    return count;
}

//function to count the number of words in a string
int countWords(char *str){
    int count = 1;
    while (*str){
        if (*str == ' ' || *str == '\t' || *str == '\n'){
            ++count;
            while (*str == ' ' || *str == '\t' || *str == '\n'){
                ++str;
            }
        }
        else{
            ++str;
        }
    }
    return count;
}

int main(){
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    printf("Number of vowels: %d\n", countVowels(str));
    printf("Number of consonants: %d\n", countConsonants(str));
    printf("Number of words: %d\n", countWords(str));
    return 0;
}