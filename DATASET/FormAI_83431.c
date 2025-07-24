//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: systematic
#include <stdio.h>
#include <string.h>

int main(void) {
    char input[50];
    printf("Input a phrase in the C Alien language: ");
    scanf("%[^\n]", input);
    
    int i;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == 'C') {
            printf("%d", 1);
        } else if (input[i] == ' ') {
            printf(" ");
        } else if (input[i] == '.') {
            printf("%d", 0);
        } else {
            printf("%c", input[i]);
        }
    }
    printf("\n");
    return 0;
}