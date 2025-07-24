//FormAI DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include<stdio.h>
#include<string.h>

int countWords(char *str) {
    int count = 0;
    int flag = 0;
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            flag = 0;    // Set the flag if space, new line or tab found
        }
        else if(flag == 0) {
            count++;    // Increment the count if a new word found
            flag = 1;    // Set the flag to 1 for the next character
        }
    }
    return count;
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("Number of words in the string: %d", countWords(str));
    return 0;
}