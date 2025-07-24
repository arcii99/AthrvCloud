//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: recursive
#include <stdio.h>
#include <ctype.h>
#include <time.h>

#define TEXT_SIZE 50
#define MAX_WRONG 7

char text[TEXT_SIZE+1] = "recursive function example";
char input[TEXT_SIZE+1];
int mistakes = 0;

void type_letters(int idx);

int main() {
    int idx = 0;
    printf("Type the text:\n");
    type_letters(idx);
    printf("\n\nYou made %d mistakes!", mistakes);
    return 0;
}

void type_letters(int idx) {
    char c;
    if (text[idx] != '\0') {
        c = getchar();
        if (isalpha(c) && c == tolower(text[idx])) {
            printf("%c", c);
            fflush(stdout);
            type_letters(idx+1);
        } else {
            mistakes++;
            if (mistakes <= MAX_WRONG) {
                printf("\n\nWrong letter! Try again:\n");
                fflush(stdout);
                type_letters(idx);
            } else {
                printf("\n\nToo many mistakes!\n");
            }
        }
    }
}