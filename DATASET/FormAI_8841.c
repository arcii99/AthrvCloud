//FormAI DATASET v1.0 Category: Word Count Tool ; Style: authentic
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Enter your text: \n");
    fgets(input, 1000, stdin);
    int len = strlen(input);
    int words = 1, characters = 0, lines = 1;
    for(int i = 0; i < len; i++) {
        if(input[i] == '\n') {
            lines++;
        }
        if(input[i] == ' ' || input[i] == '\n') {
            words++;
        }
        characters++;
    }
    printf("\nWord count : %d\n", words);
    printf("Character count : %d\n", characters - 1);
    printf("Line count : %d\n", lines);
    return 0;
}