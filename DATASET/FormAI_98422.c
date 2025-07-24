//FormAI DATASET v1.0 Category: Word Count Tool ; Style: invasive
#include <stdio.h>
#include <string.h>

int countWords(char*);

int main() {
    char str[1000];
    printf("Enter a sentence: ");
    fgets(str, 1000, stdin);
    printf("Word count: %d\n", countWords(str)); 
    return 0;
}

int countWords(char* str) {
    int len = strlen(str), count = 0, i;
    if (len > 0)
        count++;
    for (i = 0; i < len; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            count++;
    }
    return count;
}