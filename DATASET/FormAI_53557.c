//FormAI DATASET v1.0 Category: Word Count Tool ; Style: relaxed
#include <stdio.h>
#include <string.h>

int countWords(char str[]);

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);
    printf("Total number of words in the string = %d\n", countWords(str));
    return 0;
}

int countWords(char str[]) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            count++;
        }
    }
    return count + 1;
}