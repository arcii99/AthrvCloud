//FormAI DATASET v1.0 Category: Word Count Tool ; Style: irregular
#include <stdio.h>
#include <string.h>
#define MAX_CHARACTERS 10000

int main() {
    char text[MAX_CHARACTERS];
    int words = 0, characters = 0, sentences = 0;

    printf("Enter the text you want to analyze:\n");
    fgets(text, MAX_CHARACTERS, stdin);

    int length = strlen(text);

    //Checking for each character in the entered text
    for(int i = 0; i < length; i++) {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;//when the statement ends
            continue;
        } else if(text[i] == ' ') {
            words++; //when one word ends
            continue;
        }
        characters++;//when no statement ends
    }
    //Changing words+1 as there would be one word after the last space in the text
    printf("The text entered by you have:\n");
    printf("%d words\n", words+1);
    printf("%d characters\n", characters);
    printf("%d sentences\n", sentences);

    float index = 0.0588 * ((float)characters / (float)(words + 1)) * 100 - 0.296 * ((float)sentences / (float)(words + 1)) * 100 - 15.8;
    int grade = (int)index;

    if(grade >= 1 && grade <= 16) {
        printf("The grade level of the text is: %d\n", grade);
    } else if(grade > 16) {
        printf("The text is rated as Grade 16+\n");
    } else {
        printf("The text is rated as Grade 0-1\n");
    }

    return 0;
}