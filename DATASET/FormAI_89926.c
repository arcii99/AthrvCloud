//FormAI DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void countChar(char* str, int* charCount);
void replaceChar(char* str, char oldChar, char newChar);
void reverseWords(char* str);

int main() {
    char myString[] = "This is a unique C string manipulation example program.";
    int charCount[26] = {0};
    
    printf("Original String: %s\n", myString);
    
    countChar(myString, charCount);
    printf("\nCharacter Count:\n");
    for(int i=0; i<26; i++) {
        printf("%c: %d\n", 97+i, charCount[i]);
    }
    
    printf("\nReplacing all 'i' with 'X':\n");
    replaceChar(myString, 'i', 'X');
    printf("%s\n", myString);
    
    printf("\nReversing each word in the string:\n");
    reverseWords(myString);
    printf("%s\n", myString);
    
    return 0;
}

// count the number of occurences of each character
void countChar(char* str, int* charCount) {
    for(int i=0; i<strlen(str); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            charCount[str[i]-'a']++;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            charCount[str[i]-'A']++;
        }
    }
}

// replace all instances of oldChar with newChar
void replaceChar(char* str, char oldChar, char newChar) {
    for(int i=0; i<strlen(str); i++) {
        if(str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

// reverse each word in the string
void reverseWords(char* str) {
    int start = 0;
    for(int i=0; i<strlen(str); i++) {
        if(str[i] == ' ') {
            int end = i-1;
            while(start < end) {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }
            start = i+1;
        }
    }
    int end = strlen(str)-1;
    while(start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}