//FormAI DATASET v1.0 Category: String manipulation ; Style: Cryptic
#include<stdio.h>
#include<string.h>

// function prototypes
void reverse_string(char* str);
void to_uppercase(char* str);
void replace_vowels(char* str);

int main() {
    // initialize string variable
    char cryptic_string[50] = "sEcrEt_mEssAge_herE";
    
    // reverse string
    reverse_string(cryptic_string);
    
    // convert to uppercase
    to_uppercase(cryptic_string);
    
    // replace vowels with '+'
    replace_vowels(cryptic_string);
    
    // print final string
    printf("Output: %s", cryptic_string);
    
    return 0;
}

// function to reverse the string
void reverse_string(char* str) {
    int i, j;
    char temp;
    
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// function to convert the string to uppercase
void to_uppercase(char* str) {
    int i;
    
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

// function to replace the vowels with '+'
void replace_vowels(char* str) {
    int i;
    
    for (i = 0; str[i] != '\0'; i++) {
        switch(str[i]) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                str[i] = '+';
                break;
            default:
                break;
        }
    }
}