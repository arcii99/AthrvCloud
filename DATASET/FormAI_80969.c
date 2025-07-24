//FormAI DATASET v1.0 Category: Word Count Tool ; Style: systematic
#include<stdio.h>
#include<string.h>

void countWords(char str[]) {
    int count = 0, i;
    char last_char = ' ';

    for(i=0; i<strlen(str); i++) {
        if(str[i] != ' ' && (last_char == ' ' || last_char == '\t' || last_char == '\n')) {
            count++;
        }
        last_char = str[i];
    }

    printf("The total number of words in the given string is: %d\n", count);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    countWords(str);

    return 0;
}