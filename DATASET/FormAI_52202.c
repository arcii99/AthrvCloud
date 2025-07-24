//FormAI DATASET v1.0 Category: Word Count Tool ; Style: introspective
#include <stdio.h> 

int main() { 
    char ch;
    int count = 0, word = 0, line = 0;

    printf("Enter your text:\n");

    while ((ch=getchar()) != EOF) {
        if (ch == '\n') {
            line++;
            word++;
        }
        else if (ch == ' ' || ch == '\t') {
            word++;
        }
        else {
            count++;
        }
    }

    printf("The total number of characters in the text is: %d\n", count);
    printf("The total number of words in the text is: %d\n", word);
    printf("The total number of lines in the text is: %d\n", line);

    return 0; 
}